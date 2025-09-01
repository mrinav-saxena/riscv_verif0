// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb__Syms.h"


VL_ATTR_COLD void Vtb___024root__trace_init_sub__TOP__0(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_sub__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"deadbeef_written",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+65,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"instr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"opcode_e",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+3,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+4,0,"instr_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"instr_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"instr_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+66,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"regfile_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"regfile_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"imm_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+11,0,"alu_imm_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+13,0,"alu_eq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"alu_lt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"alu_ltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"alu_src_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"alu_src_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"mem_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+19,0,"mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("alu_main", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+16,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+2,0,"opcode_e",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+12,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+13,0,"eq",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"lt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ltu",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"alu_ctrl",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_dmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+74,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+21,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+19,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+28,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_imem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+74,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+76,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+78,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+29,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+80,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("imm_gen_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"i_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"s_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"b_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"u_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"j_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rf_main", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+73,0,"N_REGS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+66,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+30+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb___024root__trace_init_top(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_top\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtb___024root__trace_register(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_register\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+73,(0x20U),32);
    bufp->fullIData(oldp+74,(0x400U),32);
    bufp->fullIData(oldp+75,(0xaU),32);
    bufp->fullIData(oldp+76,(0U),32);
    bufp->fullCData(oldp+77,(0U),4);
    bufp->fullBit(oldp+78,(0U));
    bufp->fullBit(oldp+79,(1U));
    bufp->fullIData(oldp+80,(vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk2__DOT__i),32);
    bufp->fullCData(oldp+81,(0xfU),4);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.tb__DOT__dut__DOT__instr_reg),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb__DOT__dut__DOT__opcode_e),32);
    bufp->fullIData(oldp+3,(vlSelfRef.tb__DOT__dut__DOT__instr_type),32);
    bufp->fullCData(oldp+4,(vlSelfRef.tb__DOT__dut__DOT__instr_rs1),5);
    bufp->fullCData(oldp+5,(vlSelfRef.tb__DOT__dut__DOT__instr_rs2),5);
    bufp->fullCData(oldp+6,(vlSelfRef.tb__DOT__dut__DOT__instr_rd),5);
    bufp->fullIData(oldp+7,(vlSelfRef.tb__DOT__dut__DOT__rs2_data),32);
    bufp->fullIData(oldp+8,(vlSelfRef.tb__DOT__dut__DOT__regfile_wdata),32);
    bufp->fullBit(oldp+9,(((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                           | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11))));
    bufp->fullIData(oldp+10,(vlSelfRef.tb__DOT__dut__DOT__imm_value),32);
    bufp->fullBit(oldp+11,(((1U == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                            | ((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type) 
                               | (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_11)))));
    bufp->fullIData(oldp+12,(vlSelfRef.tb__DOT__dut__DOT__alu_result),32);
    bufp->fullBit(oldp+13,(vlSelfRef.tb__DOT__dut__DOT__alu_eq));
    bufp->fullBit(oldp+14,(vlSelfRef.tb__DOT__dut__DOT__alu_lt));
    bufp->fullBit(oldp+15,(vlSelfRef.tb__DOT__dut__DOT__alu_ltu));
    bufp->fullIData(oldp+16,(vlSelfRef.tb__DOT__dut__DOT__alu_src_a),32);
    bufp->fullIData(oldp+17,(vlSelfRef.tb__DOT__dut__DOT__alu_src_b),32);
    bufp->fullCData(oldp+18,(vlSelfRef.tb__DOT__dut__DOT__mem_wstrb),4);
    bufp->fullBit(oldp+19,((2U == vlSelfRef.tb__DOT__dut__DOT__instr_type)));
    bufp->fullBit(oldp+20,((3U == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))));
    bufp->fullIData(oldp+21,(vlSelfRef.tb__DOT__dut__DOT__mem_wdata),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb__DOT__dut__DOT__alu_main__DOT__alu_ctrl),32);
    bufp->fullSData(oldp+23,((0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                        >> 2U))),10);
    bufp->fullIData(oldp+24,(vlSelfRef.tb__DOT__dut__DOT__pc),32);
    bufp->fullIData(oldp+25,(((IData)(4U) + vlSelfRef.tb__DOT__dut__DOT__pc)),32);
    bufp->fullSData(oldp+26,((0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                        >> 2U))),10);
    bufp->fullIData(oldp+27,(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+28,(vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+29,(vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+30,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[0]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[1]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[2]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[3]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[4]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[5]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[6]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[7]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[8]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[9]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[10]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[11]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[12]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[13]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[14]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[15]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[16]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[17]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[18]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[19]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[20]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[21]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[22]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[23]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[24]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[25]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[26]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[27]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[28]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[29]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[30]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs[31]),32);
    bufp->fullBit(oldp+62,(vlSelfRef.clk));
    bufp->fullBit(oldp+63,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+64,(vlSelfRef.tb__DOT__deadbeef_written));
    bufp->fullIData(oldp+65,(vlSelfRef.tb__DOT__cycle_count),32);
    bufp->fullIData(oldp+66,(((0U == (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rs1))
                               ? 0U : vlSelfRef.tb__DOT__dut__DOT__rf_main__DOT__regs
                              [vlSelfRef.tb__DOT__dut__DOT__instr_rs1])),32);
    bufp->fullIData(oldp+67,(((3U == (IData)(vlSelfRef.tb__DOT__dut__DOT____VdfgRegularize_hd1c0e5ba_0_2))
                               ? vlSelfRef.tb__DOT__dut__DOT__i_dmem__DOT__mem_array
                              [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__alu_result 
                                          >> 2U))] : 0U)),32);
    bufp->fullIData(oldp+68,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                               << 0xcU) | (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                           [(0x3ffU 
                                             & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                >> 2U))] 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+69,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                                               [(0x3ffU 
                                                 & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x14U)) 
                                           | (IData)(vlSelfRef.tb__DOT__dut__DOT__instr_rd)))),32);
    bufp->fullIData(oldp+70,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
                               << 0xdU) | ((((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0) 
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
                                                    >> 7U)))))),32);
    bufp->fullIData(oldp+71,((0xfffff000U & vlSelfRef.tb__DOT__dut__DOT__i_imem__DOT__mem_array
                              [(0x3ffU & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                          >> 2U))])),32);
    bufp->fullIData(oldp+72,((((- (IData)((IData)(vlSelfRef.tb__DOT__dut__DOT__imm_gen_inst__DOT____VdfgRegularize_hf91b520b_0_0))) 
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
                                                  [
                                                  (0x3ffU 
                                                   & (vlSelfRef.tb__DOT__dut__DOT__pc 
                                                      >> 2U))] 
                                                  >> 0x14U))))),32);
}
