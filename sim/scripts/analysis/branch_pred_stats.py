import argparse
import os
import sys
import time
from pathlib import Path


def create_directory_if_not_exists(path):
    Path(path).mkdir(parents=True, exist_ok=True)


def process_pc_sequence(input_file, output_file, debug=False):
    print("========== [1/2] : FILTERING BRANCH SEQUENCE ==========")
    try:
        with open(input_file, 'r') as f:
            lines = f.readlines()
        
        if not lines:
            if debug:
                print(f"Warning: {input_file} is empty")
            return
        
        # Keep the first line (header) and process the rest
        header = lines[0].strip()
        data_lines = lines[1:]
        
        # Filter lines that contain branch information
        filtered_lines = [header + '\n']
        
        for line in data_lines:
            line = line.strip()
            if not line:
                continue
                
            # Split by space and check if it has a "B" element at index 1
            parts = line.split()
            if len(parts) >= 2 and parts[1] == 'B':
                filtered_lines.append(line + '\n')
        
        # Create output directory if it doesn't exist
        output_dir = os.path.dirname(output_file)
        create_directory_if_not_exists(output_dir)
        
        # Write filtered data to output file
        with open(output_file, 'w') as f:
            f.writelines(filtered_lines)
        
        print(f"read {input_file} successfully")
        print(f"generated {output_file} successfully")
        
        if debug:
            print(f"  - Input lines: {len(lines)}")
            print(f"  - Output lines: {len(filtered_lines)}")
            print(f"  - Branch entries: {len(filtered_lines) - 1}")
        
        print("========== BRANCH SEQUENCE FILTERED =================\n")
        
    except FileNotFoundError:
        print(f"Error: Input file {input_file} not found")
        sys.exit(1)
    except Exception as e:
        print(f"Error processing {input_file}: {e}")
        sys.exit(1)


def validate_scheme(scheme):
    """Validate branch prediction scheme."""
    valid_schemes = ["addr_index", "ghr", "lhr", "gselect", "gshare"]
    if scheme not in valid_schemes:
        print(f"Error: Unrecognized branch prediction scheme '{scheme}'")
        print(f"Valid schemes: {', '.join(valid_schemes)}")
        sys.exit(1)
    return scheme

def validate_counter_policy(policy):
    """Validate counter policy."""
    valid_policies = ["saturating"]
    if policy not in valid_policies:
        print(f"Error: Unrecognized counter policy '{policy}'")
        print(f"Valid policies: {', '.join(valid_policies)}")
        sys.exit(1)
    return policy

class SaturatingCounter:
    """Saturating counter for branch prediction."""
    
    def __init__(self, n_cnt_bits=2):
        self.n_cnt_bits = n_cnt_bits
        self.max_value = (2 ** n_cnt_bits) - 1
        self.min_value = 0
        self.counters = {}  # Dictionary to store counters by index
    
    def get_counter(self, index):
        """Get counter value for given index, initialize if not exists."""
        if index not in self.counters:
            self.counters[index] = 0  # Initialize to 0
        return self.counters[index]
    
    def update_counter(self, index, outcome):
        """Update counter based on branch outcome (1=taken, 0=not taken)."""
        current_value = self.get_counter(index)
        
        if outcome == 1:  # Branch taken - increment
            new_value = min(current_value + 1, self.max_value)
        else:  # Branch not taken - decrement
            new_value = max(current_value - 1, self.min_value)
        
        self.counters[index] = new_value
        return new_value

class GlobalHistoryRegister:
    """Global History Register for branch prediction."""
    
    def __init__(self, size=0):
        self.size = size
        self.value = 0
    
    def update(self, outcome):
        """Update GHR by adding outcome as LSB and left-shifting existing content."""
        # Left shift existing content and add outcome as LSB
        self.value = ((self.value << 1) | outcome) & ((1 << self.size) - 1) if self.size > 0 else 0
    
    def get_value(self):
        """Get current GHR value."""
        return self.value

class LocalHistoryRegister:
    """Local History Register dictionary for branch prediction."""
    
    def __init__(self, size=8):
        self.size = size
        self.registers = {}  # Dictionary keyed by pc_bits
    
    def get_register(self, pc_bits):
        """Get LHR value for given PC bits, initialize if not exists."""
        if pc_bits not in self.registers:
            self.registers[pc_bits] = 0  # Initialize to 0
        return self.registers[pc_bits]
    
    def update_register(self, pc_bits, outcome):
        """Update LHR for given PC bits by adding outcome as LSB and left-shifting."""
        current_value = self.get_register(pc_bits)
        # Left shift existing content and add outcome as LSB
        new_value = ((current_value << 1) | outcome) & ((1 << self.size) - 1)
        self.registers[pc_bits] = new_value
        return new_value

class BranchPredictor:
    """Branch Predictor class that manages all prediction components."""
    
    def __init__(self, scheme, counter_policy, n_cnt_bits, addr_bit_range, ghr_size=8, lhr_size=8):
        self.scheme = scheme
        self.counter_policy = counter_policy
        self.addr_bit_range = addr_bit_range
        self.ghr_size = ghr_size
        self.lhr_size = lhr_size
        self.n_cnt_bits = n_cnt_bits
        
        # Initialize components
        self.saturating_counter = SaturatingCounter(n_cnt_bits)
        self.ghr = GlobalHistoryRegister(ghr_size)
        self.lhr = LocalHistoryRegister(lhr_size)
        
        # Statistics tracking
        self.total_branches = 0
        self.total_predicts = 0
        self.unique_indices = set()
        self.index_hits = 0
        self.replacements = 0
        self.index_stats = {}  # Per-index statistics: {index: {'predicts': 0, 'mispredicts': 0, 'total': 0}}
        self.iteration_stats = []  # Track stats for each iteration
    
    def extract_addr_bits(self, pc_address):
        """Extract specific bit range from PC address."""
        pc_int = int(pc_address, 16)
        high_bit, low_bit = self.addr_bit_range
        
        # Create mask for the bit range
        mask = (1 << (high_bit - low_bit + 1)) - 1
        
        # Extract bits by shifting right and masking
        extracted_bits = (pc_int >> low_bit) & mask
        
        return extracted_bits
    
    def generate_index(self, pc_address):
        """Generate index for counter table based on prediction scheme."""
        pc_bits = self.extract_addr_bits(pc_address)
        
        # Generate index based on scheme
        if self.scheme == "addr_index":
            return pc_bits  # Use extracted PC bits directly
        elif self.scheme == "ghr":
            return self.ghr.get_value()  # Index is GHR itself
        elif self.scheme == "lhr":
            return self.lhr.get_register(pc_bits)  # LHR[pc_bits] - local history for this PC
        elif self.scheme == "gselect":
            # Concatenate pc_bits and ghr: (pc_bits << ghr_bit_size) | ghr
            ghr_value = self.ghr.get_value()
            ghr_bit_size = self.ghr_size
            return (pc_bits << ghr_bit_size) | ghr_value
        elif self.scheme == "gshare":
            # XOR pc_bits and ghr with MSBs aligned
            return pc_bits ^ self.ghr.get_value()
        else:
            return pc_bits  # Default to address-based
    
    def process_branch(self, pc_address, outcome):
        """Process a single branch entry and update all components."""
        # Generate index for this branch
        index = self.generate_index(pc_address)
        
        # Get current counter value
        current_counter = self.saturating_counter.get_counter(index)
        
        # Make prediction based on counter value (taken if above half, not taken if below half)
        threshold = (2 ** self.n_cnt_bits) // 2
        prediction = 1 if current_counter >= threshold else 0
        
        # Check if prediction was correct (predict or mispredict)
        is_predict = (prediction == outcome)
        
        # Update statistics
        self.total_branches += 1
        if is_predict:
            self.total_predicts += 1
        
        # Track unique indices
        if index not in self.unique_indices:
            self.unique_indices.add(index)
        else:
            self.index_hits += 1
        
        # Track per-index statistics
        if index not in self.index_stats:
            self.index_stats[index] = {'predicts': 0, 'mispredicts': 0, 'total': 0}
        
        self.index_stats[index]['total'] += 1
        if is_predict:
            self.index_stats[index]['predicts'] += 1
        else:
            self.index_stats[index]['mispredicts'] += 1
        
        # Track iteration stats
        predict_rate = (self.total_predicts / self.total_branches * 100) if self.total_branches > 0 else 0
        self.iteration_stats.append({
            'iteration': self.total_branches,
            'total_branches': self.total_branches,
            'total_predicts': self.total_predicts,
            'total_mispredicts': self.total_branches - self.total_predicts,
            'predict_rate': predict_rate,
            'unique_indices': len(self.unique_indices),
            'index_hits': self.index_hits,
            'index': index,
            'prediction': prediction,
            'outcome': outcome,
            'is_predict': is_predict
        })
        
        # Update counter based on outcome
        new_counter = self.saturating_counter.update_counter(index, outcome)
        
        # Update history registers
        self.ghr.update(outcome)
        pc_bits = self.extract_addr_bits(pc_address)
        self.lhr.update_register(pc_bits, outcome)
        
        return {
            'index': index,
            'counter_value': new_counter,
            'ghr_value': self.ghr.get_value(),
            'lhr_value': self.lhr.get_register(pc_bits),
            'prediction': prediction,
            'is_predict': is_predict
        }
    
    def generate_csv_report(self, output_dir, code_name, scheme, counter_policy, n_cnt_bits, addr_bit_range, ghr_size, lhr_size):
        """Generate CSV report with branch prediction statistics."""
        import csv
        import time
        
        # Create output directory if it doesn't exist
        create_directory_if_not_exists(output_dir)
        
        csv_file = os.path.join(output_dir, "branch_stats.csv")
        
        # Try to write the file with retry logic for permission issues
        max_retries = 3
        retry_delay = 1  # seconds
        
        for attempt in range(max_retries):
            try:
                with open(csv_file, 'w', newline='') as f:
                    writer = csv.writer(f)
                    
                    # Simulation parameters
                    writer.writerow(["Simulation Parameters"])
                    writer.writerow(["Parameter", "Value"])
                    writer.writerow(["Scheme", scheme])
                    writer.writerow(["Counter Policy", counter_policy])
                    writer.writerow(["Counter Bits", n_cnt_bits])
                    writer.writerow(["Address Bit Range", f"{addr_bit_range[0]}:{addr_bit_range[1]}"])
                    
                    # Show only relevant parameters based on scheme
                    if scheme in ["ghr", "gselect", "gshare"]:
                        writer.writerow(["GHR Size", ghr_size])
                    elif scheme == "lhr":
                        writer.writerow(["LHR Size", lhr_size])
                    elif scheme == "addr_index":
                        # No additional parameters needed for addr_index
                        pass
                    
                    writer.writerow([])
                    
                    # Overall statistics
                    predict_rate = (self.total_predicts / self.total_branches * 100) if self.total_branches > 0 else 0
                    n_unique_indices = len(self.unique_indices)
                    n_index_hits = self.index_hits
                    n_replacements = self.replacements
                    replacement_percentage = (n_replacements / self.total_branches * 100) if self.total_branches > 0 else 0
                    
                    # Write overall statistics
                    writer.writerow(["Overall Statistics"])
                    writer.writerow(["Metric", "Value", "Percentage", "Total"])
                    writer.writerow(["Total Branches", self.total_branches, "100.0%", self.total_branches])
                    writer.writerow(["Total Predicts", self.total_predicts, f"{predict_rate:.2f}%", self.total_predicts])
                    writer.writerow(["Total Mispredicts", self.total_branches - self.total_predicts, f"{100-predict_rate:.2f}%", self.total_branches - self.total_predicts])
                    writer.writerow(["Predict Rate", f"{predict_rate:.2f}%", "", ""])
                    writer.writerow([])
                    
                    # Index access statistics
                    writer.writerow(["Index Access Statistics"])
                    writer.writerow(["Metric", "Count", "Percentage", "Total"])
                    writer.writerow(["Unique Indices (n)", n_unique_indices, f"{(n_unique_indices/self.total_branches*100):.2f}%", n_unique_indices])
                    writer.writerow(["Index Hits (N)", n_index_hits, f"{(n_index_hits/self.total_branches*100):.2f}%", n_index_hits])
                    writer.writerow(["Replacements", n_replacements, f"{replacement_percentage:.2f}%", n_replacements])
                    writer.writerow([])
                    
                    # Per-index statistics
                    writer.writerow(["Per-Index Statistics"])
                    writer.writerow(["Index", "Total Branches", "Predicts", "Mispredicts", "Predict Rate", "Total Branches", "Total Predicts", "Total Mispredicts"])
                    
                    # Sort indices for consistent output
                    sorted_indices = sorted(self.index_stats.keys())
                    for index in sorted_indices:
                        stats = self.index_stats[index]
                        index_predict_rate = (stats['predicts'] / stats['total'] * 100) if stats['total'] > 0 else 0
                        writer.writerow([
                            index,
                            stats['total'],
                            stats['predicts'],
                            stats['mispredicts'],
                            f"{index_predict_rate:.2f}%",
                            stats['total'],
                            stats['predicts'],
                            stats['mispredicts']
                        ])
                    
                    # Iteration-by-iteration statistics
                    writer.writerow([])
                    writer.writerow(["Iteration-by-Iteration Statistics"])
                    writer.writerow(["Iteration", "Total Branches", "Total Predicts", "Total Mispredicts", "Predict Rate", "Unique Indices", "Index Hits", "Index", "Prediction", "Outcome", "Is Predict"])
                    
                    for stats in self.iteration_stats:
                        writer.writerow([
                            stats['iteration'],
                            stats['total_branches'],
                            stats['total_predicts'],
                            stats['total_mispredicts'],
                            f"{stats['predict_rate']:.2f}%",
                            stats['unique_indices'],
                            stats['index_hits'],
                            stats['index'],
                            stats['prediction'],
                            stats['outcome'],
                            stats['is_predict']
                        ])
                
                # If we get here, the file was written successfully
                return csv_file
                
            except PermissionError as e:
                if attempt < max_retries - 1:
                    print(f"Permission denied writing to {csv_file}. Retrying in {retry_delay} seconds... (attempt {attempt + 1}/{max_retries})")
                    time.sleep(retry_delay)
                    retry_delay *= 2  # Exponential backoff
                else:
                    print(f"Error: Failed to write to {csv_file} after {max_retries} attempts.")
                    print(f"Please ensure the file is not open in another program and you have write permissions.")
                    print(f"Original error: {e}")
                    raise
            except Exception as e:
                print(f"Error writing CSV file: {e}")
                raise
    
    def get_aggregated_stats(self):
        """Get current aggregated statistics."""
        predict_rate = (self.total_predicts / self.total_branches * 100) if self.total_branches > 0 else 0
        n_unique_indices = len(self.unique_indices)
        n_index_hits = self.index_hits
        
        return {
            'total_branches': self.total_branches,
            'total_predicts': self.total_predicts,
            'total_mispredicts': self.total_branches - self.total_predicts,
            'predict_rate': predict_rate,
            'unique_indices': n_unique_indices,
            'index_hits': n_index_hits
        }


def simulate_branch_prediction(branch_seq_file, scheme, counter_policy, n_cnt_bits, addr_bit_range, ghr_size, lhr_size, output_dir, debug_seq=False):
    """Simulate branch prediction with interactive mode."""
    print("========== [2/2] : BRANCH PREDICTION SIMULATION ==========")
    print(f"Branch prediction scheme: {scheme}")
    print(f"Counter policy: {counter_policy}")
    print(f"Counter bits: {n_cnt_bits}")
    print(f"Address bit range: {addr_bit_range[0]}:{addr_bit_range[1]}")
    print(f"GHR size: {ghr_size} bits")
    print(f"LHR size: {lhr_size} bits")
    print("Press Enter to process next entry, 'x' to exit, 's' for slow mode (100ms delay)")
    print("-" * 60)
    
    # Initialize branch predictor
    predictor = BranchPredictor(scheme, counter_policy, n_cnt_bits, addr_bit_range, ghr_size, lhr_size)
    slow_mode = False
    
    try:
        with open(branch_seq_file, 'r') as f:
            lines = f.readlines()
        
        # Skip header line
        data_lines = lines[1:] if len(lines) > 1 else []
        
        for i, line in enumerate(data_lines):
            line = line.strip()
            if not line:
                continue
            
            # Parse branch entry: "0x<address> B <outcome>"
            parts = line.split()
            if len(parts) >= 3 and parts[1] == 'B':
                pc_address = parts[0]
                outcome = int(parts[2])
                
                # Process branch through predictor
                result = predictor.process_branch(pc_address, outcome)
                
                # Get aggregated stats
                stats = predictor.get_aggregated_stats()
                
                if debug_seq:
                    predict_mispredict = "PREDICT" if result['is_predict'] else "MISPREDICT"
                    print(f"processed {line} - outcome - {outcome}, prediction - {result['prediction']}, {predict_mispredict}")
                    print(f"  index: {result['index']}, counter: {result['counter_value']}, ghr: {result['ghr_value']}, lhr: {result['lhr_value']}")
                    print(f"  [AGGREGATED] Branch: {stats['total_branches']}, Predicts: {stats['total_predicts']}, Mispredicts: {stats['total_mispredicts']}, Predict Rate: {stats['predict_rate']:.2f}%, Unique Indices: {stats['unique_indices']}, Index Hits: {stats['index_hits']}")
                
                # Interactive mode
                if slow_mode:
                    time.sleep(0.1)  # 100ms delay
                    user_input = 'continue'
                else:
                    user_input = input()
                
                if user_input.lower() == 'x':
                    print("Exiting simulation...")
                    break
                elif user_input.lower() == 's':
                    print("Switching to slow mode (100ms delay per iteration)...")
                    slow_mode = True
                    time.sleep(0.1)  # 100ms delay for first slow iteration
        
        # Generate CSV report
        csv_file = predictor.generate_csv_report(output_dir, "branch_prediction", scheme, counter_policy, n_cnt_bits, addr_bit_range, ghr_size, lhr_size)
        print(f"Generated statistics report: {csv_file}")
        
        print("========== BRANCH PREDICTION SIMULATION COMPLETE ================\n")
        
    except FileNotFoundError:
        print(f"Error: Branch sequence file {branch_seq_file} not found")
        sys.exit(1)
    except Exception as e:
        print(f"Error during simulation: {e}")
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser()
    
    parser.add_argument(
        '-code',
        required=True,
        help='Code file path (e.g., code/linked_list.c)'
    )
    
    parser.add_argument(
        '-filter_debug',
        action='store_true',
        help='Enable debug output'
    )
    
    parser.add_argument(
        '-scheme',
        required=True,
        help='Branch prediction scheme (addr_index, ghr, lhr, gselect, gshare)'
    )
    
    parser.add_argument(
        '-counter_policy',
        default='saturating',
        help='Counter policy (default: saturating)'
    )
    
    parser.add_argument(
        '-n_cnt_bits',
        type=int,
        default=2,
        help='Number of counter bits (default: 2)'
    )
    
    parser.add_argument(
        '-debug_seq',
        action='store_true',
        help='Enable debug output for branch sequence processing'
    )
    
    parser.add_argument(
        '-addr_bit_range',
        required=True,
        help='Address bit range as high_bit,low_bit (e.g., 11,2)'
    )
    
    parser.add_argument(
        '-ghr_size',
        type=int,
        default=8,
        help='Global History Register size in bits (default: 8)'
    )
    
    parser.add_argument(
        '-lhr_size',
        type=int,
        default=8,
        help='Local History Register size in bits (default: 8)'
    )
    
    args = parser.parse_args()
    
    # Parse address bit range
    try:
        addr_bit_range = tuple(map(int, args.addr_bit_range.split(',')))
        if len(addr_bit_range) != 2 or addr_bit_range[0] < addr_bit_range[1]:
            raise ValueError("Invalid bit range format")
    except ValueError:
        print(f"Error: Invalid address bit range '{args.addr_bit_range}'")
        print("Expected format: high_bit,low_bit (e.g., 11,2)")
        sys.exit(1)
    
    # Validate arguments
    scheme = validate_scheme(args.scheme)
    counter_policy = validate_counter_policy(args.counter_policy)
    
    # Extract filename from code path
    code_path = args.code
    if code_path.endswith('.c'):
        code_name = os.path.splitext(os.path.basename(code_path))[0]
    else:
        code_name = os.path.basename(code_path)
    
    # Construct file paths
    input_file = f"sim/runs/{code_name}_on_sanity/pc_seq.hex"
    output_file = f"sim/results/{code_name}/branch_seq.hex"
    
    if args.filter_debug:
        print(f"Processing code: {code_name}")
        print(f"Input file: {input_file}")
        print(f"Output file: {output_file}")
        print(f"Branch prediction scheme: {scheme}")
        print(f"Counter policy: {counter_policy}")
        print(f"Counter bits: {args.n_cnt_bits}")
        print(f"Address bit range: {addr_bit_range[0]}:{addr_bit_range[1]}")
        print(f"GHR size: {args.ghr_size} bits")
        print(f"LHR size: {args.lhr_size} bits")
        print(f"Debug sequence: {args.debug_seq}")
        print("-" * 50)
    
    # Check if input file exists
    if not os.path.exists(input_file):
        print(f"Error: Input file {input_file} does not exist")
        if args.filter_debug:
            print("Please ensure the file exists and the code name is correct.")
        sys.exit(1)
    
    # Process the file
    process_pc_sequence(input_file, output_file, args.filter_debug)
    
    # Step 2 - branch prediction simulation
    output_dir = os.path.dirname(output_file)
    simulate_branch_prediction(output_file, scheme, counter_policy, args.n_cnt_bits, addr_bit_range, args.ghr_size, args.lhr_size, output_dir, args.debug_seq)


if __name__ == "__main__":
    main()
