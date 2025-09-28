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
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    CData/*0:0*/ tb__DOT__core_write;
    CData/*3:0*/ tb__DOT__core_wstrb;
    CData/*0:0*/ tb__DOT__core_read;
    CData/*0:0*/ tb__DOT__core_ready;
    CData/*0:0*/ tb__DOT__cleanup;
    CData/*0:0*/ tb__DOT__dmem_write;
    CData/*3:0*/ tb__DOT__dmem_wstrb;
    CData/*0:0*/ tb__DOT__dmem_read;
    CData/*0:0*/ tb__DOT__dmem_ready;
    CData/*3:0*/ tb__DOT__i_dmem__DOT__read_counter;
    CData/*3:0*/ tb__DOT__i_dmem__DOT__read_counter_next;
    CData/*3:0*/ tb__DOT__i_dmem__DOT__write_counter;
    CData/*3:0*/ tb__DOT__i_dmem__DOT__write_counter_next;
    CData/*3:0*/ tb__DOT__i_dmem__DOT__latched_wstrb;
    CData/*0:0*/ tb__DOT__i_dmem__DOT__latched_operation;
    CData/*0:0*/ tb__DOT__i_dcache__DOT__cache_hit;
    CData/*0:0*/ tb__DOT__i_dcache__DOT__perform_write;
    CData/*1:0*/ tb__DOT__i_dcache__DOT__latched_core_index;
    CData/*3:0*/ tb__DOT__i_dcache__DOT__latched_core_wstrb;
    CData/*0:0*/ tb__DOT__i_dcache__DOT__latched_core_write;
    CData/*3:0*/ tb__DOT__i_dcache__DOT__writeback_buffer_wstrb;
    CData/*0:0*/ tb__DOT__i_dcache__DOT__writeback_buffer_valid_r;
    CData/*0:0*/ tb__DOT__i_dcache__DOT__writeback_buffer_valid_next;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ tb__DOT__i_dmem__DOT__latched_addr;
    IData/*31:0*/ tb__DOT__cycle_count;
    IData/*31:0*/ tb__DOT__core_addr;
    IData/*31:0*/ tb__DOT__core_wdata;
    IData/*31:0*/ tb__DOT__dmem_addr;
    IData/*31:0*/ tb__DOT__dmem_wdata;
    IData/*31:0*/ tb__DOT__dmem_rdata;
    IData/*31:0*/ tb__DOT__cache_mem_fh;
    IData/*31:0*/ tb__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb__DOT__i_dmem__DOT__curr_state;
    IData/*31:0*/ tb__DOT__i_dmem__DOT__next_state;
    IData/*31:0*/ tb__DOT__i_dmem__DOT__latched_wdata;
    IData/*31:0*/ tb__DOT__i_dmem__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i;
    IData/*27:0*/ tb__DOT__i_dcache__DOT__latched_core_tag;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__latched_core_wdata;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__writeback_buffer_addr;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__writeback_buffer_wdata;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__curr_cache_state;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__next_cache_state;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__curr_wb_state;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__next_wb_state;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__unnamedblk1__DOT__j_byte;
    IData/*31:0*/ tb__DOT__i_dcache__DOT__unnamedblk2__DOT__j_byte;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 4> tb__DOT__tc_addr;
    VlUnpacked<IData/*31:0*/, 1024> tb__DOT__i_dmem__DOT__mem_array;
    VlUnpacked<CData/*0:0*/, 4> tb__DOT__i_dcache__DOT__valid;
    VlUnpacked<CData/*0:0*/, 4> tb__DOT__i_dcache__DOT__dirty;
    VlUnpacked<IData/*27:0*/, 4> tb__DOT__i_dcache__DOT__tag;
    VlUnpacked<IData/*31:0*/, 4> tb__DOT__i_dcache__DOT__mem_array;
    VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 1024>, true, IData/*31:0*/, 1> __VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array;
    VlTriggerScheduler __VtrigSched_hf87a9cf6__0;
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
