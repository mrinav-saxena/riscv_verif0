// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtb___024root___eval_final(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_final\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_settle(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_settle\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/ip_level/dmap_wback_walloc\\tb.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf);
VL_ATTR_COLD void Vtb___024root____Vm_traceActivitySetAll(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb___024root___stl_sequent__TOP__0(vlSelf);
        Vtb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dmem_wdata = 0U;
    vlSelfRef.tb__DOT__dmem_wstrb = 0U;
    vlSelfRef.tb__DOT__dmem_write = 0U;
    vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit = (
                                                   ((vlSelfRef.tb__DOT__core_addr 
                                                     >> 4U) 
                                                    == 
                                                    vlSelfRef.tb__DOT__i_dcache__DOT__tag
                                                    [
                                                    (3U 
                                                     & (vlSelfRef.tb__DOT__core_addr 
                                                        >> 2U))]) 
                                                   & vlSelfRef.tb__DOT__i_dcache__DOT__valid
                                                   [
                                                   (3U 
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
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)) {
        if (vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r) {
            if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
                vlSelfRef.tb__DOT__dmem_wdata = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wdata;
                vlSelfRef.tb__DOT__dmem_wstrb = vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wstrb;
                vlSelfRef.tb__DOT__dmem_write = 1U;
            }
        }
    }
    if ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state)) {
        if (vlSelfRef.tb__DOT__core_write) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(3U & (vlSelfRef.tb__DOT__core_addr 
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
                    [(3U & (vlSelfRef.tb__DOT__core_addr 
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
    vlSelfRef.tb__DOT__core_ready = 0U;
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
                vlSelfRef.tb__DOT__core_ready = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__perform_write = 1U;
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state = 0U;
            } else {
                vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state 
                    = (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                       [(3U & (vlSelfRef.tb__DOT__core_addr 
                               >> 2U))] ? ((0U == vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state)
                                            ? 2U : 3U)
                        : 2U);
            }
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit)))) {
                if (vlSelfRef.tb__DOT__i_dcache__DOT__dirty
                    [(3U & (vlSelfRef.tb__DOT__core_addr 
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
                vlSelfRef.tb__DOT__core_ready = 1U;
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

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root____Vm_traceActivitySetAll(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root____Vm_traceActivitySetAll\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cycle_count = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__tc_addr[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__core_addr = 0;
    vlSelf->tb__DOT__core_wdata = 0;
    vlSelf->tb__DOT__core_write = 0;
    vlSelf->tb__DOT__core_wstrb = 0;
    vlSelf->tb__DOT__core_read = 0;
    vlSelf->tb__DOT__core_ready = 0;
    vlSelf->tb__DOT__cleanup = 0;
    vlSelf->tb__DOT__dmem_addr = 0;
    vlSelf->tb__DOT__dmem_wdata = 0;
    vlSelf->tb__DOT__dmem_write = 0;
    vlSelf->tb__DOT__dmem_wstrb = 0;
    vlSelf->tb__DOT__dmem_read = 0;
    vlSelf->tb__DOT__dmem_rdata = 0;
    vlSelf->tb__DOT__dmem_ready = 0;
    vlSelf->tb__DOT__cache_mem_fh = 0;
    vlSelf->tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb__DOT__i_dmem__DOT__curr_state = 0;
    vlSelf->tb__DOT__i_dmem__DOT__next_state = 0;
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb__DOT__i_dmem__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__i_dmem__DOT__read_counter = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dmem__DOT__read_counter_next = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dmem__DOT__write_counter = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dmem__DOT__write_counter_next = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dmem__DOT__latched_addr = VL_RAND_RESET_I(10);
    vlSelf->tb__DOT__i_dmem__DOT__latched_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__i_dmem__DOT__latched_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dmem__DOT__latched_operation = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dmem__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__i_dcache__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__i_dcache__DOT__dirty[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__i_dcache__DOT__tag[__Vi0] = VL_RAND_RESET_I(28);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__i_dcache__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__i_dcache__DOT__cache_hit = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dcache__DOT__perform_write = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dcache__DOT__latched_core_tag = VL_RAND_RESET_I(28);
    vlSelf->tb__DOT__i_dcache__DOT__latched_core_index = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__i_dcache__DOT__latched_core_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__i_dcache__DOT__latched_core_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dcache__DOT__latched_core_write = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dcache__DOT__writeback_buffer_addr = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__i_dcache__DOT__writeback_buffer_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__i_dcache__DOT__writeback_buffer_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__i_dcache__DOT__writeback_buffer_valid_r = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dcache__DOT__writeback_buffer_valid_next = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__i_dcache__DOT__curr_cache_state = 0;
    vlSelf->tb__DOT__i_dcache__DOT__next_cache_state = 0;
    vlSelf->tb__DOT__i_dcache__DOT__curr_wb_state = 0;
    vlSelf->tb__DOT__i_dcache__DOT__next_wb_state = 0;
    vlSelf->tb__DOT__i_dcache__DOT__unnamedblk1__DOT__j_byte = 0;
    vlSelf->tb__DOT__i_dcache__DOT__unnamedblk2__DOT__j_byte = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
