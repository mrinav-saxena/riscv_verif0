// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb__DOT__tc_addr[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb__DOT__tc_addr[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb__DOT__tc_addr[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb__DOT__tc_addr[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb__DOT__core_addr),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb__DOT__core_wdata),32);
        bufp->chgBit(oldp+6,(vlSelfRef.tb__DOT__core_write));
        bufp->chgCData(oldp+7,(vlSelfRef.tb__DOT__core_wstrb),4);
        bufp->chgBit(oldp+8,(vlSelfRef.tb__DOT__core_read));
        bufp->chgBit(oldp+9,(vlSelfRef.tb__DOT__cleanup));
        bufp->chgSData(oldp+10,((0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                           >> 2U))),10);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+11,(vlSelfRef.tb__DOT__dmem_addr),32);
        bufp->chgBit(oldp+12,(vlSelfRef.tb__DOT__dmem_read));
        bufp->chgBit(oldp+13,(vlSelfRef.tb__DOT__dmem_ready));
        bufp->chgBit(oldp+14,(vlSelfRef.tb__DOT__i_dcache__DOT__perform_write));
        bufp->chgBit(oldp+15,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next));
        bufp->chgIData(oldp+16,(vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state),32);
        bufp->chgIData(oldp+17,(vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state),32);
        bufp->chgSData(oldp+18,((0x3ffU & (vlSelfRef.tb__DOT__dmem_addr 
                                           >> 2U))),10);
        bufp->chgIData(oldp+19,(vlSelfRef.tb__DOT__i_dmem__DOT__next_state),32);
        bufp->chgCData(oldp+20,(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next),4);
        bufp->chgCData(oldp+21,(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+22,(vlSelfRef.tb__DOT__dmem_wdata),32);
        bufp->chgBit(oldp+23,(vlSelfRef.tb__DOT__dmem_write));
        bufp->chgCData(oldp+24,(vlSelfRef.tb__DOT__dmem_wstrb),4);
        bufp->chgIData(oldp+25,(vlSelfRef.tb__DOT__dmem_rdata),32);
        bufp->chgIData(oldp+26,(vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb__DOT__i_dmem__DOT__curr_state),32);
        bufp->chgCData(oldp+29,(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter),4);
        bufp->chgCData(oldp+30,(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter),4);
        bufp->chgSData(oldp+31,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr),10);
        bufp->chgIData(oldp+32,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata),32);
        bufp->chgCData(oldp+33,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb),4);
        bufp->chgBit(oldp+34,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation));
        bufp->chgIData(oldp+35,(vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+37,(vlSelfRef.clk));
    bufp->chgBit(oldp+38,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+39,(vlSelfRef.tb__DOT__cycle_count),32);
    bufp->chgBit(oldp+40,(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit));
}

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
