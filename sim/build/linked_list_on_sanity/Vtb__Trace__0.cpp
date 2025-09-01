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
                      [5U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb__DOT__dut__DOT__instr_reg),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb__DOT__dut__DOT__opcode_e),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb__DOT__dut__DOT__instr_type),32);
        bufp->chgCData(oldp+3,(vlSelfRef.tb__DOT__dut__DOT__instr_rs1),5);
        bufp->chgCData(oldp+4,(vlSelfRef.tb__DOT__dut__DOT__instr_rs2),5);
        bufp->chgCData(oldp+5,(vlSelfRef.tb__DOT__dut__DOT__instr_rd),5);
        bufp->chgIData(oldp+6,(vlSelfRef.tb__DOT__dut__DOT__rs2_data),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb__DOT__dut__DOT__regfile_wdata),32);
        bufp->chgBit(oldp+8,(((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                              | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11))));
        bufp->chgIData(oldp+9,(vlSelfRef.tb__DOT__dut__DOT__imm_value),32);
        bufp->chgBit(oldp+10,(((1U == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                               | ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                                  | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11)))));
        bufp->chgIData(oldp+11,(vlSelfRef.tb__DOT__dut__DOT__alu_result),32);
        bufp->chgBit(oldp+12,(vlSelfRef.tb__DOT__dut__DOT__alu_eq));
        bufp->chgBit(oldp+13,(vlSelfRef.tb__DOT__dut__DOT__alu_lt));
        bufp->chgBit(oldp+14,(vlSelfRef.tb__DOT__dut__DOT__alu_ltu));
        bufp->chgIData(oldp+15,(vlSelfRef.tb__DOT__dut__DOT__alu_src_a),32);
        bufp->chgIData(oldp+16,(vlSelfRef.tb__DOT__dut__DOT__alu_src_b),32);
        bufp->chgCData(oldp+17,(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb),4);
        bufp->chgBit(oldp+18,((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)));
        bufp->chgBit(oldp+19,((3U == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))));
        bufp->chgIData(oldp+20,(vlSelfRef.tb__DOT__dut__DOT__mem_wdata),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl),32);
        bufp->chgSData(oldp+22,((0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                           >> 2U))),10);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+23,(vlSelfRef.tb__DOT__dut__DOT__pc),32);
        bufp->chgIData(oldp+24,(((IData)(4U) + vlSelfRef.tb__DOT__dut__DOT__pc)),32);
        bufp->chgSData(oldp+25,((0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                           >> 2U))),10);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+26,(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+29,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[1]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[2]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[3]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[4]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[5]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[6]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[7]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[8]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[9]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[10]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[11]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[12]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[13]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[14]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[15]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[16]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[17]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[18]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[19]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[20]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[21]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[22]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[23]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[24]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[25]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[26]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[27]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[28]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[29]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[30]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[31]),32);
    }
    bufp->chgBit(oldp+61,(vlSelfRef.clk));
    bufp->chgBit(oldp+62,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+63,(vlSelfRef.tb__DOT__deadbeef_written));
    bufp->chgIData(oldp+64,(vlSelfRef.tb__DOT__cycle_count),32);
    bufp->chgIData(oldp+65,(((0U == (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rs1))
                              ? 0U : vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs
                             [vlSelfRef.tb__DOT__dut__DOT__instr_rs1])),32);
    bufp->chgIData(oldp+66,(((3U == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                              ? vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                             [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                         >> 2U))] : 0U)),32);
    bufp->chgIData(oldp+67,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                              << 0xcU) | (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                          [(0x3ffU 
                                            & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                               >> 2U))] 
                                          >> 0x14U))),32);
    bufp->chgIData(oldp+68,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                              << 0xcU) | ((0xfe0U & 
                                           (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                            [(0x3ffU 
                                              & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                 >> 2U))] 
                                            >> 0x14U)) 
                                          | (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rd)))),32);
    bufp->chgIData(oldp+69,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                              << 0xdU) | ((((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0) 
                                            << 0xcU) 
                                           | (0x800U 
                                              & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                 [(0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                 << 4U))) 
                                          | ((0x7e0U 
                                              & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                 [(0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                 >> 0x14U)) 
                                             | (0x1eU 
                                                & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                                   [
                                                   (0x3ffU 
                                                    & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                       >> 2U))] 
                                                   >> 7U)))))),32);
    bufp->chgIData(oldp+70,((0xfffff000U & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                             [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                         >> 2U))])),32);
    bufp->chgIData(oldp+71,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                              << 0x14U) | (((0xff000U 
                                             & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                             [(0x3ffU 
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
                                                 [(0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                 >> 0x14U))))),32);
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
