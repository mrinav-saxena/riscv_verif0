import argparse
import os
import sys
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
        required=True,
        help='Counter policy (saturating)'
    )
    
    args = parser.parse_args()
    
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
        print("-" * 50)
    
    # Check if input file exists
    if not os.path.exists(input_file):
        print(f"Error: Input file {input_file} does not exist")
        if args.filter_debug:
            print("Please ensure the file exists and the code name is correct.")
        sys.exit(1)
    
    # Process the file
    process_pc_sequence(input_file, output_file, args.filter_debug)
    
    # TODO: Add step 2 - branch prediction simulation
    print("========== [2/2] : BRANCH PREDICTION SIMULATION ==========")
    print(f"Branch prediction scheme: {scheme}")
    print(f"Counter policy: {counter_policy}")
    print("========== BRANCH PREDICTION SIMULATION =================\n")


if __name__ == "__main__":
    main()
