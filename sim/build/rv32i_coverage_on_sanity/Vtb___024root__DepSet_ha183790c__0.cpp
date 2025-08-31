// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                             38);
        if (VL_UNLIKELY(((0xdeadbeefU == vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                          [0U])))) {
            VL_WRITEF_NX("[TB] Data memory completion signal detected at time %t\n",0,
                         64,VL_TIME_UNITED_Q(1),-12);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 43);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 43);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 43);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 43);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 43);
            VL_FINISH_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\\tb.sv", 44, "");
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                             26);
        if (VL_UNLIKELY(((0x100073U == vlSelfRef.tb__DOT__dut__DOT__instr_reg)))) {
            VL_WRITEF_NX("[TB] ebreak instruction detected at time %t - test completed!\n",0,
                         64,VL_TIME_UNITED_Q(1),-12);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 30);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 30);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 30);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 30);
            co_await vlSelfRef.__VtrigSched_hf87a9c37__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                                 30);
            VL_FINISH_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\\tb.sv", 31, "");
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VtrigSched_h96aaa0a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge rst_n)", 
                                                         "C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\tb.sv", 
                                                         50);
    VL_READMEM_N(true, 32, 1024, 0, std::string{"imem.hex"}
                 ,  &(vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 1024, 0, std::string{"dmem.hex"}
                 ,  &(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array)
                 , 0, ~0ULL);
    VL_WRITEF_NX("[TB] Loaded imem.hex and dmem.hex\n",0);
}

void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2;
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 = 0;
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
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 
        = (0x7fU & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
           [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                       >> 2U))]);
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3 
        = (7U & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                 [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                             >> 2U))] >> 0xcU));
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
                                                  | ((3U 
                                                      == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                                     | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11))))
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
    if ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)) {
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
                                                      == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                       ? 
                                                      (((- (IData)(
                                                                   ((2U 
                                                                     == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
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
                                                                    ((2U 
                                                                      == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
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
                                                        ((2U 
                                                          == vlSelfRef.tb__DOT__dut__DOT__instr_type)
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
                                                       == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
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
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
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
    IData/*31:0*/ __Vtemp_1;
    // Body
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v1 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v2 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v3 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v4 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v5 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v6 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v7 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v8 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v9 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v10 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v11 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v12 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v13 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v14 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v15 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v16 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v17 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v18 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v19 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v20 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v21 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v22 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v23 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v24 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v25 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v26 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v27 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v28 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v29 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v30 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v31 = 0U;
    vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v1 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v2 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v3 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v4 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v5 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v6 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v7 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v8 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v9 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v10 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v11 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v12 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v13 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v14 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v15 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v16 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v17 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v18 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v19 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v20 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v21 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v22 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v23 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v24 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v25 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v26 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v27 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v28 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v29 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v30 = 1U;
        vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v31 = 1U;
    }
    __Vtemp_1 = ((IData)(vlSelfRef.rst_n) ? ((3U == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                              ? (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                 + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                              : ((4U 
                                                  == vlSelfRef.tb__DOT__dut__DOT__opcode_e)
                                                  ? vlSelfRef.tb__DOT__dut__DOT__alu_result
                                                  : 
                                                 (((5U 
                                                    == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_eq))
                                                   ? 
                                                  (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                   + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                   : 
                                                  (((6U 
                                                     == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                    & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_eq)))
                                                    ? 
                                                   (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                    + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                    : 
                                                   (((7U 
                                                      == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_lt))
                                                     ? 
                                                    (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                     + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                     : 
                                                    (((8U 
                                                       == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                      & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_lt)))
                                                      ? 
                                                     (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                      : 
                                                     (((9U 
                                                        == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_ltu))
                                                       ? 
                                                      (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                       + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                       : 
                                                      (((0xaU 
                                                         == vlSelfRef.tb__DOT__dut__DOT__opcode_e) 
                                                        & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__alu_ltu)))
                                                        ? 
                                                       (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                        + vlSelfRef.tb__DOT__dut__DOT__imm_value)
                                                        : vlSelfRef.tb__DOT__dut__DOT__pc_next))))))))
                  : 0U);
    vlSelfRef.tb__DOT__dut__DOT__pc = __Vtemp_1;
    vlSelfRef.tb__DOT__dut__DOT__pc_next = ((IData)(4U) 
                                            + vlSelfRef.tb__DOT__dut__DOT__pc);
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_imem__DOT__mem_array__v0;
    __VdlyDim0__tb__DOT__dut__DOT__i_imem__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0;
    __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1;
    __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2;
    __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 = 0;
    IData/*31:0*/ __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3;
    __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 = 0;
    SData/*9:0*/ __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v4;
    __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v4 = 0;
    // Body
    if (vlSelfRef.rst_n) {
        if ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)) {
            vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk2__DOT__j = 4U;
        }
    }
    if (vlSelfRef.rst_n) {
        if ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)) {
            if ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb))) {
                __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 
                    = (0xffU & vlSelfRef.tb__DOT__dut__DOT__mem_wdata);
                __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                 >> 2U));
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 = 0U;
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0 
                    = ((0xffffff00U & __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0) 
                       | (IData)(__VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0));
                vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0, 0xffU, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v0));
            }
            if ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb))) {
                __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 
                    = (0xffU & (vlSelfRef.tb__DOT__dut__DOT__mem_wdata 
                                >> 8U));
                __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                 >> 2U));
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 = 0U;
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1 
                    = ((0xffff00ffU & __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1) 
                       | ((IData)(__VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1) 
                          << 8U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1, 0xff00U, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v1));
            }
            if ((4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb))) {
                __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 
                    = (0xffU & (vlSelfRef.tb__DOT__dut__DOT__mem_wdata 
                                >> 0x10U));
                __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                 >> 2U));
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 = 0U;
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2 
                    = ((0xff00ffffU & __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2) 
                       | ((IData)(__VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2) 
                          << 0x10U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2, 0xff0000U, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v2));
            }
            if ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb))) {
                __VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 
                    = (vlSelfRef.tb__DOT__dut__DOT__mem_wdata 
                       >> 0x18U);
                __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 
                    = (0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                 >> 2U));
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 = 0U;
                __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3 
                    = ((0xffffffU & __VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3) 
                       | ((IData)(__VdlyVal__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3) 
                          << 0x18U));
                vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.enqueue(__VdlyElem__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3, 0xff000000U, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v3));
            }
        }
    } else {
        vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x400U, vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v4 
                = (0x3ffU & vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.enqueue(0U, 0xffffffffU, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_dmem__DOT__mem_array__v4));
            vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x400U, vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__tb__DOT__dut__DOT__i_imem__DOT__mem_array__v0 
                = (0x3ffU & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_imem__DOT__mem_array.enqueue(0U, (IData)(__VdlyDim0__tb__DOT__dut__DOT__i_imem__DOT__mem_array__v0));
            vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i);
        }
    }
    if (vlSelfRef.rst_n) {
        if ((((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
              | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11)) 
             & (0U != (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rd)))) {
            vlSelfRef.__VdlyVal__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 
                = vlSelfRef.tb__DOT__dut__DOT__regfile_wdata;
            vlSelfRef.__VdlyDim0__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 
                = vlSelfRef.tb__DOT__dut__DOT__instr_rd;
            vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v0 = 1U;
        }
    }
    vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_dmem__DOT__mem_array.commit(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array);
    vlSelfRef.__VdlyCommitQueuetb__DOT__dut__DOT__i_imem__DOT__mem_array.commit(vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array);
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v0) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[vlSelfRef.__VdlyDim0__tb__DOT__dut__DOT__rf_main__DOT__regs__v0] 
            = vlSelfRef.__VdlyVal__tb__DOT__dut__DOT__rf_main__DOT__regs__v0;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v1) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v2) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v3) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v4) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[4U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v5) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[5U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v6) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v7) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v8) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[8U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v9) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[9U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v10) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xaU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v11) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xbU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v12) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xcU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v13) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xdU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v14) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xeU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v15) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0xfU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v16) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x10U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v17) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x11U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v18) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x12U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v19) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x13U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v20) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x14U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v21) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v22) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x16U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v23) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x17U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v24) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x18U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v25) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x19U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v26) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1aU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v27) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1bU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v28) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1cU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v29) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1dU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v30) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1eU] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb__DOT__dut__DOT__rf_main__DOT__regs__v31) {
        vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0x1fU] = 0U;
    }
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2;
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 = 0;
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
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2 
        = (0x7fU & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
           [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                       >> 2U))]);
    tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3 
        = (7U & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                 [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                             >> 2U))] >> 0xcU));
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
                        goto __Vlabel3;
                    } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 7U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x29U;
                                goto __Vlabel3;
                            } else if ((0x2000U == 
                                        (__Vfunc_instr_enum_from_val__0__instr 
                                         >> 7U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x2aU;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 3U;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                              >> 0xcU)))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 4U;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xaU;
                                    goto __Vlabel3;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 9U;
                                    goto __Vlabel3;
                                }
                            } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 8U;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 7U;
                                goto __Vlabel3;
                            }
                        } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 6U;
                            goto __Vlabel3;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 5U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            }
        } else if ((0x20U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((0x10U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 1U;
                            goto __Vlabel3;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                    if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                                >> 0x19U))) {
                                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x25U;
                                        goto __Vlabel3;
                                    } else {
                                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                        goto __Vlabel3;
                                    }
                                } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                                   >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x24U;
                                    goto __Vlabel3;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel3;
                                }
                            } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x22U;
                                    goto __Vlabel3;
                                } else if ((0x20U == 
                                            (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x23U;
                                    goto __Vlabel3;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel3;
                                }
                            } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                               >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x21U;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 0x19U))) {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x20U;
                                    goto __Vlabel3;
                                } else {
                                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                    goto __Vlabel3;
                                }
                            } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                               >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1fU;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1eU;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                           >> 0x19U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1cU;
                            goto __Vlabel3;
                        } else if ((0x20U == (__Vfunc_instr_enum_from_val__0__instr 
                                              >> 0x19U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1dU;
                            goto __Vlabel3;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                      >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x10U;
                        goto __Vlabel3;
                    } else if ((1U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x11U;
                        goto __Vlabel3;
                    } else if ((2U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                             >> 0xcU)))) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x12U;
                        goto __Vlabel3;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            }
        } else if ((0x10U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 2U;
                        goto __Vlabel3;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x18U;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x17U;
                                goto __Vlabel3;
                            }
                        } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            if ((0U == (__Vfunc_instr_enum_from_val__0__instr 
                                        >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1aU;
                                goto __Vlabel3;
                            } else if ((0x20U == (__Vfunc_instr_enum_from_val__0__instr 
                                                  >> 0x19U))) {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x1bU;
                                goto __Vlabel3;
                            } else {
                                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                                goto __Vlabel3;
                            }
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x16U;
                            goto __Vlabel3;
                        }
                    } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x15U;
                            goto __Vlabel3;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x14U;
                            goto __Vlabel3;
                        }
                    } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x19U;
                        goto __Vlabel3;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x13U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            }
        } else if ((8U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                        if ((0x1066000U == (__Vfunc_instr_enum_from_val__0__instr 
                                            >> 7U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x27U;
                            goto __Vlabel3;
                        } else if ((0x20000U == (__Vfunc_instr_enum_from_val__0__instr 
                                                 >> 7U))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x28U;
                            goto __Vlabel3;
                        } else if ((0U == (7U & (__Vfunc_instr_enum_from_val__0__instr 
                                                 >> 0xcU)))) {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0x26U;
                            goto __Vlabel3;
                        } else {
                            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                    goto __Vlabel3;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            }
        } else if ((4U & __Vfunc_instr_enum_from_val__0__instr)) {
            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
            goto __Vlabel3;
        } else if ((2U & __Vfunc_instr_enum_from_val__0__instr)) {
            if ((1U & __Vfunc_instr_enum_from_val__0__instr)) {
                if ((0x4000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xfU;
                        goto __Vlabel3;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xeU;
                        goto __Vlabel3;
                    }
                } else if ((0x2000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                        goto __Vlabel3;
                    } else {
                        vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xdU;
                        goto __Vlabel3;
                    }
                } else if ((0x1000U & __Vfunc_instr_enum_from_val__0__instr)) {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xcU;
                    goto __Vlabel3;
                } else {
                    vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0xbU;
                    goto __Vlabel3;
                }
            } else {
                vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
                goto __Vlabel3;
            }
        } else {
            vlSelfRef.__Vfunc_instr_enum_from_val__0__Vfuncout = 0U;
            goto __Vlabel3;
        }
        __Vlabel3: ;
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
                goto __Vlabel4;
            } else if (((1U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                        || (2U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 4U;
                goto __Vlabel4;
            } else if ((3U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 5U;
                goto __Vlabel4;
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
                goto __Vlabel4;
            } else if (((((((5U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                            || (6U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                           || (7U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                          || (8U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                         || (9U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0xaU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 3U;
                goto __Vlabel4;
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
                goto __Vlabel4;
            } else if ((((0x10U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                         || (0x11U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode)) 
                        || (0x12U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 2U;
                goto __Vlabel4;
            } else {
                vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 6U;
                goto __Vlabel4;
            }
        } else if (((0x29U == __Vfunc_instr_type_enum_from_instr__1__instr_opcode) 
                    || (0x2aU == __Vfunc_instr_type_enum_from_instr__1__instr_opcode))) {
            vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 7U;
            goto __Vlabel4;
        } else {
            vlSelfRef.__Vfunc_instr_type_enum_from_instr__1__Vfuncout = 8U;
            goto __Vlabel4;
        }
        __Vlabel4: ;
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
                                                  | ((3U 
                                                      == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                                     | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11))))
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
    if ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)) {
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
                                                      == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_3))
                                                       ? 
                                                      (((- (IData)(
                                                                   ((2U 
                                                                     == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
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
                                                                    ((2U 
                                                                      == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
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
                                                        ((2U 
                                                          == vlSelfRef.tb__DOT__dut__DOT__instr_type)
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
                                                       == (IData)(tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
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

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf87a9c37__0.resume(
                                                   "@(posedge clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h96aaa0a4__0.resume(
                                                   "@(posedge rst_n)");
    }
}

void Vtb___024root___timing_commit(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_commit\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf87a9c37__0.commit(
                                                   "@(posedge clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h96aaa0a4__0.commit(
                                                   "@(posedge rst_n)");
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
    Vtb___024root___timing_commit(vlSelf);
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
            VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\\tb.sv", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("C:/Users/DELL/OneDrive/Documents/projects/riscv_verif0/tb/sanity\\tb.sv", 1, "", "Active region did not converge.");
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
