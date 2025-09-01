// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static__TOP\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__deadbeef_written = 0U;
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
            VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\\tb.sv", 1, "", "Settle region did not converge.");
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
    // Init
    CData/*2:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3;
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3 = 0;
    CData/*7:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4;
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4 = 0;
    SData/*15:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5;
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5 = 0;
    IData/*31:0*/ __Vfunc_instr_enum_from_val__0__instr;
    __Vfunc_instr_enum_from_val__0__instr = 0;
    IData/*31:0*/ __Vfunc_instr_type_enum_from_instr__1__instr_opcode;
    __Vfunc_instr_type_enum_from_instr__1__instr_opcode = 0;
    // Body
    vlSelfRef.tb__DOT__dut__DOT__pc_next = ((IData)(4U) 
                                            + vlSelfRef.tb__DOT__dut__DOT__pc);
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3 
        = (7U & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                 [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                             >> 2U))] >> 0xcU));
    vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 
        = (0x7fU & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
           [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                       >> 2U))]);
    vlSelfRef.tb__DOT__dut__DOT__instr_rs1 = (0x1fU 
                                              & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                 [(0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                 >> 0xfU));
    vlSelfRef.tb__DOT__dut__DOT__instr_rs2 = (0x1fU 
                                              & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                 [(0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                 >> 0x14U));
    vlSelfRef.tb__DOT__dut__DOT__instr_rd = (0x1fU 
                                             & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                [(0x3ffU 
                                                  & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                     >> 2U))] 
                                                >> 7U));
    vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0 
        = (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
           [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                       >> 2U))] >> 0x1fU);
    vlSelfRef.tb__DOT__dut__DOT__instr_reg = vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
        [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                    >> 2U))];
    vlSelfRef.tb__DOT__dut__DOT__rs2_data = ((0U == (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rs2))
                                              ? 0U : 
                                             vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs
                                             [vlSelfRef.tb__DOT__dut__DOT__instr_rs2]);
    vlSelfRef.tb__DOT__dut__DOT__imm_value = ((((0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelfRef.tb__DOT__dut__DOT__instr_reg)) 
                                                | (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.tb__DOT__dut__DOT__instr_reg))) 
                                               | (0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.tb__DOT__dut__DOT__instr_reg)))
                                               ? ((
                                                   (- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                                                   << 0xcU) 
                                                  | (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                     [
                                                     (0x3ffU 
                                                      & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                         >> 2U))] 
                                                     >> 0x14U))
                                               : ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.tb__DOT__dut__DOT__instr_reg))
                                                   ? 
                                                  (((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                          [
                                                          (0x3ffU 
                                                           & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                              >> 2U))] 
                                                          >> 0x14U)) 
                                                      | (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rd)))
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.tb__DOT__dut__DOT__instr_reg))
                                                    ? 
                                                   (((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                                                     << 0xdU) 
                                                    | ((((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0) 
                                                         << 0xcU) 
                                                        | (0x800U 
                                                           & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                              [
                                                              (0x3ffU 
                                                               & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                                  >> 2U))] 
                                                              << 4U))) 
                                                       | ((0x7e0U 
                                                           & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                              [
                                                              (0x3ffU 
                                                               & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                                  >> 2U))] 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                                [
                                                                (0x3ffU 
                                                                 & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                                    >> 2U))] 
                                                                >> 7U)))))
                                                    : 
                                                   (((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.tb__DOT__dut__DOT__instr_reg)) 
                                                     | (0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.tb__DOT__dut__DOT__instr_reg)))
                                                     ? 
                                                    (0xfffff000U 
                                                     & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                     [
                                                     (0x3ffU 
                                                      & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                         >> 2U))])
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.tb__DOT__dut__DOT__instr_reg))
                                                      ? 
                                                     (((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                                                       << 0x14U) 
                                                      | (((0xff000U 
                                                           & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                           [
                                                           (0x3ffU 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                               >> 2U))]) 
                                                          | (0x800U 
                                                             & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                                [
                                                                (0x3ffU 
                                                                 & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                                    >> 2U))] 
                                                                >> 9U))) 
                                                         | (0x7feU 
                                                            & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                               [
                                                               (0x3ffU 
                                                                & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                                   >> 2U))] 
                                                               >> 0x14U))))
                                                      : 0U)))));
    __Vfunc_instr_enum_from_val__0__instr = vlSelfRef.tb__DOT__dut__DOT__instr_reg;
    {
        if ((0x40U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((0x20U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((0x10U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 7U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x29U;
                                goto __Vlabel1;
                            } else if ((0x2000U == 
                                        (__Vfunc_instr_enum_from_val__0__instr 
                                         >> 7U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x2aU;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 3U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                              >> 0xcU)))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 4U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xaU;
                                    goto __Vlabel1;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 9U;
                                    goto __Vlabel1;
                                }
                            } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 8U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 7U;
                                goto __Vlabel1;
                            }
                        } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 6U;
                            goto __Vlabel1;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 5U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
        } else if ((0x20U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((0x10U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 1U;
                            goto __Vlabel1;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                    if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                                >> 0x19U))) {
                                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x25U;
                                        goto __Vlabel1;
                                    } else {
                                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                        goto __Vlabel1;
                                    }
                                } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                                   >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x24U;
                                    goto __Vlabel1;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel1;
                                }
                            } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x22U;
                                    goto __Vlabel1;
                                } else if ((0x20U == 
                                            (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x23U;
                                    goto __Vlabel1;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel1;
                                }
                            } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                               >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x21U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x20U;
                                    goto __Vlabel1;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel1;
                                }
                            } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                               >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1fU;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1eU;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                           >> 0x19U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1cU;
                            goto __Vlabel1;
                        } else if ((0x20U == (__Vfunc_instr_enum_from_val__0__instr 
                                              >> 0x19U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1dU;
                            goto __Vlabel1;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                      >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x10U;
                        goto __Vlabel1;
                    } else if ((1U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x11U;
                        goto __Vlabel1;
                    } else if ((2U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x12U;
                        goto __Vlabel1;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
        } else if ((0x10U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 2U;
                        goto __Vlabel1;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x18U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x17U;
                                goto __Vlabel1;
                            }
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1aU;
                                goto __Vlabel1;
                            } else if ((0x20U == (__Vfunc_instr_enum_from_val__0__instr 
                                                  >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1bU;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x16U;
                            goto __Vlabel1;
                        }
                    } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x15U;
                            goto __Vlabel1;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x14U;
                            goto __Vlabel1;
                        }
                    } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x19U;
                        goto __Vlabel1;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x13U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
        } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x1066000U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 7U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x27U;
                            goto __Vlabel1;
                        } else if ((0x20000U == (__Vfunc_instr_enum_from_val__0__instr 
                                                 >> 7U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x28U;
                            goto __Vlabel1;
                        } else if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                                 >> 0xcU)))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x26U;
                            goto __Vlabel1;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
        } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
            goto __Vlabel1;
        } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xfU;
                        goto __Vlabel1;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xeU;
                        goto __Vlabel1;
                    }
                } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xdU;
                        goto __Vlabel1;
                    }
                } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xcU;
                    goto __Vlabel1;
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xbU;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
        } else {
            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
            goto __Vlabel1;
        }
        __Vlabel1: ;
    }
    vlSelfRef.tb__DOT__dut__DOT__opcode_e = vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout;
    vlSelfRef.tb__DOT__dut__DOT__alu_src_a = ((2U == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                               ? vlSelfRef.tb__DOT__dut__DOT__pc
                                               : ((0U 
                                                   == (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rs1))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs
                                                  [vlSelfRef.tb__DOT__dut__DOT__instr_rs1]));
    __Vfunc_instr_type_enum_from_instr__1__instr_opcode 
        = vlSelfRef.tb__DOT__dut__DOT__opcode_e;
    {
        if (((((((((0U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                   | ((1U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                      || (2U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) 
                  | (3U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                 | (((((((((((((((4U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                                 || (0xbU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                || (0xcU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                               || (0xdU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                              || (0xeU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                             || (0xfU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                            || (0x13U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                           || (0x14U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                          || (0x15U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (0x16U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x17U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                       || (0x18U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                      || (0x19U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                     || (0x1aU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                    || (0x1bU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) 
                | ((((((5U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                       || (6U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                      || (7U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                     || (8U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                    || (9U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                   || (0xaU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) 
               | ((((((((((0x1cU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                          || (0x1dU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (0x1eU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x1fU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                       || (0x20U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                      || (0x21U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                     || (0x22U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                    || (0x23U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                   || (0x24U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                  || (0x25U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) 
              | (((0x10U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                  || (0x11U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                 || (0x12U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) 
             | (((0x26U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                 || (0x27U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                || (0x28U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)))) {
            if ((0U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 8U;
                goto __Vlabel2;
            } else if (((1U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                        || (2U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 4U;
                goto __Vlabel2;
            } else if ((3U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 5U;
                goto __Vlabel2;
            } else if ((((((((((((((((4U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                                     || (0xbU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                    || (0xcU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                   || (0xdU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                  || (0xeU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                 || (0xfU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                                || (0x13U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                               || (0x14U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                              || (0x15U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                             || (0x16U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                            || (0x17U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                           || (0x18U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                          || (0x19U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (0x1aU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x1bU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 1U;
                goto __Vlabel2;
            } else if (((((((5U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                            || (6U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                           || (7U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                          || (8U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (9U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0xaU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 3U;
                goto __Vlabel2;
            } else if (((((((((((0x1cU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                                || (0x1dU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                               || (0x1eU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                              || (0x1fU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                             || (0x20U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                            || (0x21U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                           || (0x22U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                          || (0x23U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (0x24U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x25U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 0U;
                goto __Vlabel2;
            } else if ((((0x10U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                         || (0x11U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x12U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 2U;
                goto __Vlabel2;
            } else {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 6U;
                goto __Vlabel2;
            }
        } else if (((0x29U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                    || (0x2aU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
            vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 7U;
            goto __Vlabel2;
        } else {
            vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 8U;
            goto __Vlabel2;
        }
        __Vlabel2: ;
    }
    vlSelfRef.tb__DOT__dut__DOT__instr_type = vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout;
    vlSelfRef.__VdfgRegularize_hd87f99a1_0_0 = ((0U 
                                                 == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                                | (1U 
                                                   == vlSelfRef.tb__DOT__dut__DOT__instr_type));
    vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11 
        = ((4U == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
           | (5U == vlSelfRef.tb__DOT__dut__DOT__instr_type));
    vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl 
        = ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0)
            ? (((0x1cU == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                | (0x13U == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                ? 0U : (((0x1dU == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                         | ((0x1fU == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                            | ((0x14U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                               | ((0x20U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                  | (0x15U == vlSelfRef.tb__DOT__dut__DOT__opcode_e)))))
                         ? 1U : (((0x25U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                  | (0x18U == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                  ? 2U : (((0x24U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                           | (0x17U 
                                              == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                           ? 3U : (
                                                   ((0x21U 
                                                     == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                    | (0x16U 
                                                       == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                                    ? 4U
                                                    : 
                                                   (((0x1eU 
                                                      == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                     | (0x19U 
                                                        == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                                     ? 5U
                                                     : 
                                                    (((0x22U 
                                                       == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                      | (0x1aU 
                                                         == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                                      ? 6U
                                                      : 
                                                     (((0x23U 
                                                        == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                       | (0x1bU 
                                                          == vlSelfRef.tb__DOT__dut__DOT__opcode_e))
                                                       ? 7U
                                                       : 0U))))))))
            : ((3U == vlSelfRef.tb__DOT__dut__DOT__instr_type)
                ? (((5U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                    | ((6U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                       | ((7U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                          | ((8U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                             | ((9U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                | (0xaU == vlSelfRef.tb__DOT__dut__DOT__opcode_e))))))
                    ? 1U : 0U) : 0U));
    vlSelfRef.tb__DOT__dut__DOT__alu_src_b = (((1U 
                                                == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                               | ((2U 
                                                   == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                                  | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11)))
                                               ? vlSelfRef.tb__DOT__dut__DOT__imm_value
                                               : vlSelfRef.tb__DOT__dut__DOT__rs2_data);
    vlSelfRef.tb__DOT__dut__DOT__alu_eq = ((1U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl) 
                                           & (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                                              == vlSelfRef.tb__DOT__dut__DOT__alu_src_b));
    vlSelfRef.tb__DOT__dut__DOT__alu_ltu = ((1U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl) 
                                            & (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                                               < vlSelfRef.tb__DOT__dut__DOT__alu_src_b));
    if (((((((((0U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl) 
               | (1U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
              | (2U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
             | (3U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
            | (4U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
           | (5U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
          | (6U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) 
         | (7U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl))) {
        if ((0U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) {
            vlSelfRef.tb__DOT__dut__DOT__alu_result 
                = (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                   + vlSelfRef.tb__DOT__dut__DOT__alu_src_b);
        } else if ((1U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)) {
            vlSelfRef.tb__DOT__dut__DOT__alu_result 
                = (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                   - vlSelfRef.tb__DOT__dut__DOT__alu_src_b);
            vlSelfRef.tb__DOT__dut__DOT__alu_lt = (
                                                   (1U 
                                                    == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl) 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                      >> 0x1fU));
            if (((0x1fU == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                 || (0x14U == vlSelfRef.tb__DOT__dut__DOT__opcode_e))) {
                vlSelfRef.tb__DOT__dut__DOT__alu_result 
                    = vlSelfRef.tb__DOT__dut__DOT__alu_lt;
            } else if (((0x20U == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                        || (0x15U == vlSelfRef.tb__DOT__dut__DOT__opcode_e))) {
                vlSelfRef.tb__DOT__dut__DOT__alu_result 
                    = vlSelfRef.tb__DOT__dut__DOT__alu_ltu;
            }
        } else {
            vlSelfRef.tb__DOT__dut__DOT__alu_result 
                = ((2U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)
                    ? (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                       & vlSelfRef.tb__DOT__dut__DOT__alu_src_b)
                    : ((3U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)
                        ? (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                           | vlSelfRef.tb__DOT__dut__DOT__alu_src_b)
                        : ((4U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)
                            ? (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                               ^ vlSelfRef.tb__DOT__dut__DOT__alu_src_b)
                            : ((5U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)
                                ? (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                                   << (0x1fU & vlSelfRef.tb__DOT__dut__DOT__alu_src_b))
                                : ((6U == vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl)
                                    ? (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                                       >> (0x1fU & vlSelfRef.tb__DOT__dut__DOT__alu_src_b))
                                    : (vlSelfRef.tb__DOT__dut__DOT__alu_src_a 
                                       >> (0x1fU & vlSelfRef.tb__DOT__dut__DOT__alu_src_b)))))));
        }
    } else {
        vlSelfRef.tb__DOT__dut__DOT__alu_result = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__mem_wstrb = (0xfU 
                                              & ((0x10U 
                                                  == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                  ? 
                                                 ((IData)(1U) 
                                                  << 
                                                  (3U 
                                                   & vlSelfRef.tb__DOT__dut__DOT__alu_result))
                                                  : 
                                                 ((0x11U 
                                                   == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                   ? 
                                                  VL_SHIFTL_III(4,4,32, (IData)(3U), 
                                                                ((IData)(1U) 
                                                                 + 
                                                                 (1U 
                                                                  & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                                     >> 1U))))
                                                   : 
                                                  ((0x12U 
                                                    == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                    ? 0xfU
                                                    : 0U))));
    vlSelfRef.tb__DOT__dut__DOT__mem_wdata = VL_SHIFTL_III(32,32,32, vlSelfRef.tb__DOT__dut__DOT__rs2_data, 
                                                           ((0x10U 
                                                             == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                             ? 
                                                            VL_SHIFTL_III(32,32,32, 
                                                                          (3U 
                                                                           & vlSelfRef.tb__DOT__dut__DOT__alu_result), 3U)
                                                             : 
                                                            ((0x11U 
                                                              == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                              ? 
                                                             VL_SHIFTL_III(32,32,32, 
                                                                           (1U 
                                                                            & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                                               >> 1U)), 4U)
                                                              : 0U)));
    if ((3U == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))) {
        tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4 
            = (0xffU & vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
               [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                           >> 2U))]);
        tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5 
            = (0xffffU & vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
               [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                           >> 2U))]);
    } else {
        tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4 = 0U;
        tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5 = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__regfile_wdata = ((0U 
                                                   == vlSelfRef.tb__DOT__dut__DOT__instr_type)
                                                   ? vlSelfRef.tb__DOT__dut__DOT__alu_result
                                                   : 
                                                  ((1U 
                                                    == vlSelfRef.tb__DOT__dut__DOT__instr_type)
                                                    ? 
                                                   ((4U 
                                                     == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.tb__DOT__dut__DOT__pc)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                       ? 
                                                      (((- (IData)(
                                                                   ((3U 
                                                                     == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2)) 
                                                                    & (vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                                                                       [
                                                                       (0x3ffU 
                                                                        & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                                           >> 2U))] 
                                                                       >> 7U)))) 
                                                        << 8U) 
                                                       | (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4))
                                                       : 
                                                      ((1U 
                                                        == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                        ? 
                                                       (((- (IData)(
                                                                    ((3U 
                                                                      == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2)) 
                                                                     & (vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                                                                        [
                                                                        (0x3ffU 
                                                                         & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                                            >> 2U))] 
                                                                        >> 0xfU)))) 
                                                         << 0x10U) 
                                                        | (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5))
                                                        : 
                                                       ((2U 
                                                         == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                         ? 
                                                        ((3U 
                                                          == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                                                          ? 
                                                         vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                                                         [
                                                         (0x3ffU 
                                                          & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                                             >> 2U))]
                                                          : 0U)
                                                         : 
                                                        ((4U 
                                                          == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                          ? (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_4)
                                                          : 
                                                         ((5U 
                                                           == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                           ? (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_5)
                                                           : 0U)))))
                                                      : 
                                                     ((0x13U 
                                                       == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                                                       ? vlSelfRef.tb__DOT__dut__DOT__alu_result
                                                       : 0U)))
                                                    : 
                                                   ((3U 
                                                     == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.tb__DOT__dut__DOT__pc)
                                                     : 
                                                    ((1U 
                                                      == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                      ? vlSelfRef.tb__DOT__dut__DOT__imm_value
                                                      : 
                                                     ((2U 
                                                       == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                       ? vlSelfRef.tb__DOT__dut__DOT__alu_result
                                                       : 0U)))));
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
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge rst_n)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge rst_n)\n");
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
    vlSelf->tb__DOT__deadbeef_written = 0;
    vlSelf->tb__DOT__cycle_count = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__pc_next = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__instr_reg = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__opcode_e = 0;
    vlSelf->tb__DOT__dut__DOT__instr_type = 0;
    vlSelf->tb__DOT__dut__DOT__instr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__instr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__instr_rd = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__regfile_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__imm_value = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__alu_eq = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__alu_lt = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__alu_ltu = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__alu_src_a = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__alu_src_b = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__mem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__dut__DOT__mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 = VL_RAND_RESET_I(7);
    vlSelf->tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb__DOT__dut__DOT__i_imem__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__dut__DOT__i_imem__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb__DOT__dut__DOT__rf_main__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0 = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl = 0;
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb__DOT__dut__DOT__i_dmem__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__VdfgRegularize_hd87f99a1_0_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_instr_enum_from_val__0__Vfuncout = 0;
    vlSelf->__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 0;
    vlSelf->__VdlyVal__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyDim0__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 = VL_RAND_RESET_I(5);
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v1 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v2 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v3 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v4 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v5 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v6 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v7 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v8 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v9 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v10 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v11 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v12 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v13 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v14 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v15 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v16 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v17 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v18 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v19 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v20 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v21 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v22 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v23 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v24 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v25 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v26 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v27 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v28 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v29 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v30 = 0;
    vlSelf->__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v31 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
