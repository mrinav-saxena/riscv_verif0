// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cycle_count = 0U;
    vlSelfRef.tb__DOT__tc_addr[0U] = 0U;
    vlSelfRef.tb__DOT__tc_addr[1U] = 0x1000000U;
    vlSelfRef.tb__DOT__tc_addr[2U] = 4U;
    vlSelfRef.tb__DOT__tc_addr[3U] = 0x1000004U;
    vlSelfRef.tb__DOT__core_addr = vlSelfRef.tb__DOT__tc_addr
        [0U];
    vlSelfRef.tb__DOT__core_wdata = 0xa5a5a5a5U;
    vlSelfRef.tb__DOT__core_write = 0U;
    vlSelfRef.tb__DOT__core_wstrb = 0xfU;
    vlSelfRef.tb__DOT__core_read = 0U;
    vlSelfRef.tb__DOT__cleanup = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                         nullptr, "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\tb.sv", 
                                         94);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb__DOT__core_write = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\tb.sv", 
                                         97);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb__DOT__core_write = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3a98ULL, 
                                         nullptr, "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\tb.sv", 
                                         100);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb__DOT__core_wdata = 0x5a5a5a5aU;
    vlSelfRef.tb__DOT__core_write = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\tb.sv", 
                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb__DOT__core_write = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3a98ULL, 
                                         nullptr, "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\tb.sv", 
                                         107);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\\tb.sv", 109, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit = (
                                                   ((vlSelfRef.tb__DOT__core_addr 
                                                     >> 0xcU) 
                                                    == 
                                                    vlSelfRef.tb__DOT__i_dcache__DOT__tag
                                                    [
                                                    (0x3ffU 
                                                     & (vlSelfRef.tb__DOT__core_addr 
                                                        >> 2U))]) 
                                                   & vlSelfRef.tb__DOT__i_dcache__DOT__valid
                                                   [
                                                   (0x3ffU 
                                                    & (vlSelfRef.tb__DOT__core_addr 
                                                       >> 2U))]);
    vlSelfRef.tb__DOT__dmem_addr = 0U;
    vlSelfRef.tb__DOT__dmem_read = 0U;
    vlSelfRef.tb__DOT__dmem_ready = 0U;
    vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
        = vlSelfRef.tb__DOT__i_dmem__DOT__write_counter;
    vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
        = vlSelfRef.tb__DOT__i_dmem__DOT__read_counter;
    vlSelfRef.tb__DOT__i_dmem__DOT__next_state = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__dmem_addr 
                            = vlSelfRef.tb__DOT__core_addr;
                    }
                } else {
                    vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__core_addr;
                }
            }
        }
    } else if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__core_addr;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_addr;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__dmem_read = 1U;
                    }
                } else {
                    vlSelfRef.tb__DOT__dmem_read = 1U;
                }
            }
        }
    } else if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__dmem_read = 1U;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if (vlSelfRef.tb__DOT__dmem_write) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
                = (0xfU & VL_URANDOM_RANGE_I(1U, 5U));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 2U;
        } else if (vlSelfRef.tb__DOT__dmem_read) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
                = (0xfU & VL_URANDOM_RANGE_I(1U, 5U));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 1U;
        } else {
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 0U;
        }
    } else if ((2U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if ((1U < (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
                = (0xfU & ((IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter) 
                           - (IData)(1U)));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state 
                = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
        } else if ((1U == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next = 0U;
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 3U;
        }
    } else if ((1U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if ((1U < (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
                = (0xfU & ((IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter) 
                           - (IData)(1U)));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state 
                = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
        } else if ((1U == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next = 0U;
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 3U;
        }
    } else if ((3U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        vlSelfRef.tb__DOT__dmem_ready = 1U;
        vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 0U;
    }
    vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 0U;
    vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state 
        = vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state = 1U;
            }
        }
    } else if ((1U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__dmem_ready) {
            vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state = 0U;
        }
    }
    vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state 
        = vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state;
    vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next 
        = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if (vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit) {
                vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 0U;
            } else {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state 
                    = (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                       [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                   >> 2U))] ? ((0U 
                                                == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)
                                                ? 2U
                                                : 3U)
                        : 2U);
            }
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 1U;
                    }
                }
            }
        }
    } else {
        if ((2U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if (vlSelfRef.tb__DOT__dmem_ready) {
                vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 0U;
            }
        } else if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 2U;
            }
        }
        if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                    vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 1U;
                }
            }
        }
    }
    if ((0U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if ((1U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
            if (vlSelfRef.tb__DOT__dmem_ready) {
                vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 0U;
            }
        }
    }
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf);
void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v0 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v0 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v1 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v1 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v2 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v2 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v3 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v3 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v4;
    __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v4 = 0;
    // Body
    if (vlSelfRef.rst_n) {
        vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state 
            = vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state;
        vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state 
            = vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state;
    } else {
        vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state = 0U;
        vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (((2U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state) 
             & (1U == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter)))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk2__DOT__i = 4U;
            if ((1U & (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb))) {
                __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v0 
                    = (0xffU & vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata);
                __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v0 
                    = vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0 = 0U;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0 
                    = ((0xffffff00U & __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0) 
                       | (IData)(__VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v0));
                vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v0, 0xffU, (IData)(__VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v0));
            }
            if ((2U & (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb))) {
                __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v1 
                    = (0xffU & (vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata 
                                >> 8U));
                __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v1 
                    = vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1 = 0U;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1 
                    = ((0xffff00ffU & __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1) 
                       | ((IData)(__VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v1) 
                          << 8U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v1, 0xff00U, (IData)(__VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v1));
            }
            if ((4U & (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb))) {
                __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v2 
                    = (0xffU & (vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata 
                                >> 0x10U));
                __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v2 
                    = vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2 = 0U;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2 
                    = ((0xff00ffffU & __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2) 
                       | ((IData)(__VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v2) 
                          << 0x10U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v2, 0xff0000U, (IData)(__VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v2));
            }
            if ((8U & (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb))) {
                __VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v3 
                    = (vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata 
                       >> 0x18U);
                __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v3 
                    = vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3 = 0U;
                __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3 
                    = ((0xffffffU & __VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3) 
                       | ((IData)(__VdlyVal__tb__DOT__i_dmem__DOT__mem_array__v3) 
                          << 0x18U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__i_dmem__DOT__mem_array__v3, 0xff000000U, (IData)(__VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v3));
            }
        } else {
            vlSelfRef.tb__DOT__dmem_rdata = (((1U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state) 
                                              & (1U 
                                                 == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter)))
                                              ? vlSelfRef.tb__DOT__i_dmem__DOT__mem_array
                                             [vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr]
                                              : 0U);
        }
        if ((0U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
            if (vlSelfRef.tb__DOT__dmem_write) {
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation = 0U;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dmem_addr 
                                 >> 2U));
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata 
                    = vlSelfRef.tb__DOT__dmem_wdata;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb 
                    = vlSelfRef.tb__DOT__dmem_wstrb;
            } else if (vlSelfRef.tb__DOT__dmem_read) {
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation = 1U;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dmem_addr 
                                 >> 2U));
            } else {
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation = 0U;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr = 0U;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata = 0U;
                vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb = 0U;
            }
        }
    } else {
        vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x400U, vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v4 
                = (0x3ffU & vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.enqueue(0U, 0xffffffffU, (IData)(__VdlyDim0__tb__DOT__i_dmem__DOT__mem_array__v4));
            vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i);
        }
        vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr = 0U;
        vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata = 0U;
        vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb = 0U;
        vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation = 0U;
        vlSelfRef.tb__DOT__dmem_rdata = 0U;
    }
    vlSelfRef.__VdlyCommitQueuetb__DOT__i_dmem__DOT__mem_array.commit(vlSelfRef.tb__DOT__i_dmem__DOT__mem_array);
    if (vlSelfRef.rst_n) {
        vlSelfRef.tb__DOT__i_dmem__DOT__curr_state 
            = vlSelfRef.tb__DOT__i_dmem__DOT__next_state;
        vlSelfRef.tb__DOT__i_dmem__DOT__write_counter 
            = vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next;
        vlSelfRef.tb__DOT__i_dmem__DOT__read_counter 
            = vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next;
    } else {
        vlSelfRef.tb__DOT__i_dmem__DOT__curr_state = 0U;
        vlSelfRef.tb__DOT__i_dmem__DOT__write_counter = 0U;
        vlSelfRef.tb__DOT__i_dmem__DOT__read_counter = 0U;
    }
    vlSelfRef.tb__DOT__dmem_wdata = 0U;
    vlSelfRef.tb__DOT__dmem_wstrb = 0U;
    vlSelfRef.tb__DOT__dmem_write = 0U;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__dmem_wdata = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wdata;
                vlSelfRef.tb__DOT__dmem_wstrb = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wstrb;
                vlSelfRef.tb__DOT__dmem_write = 1U;
            }
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cycle_count = ((IData)(1U) + vlSelfRef.tb__DOT__cycle_count);
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit = (
                                                   ((vlSelfRef.tb__DOT__core_addr 
                                                     >> 0xcU) 
                                                    == 
                                                    vlSelfRef.tb__DOT__i_dcache__DOT__tag
                                                    [
                                                    (0x3ffU 
                                                     & (vlSelfRef.tb__DOT__core_addr 
                                                        >> 2U))]) 
                                                   & vlSelfRef.tb__DOT__i_dcache__DOT__valid
                                                   [
                                                   (0x3ffU 
                                                    & (vlSelfRef.tb__DOT__core_addr 
                                                       >> 2U))]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dmem_addr = 0U;
    vlSelfRef.tb__DOT__dmem_read = 0U;
    vlSelfRef.tb__DOT__dmem_ready = 0U;
    vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
        = vlSelfRef.tb__DOT__i_dmem__DOT__write_counter;
    vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
        = vlSelfRef.tb__DOT__i_dmem__DOT__read_counter;
    vlSelfRef.tb__DOT__i_dmem__DOT__next_state = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__dmem_addr 
                            = vlSelfRef.tb__DOT__core_addr;
                    }
                } else {
                    vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__core_addr;
                }
            }
        }
    } else if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__core_addr;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__dmem_addr = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_addr;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__dmem_read = 1U;
                    }
                } else {
                    vlSelfRef.tb__DOT__dmem_read = 1U;
                }
            }
        }
    } else if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__dmem_read = 1U;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if (vlSelfRef.tb__DOT__dmem_write) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
                = (0xfU & VL_URANDOM_RANGE_I(1U, 5U));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 2U;
        } else if (vlSelfRef.tb__DOT__dmem_read) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
                = (0xfU & VL_URANDOM_RANGE_I(1U, 5U));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 1U;
        } else {
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 0U;
        }
    } else if ((2U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if ((1U < (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next 
                = (0xfU & ((IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter) 
                           - (IData)(1U)));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state 
                = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
        } else if ((1U == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next = 0U;
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 3U;
        }
    } else if ((1U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        if ((1U < (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next 
                = (0xfU & ((IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter) 
                           - (IData)(1U)));
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state 
                = vlSelfRef.tb__DOT__i_dmem__DOT__curr_state;
        } else if ((1U == (IData)(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter))) {
            vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next = 0U;
            vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 3U;
        }
    } else if ((3U == vlSelfRef.tb__DOT__i_dmem__DOT__curr_state)) {
        vlSelfRef.tb__DOT__dmem_ready = 1U;
        vlSelfRef.tb__DOT__i_dmem__DOT__next_state = 0U;
    }
    vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 0U;
    vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state 
        = vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state = 1U;
            }
        }
    } else if ((1U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__dmem_ready) {
            vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state = 0U;
        }
    }
    vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state 
        = vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state;
    vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next 
        = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r;
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if (vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit) {
                vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 0U;
            } else {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state 
                    = (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                       [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                   >> 2U))] ? ((0U 
                                                == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)
                                                ? 2U
                                                : 3U)
                        : 2U);
            }
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(0x3ffU & (vlSelfRef.tb__DOT__core_addr 
                                >> 2U))]) {
                    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                        vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 1U;
                    }
                }
            }
        }
    } else {
        if ((2U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if (vlSelfRef.tb__DOT__dmem_ready) {
                vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 0U;
            }
        } else if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 2U;
            }
        }
        if ((2U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
            if ((3U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
                    vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 1U;
                }
            }
        }
    }
    if ((0U != vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if ((1U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
            if (vlSelfRef.tb__DOT__dmem_ready) {
                vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = 0U;
            }
        }
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\\tb.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\\tb.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
