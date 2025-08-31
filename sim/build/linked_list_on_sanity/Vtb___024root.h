// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        CData/*0:0*/ tb__DOT__deadbeef_written;
        CData/*4:0*/ tb__DOT__dut__DOT__instr_rs1;
        CData/*4:0*/ tb__DOT__dut__DOT__instr_rs2;
        CData/*4:0*/ tb__DOT__dut__DOT__instr_rd;
        CData/*0:0*/ tb__DOT__dut__DOT__alu_eq;
        CData/*0:0*/ tb__DOT__dut__DOT__alu_lt;
        CData/*0:0*/ tb__DOT__dut__DOT__alu_ltu;
        CData/*3:0*/ tb__DOT__dut__DOT__mem_wstrb;
        CData/*0:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11;
        CData/*0:0*/ tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0;
        CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_0;
        CData/*4:0*/ __VdlyDim0__tb__DOT__dut__DOT__rf_main__DOT__regs__v0;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v0;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v1;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v2;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v3;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v4;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v5;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v6;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v7;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v8;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v9;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v10;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v11;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v12;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v13;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v14;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v15;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v16;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v17;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v18;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v19;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v20;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v21;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v22;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v23;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v24;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v25;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v26;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v27;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v28;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v29;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v30;
        CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v31;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb__DOT__dut__DOT__pc;
        IData/*31:0*/ tb__DOT__dut__DOT__pc_next;
        IData/*31:0*/ tb__DOT__dut__DOT__instr_reg;
        IData/*31:0*/ tb__DOT__dut__DOT__opcode_e;
        IData/*31:0*/ tb__DOT__dut__DOT__instr_type;
        IData/*31:0*/ tb__DOT__dut__DOT__rs2_data;
        IData/*31:0*/ tb__DOT__dut__DOT__regfile_wdata;
        IData/*31:0*/ tb__DOT__dut__DOT__imm_value;
        IData/*31:0*/ tb__DOT__dut__DOT__alu_result;
        IData/*31:0*/ tb__DOT__dut__DOT__alu_src_a;
        IData/*31:0*/ tb__DOT__dut__DOT__alu_src_b;
        IData/*31:0*/ tb__DOT__dut__DOT__mem_wdata;
        IData/*31:0*/ tb__DOT__dut__DOT__i_imem__DOT__unnamedblk2__DOT__j;
        IData/*31:0*/ tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i;
    };
    struct {
        IData/*31:0*/ tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl;
        IData/*31:0*/ tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk2__DOT__j;
        IData/*31:0*/ tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __Vfunc_instr_enum_from_val__0__Vfuncout;
        IData/*31:0*/ __Vfunc_instr_type_enum_from_instr__1__Vfuncout;
        IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__rf_main__DOT__regs__v0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 1024> tb__DOT__dut__DOT__i_imem__DOT__mem_array;
        VlUnpacked<IData/*31:0*/, 32> tb__DOT__dut__DOT__rf_main__DOT__regs;
        VlUnpacked<IData/*31:0*/, 1024> tb__DOT__dut__DOT__i_dmem__DOT__mem_array;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 1024>, false, IData/*31:0*/, 1> __VdlyCommitQueuetb__DOT__dut__DOT__i_imem__DOT__mem_array;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 1024>, true, IData/*31:0*/, 1> __VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array;
    VlTriggerScheduler __VtrigSched_hf87a9c37__0;
    VlTriggerScheduler __VtrigSched_h96aaa0a4__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
