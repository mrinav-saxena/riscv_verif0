#include "verilated.h"
#include "verilated_fst_c.h"
#include "Vtb.h"

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

static void tick(Vtb* top, VerilatedFstC* tfp) {
    // Clock LOW for 500ps
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time);
    
    // Clock HIGH for 500ps  
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time + 500);
    
    main_time += 1000;  // Total cycle time: 1000ps
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtb* top = new Vtb;
    VerilatedFstC* tfp = new VerilatedFstC;
    top->trace(tfp, 99);
    tfp->open("dump.fst");

    // reset low for 1ns
    top->rst_n = 0;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time += 1000;
    
    // reset high for 1ns
    top->rst_n = 1;
    top->eval();
    if (tfp) tfp->dump(main_time);
    main_time += 1000;
    
    // run N cycles
    for (int i = 0; i < 200; ++i) {
        tick(top, tfp);
        if (Verilated::gotFinish()) {
            break ;
        }
    }

    tfp->close();
    delete tfp;
    delete top;
    return 0;
}
