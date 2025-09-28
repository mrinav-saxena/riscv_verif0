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
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+68,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+68,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+69,0,"DMEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+70,0,"CACHE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"deadbeef_written",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+67,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("tc_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+5,0,"core_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+6,0,"core_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+7,0,"core_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+8,0,"core_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBit(c+9,0,"core_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+72,0,"core_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+14,0,"core_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+10,0,"cleanup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+15,0,"dmem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBus(c+27,0,"dmem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+28,0,"dmem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+29,0,"dmem_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBit(c+16,0,"dmem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+30,0,"dmem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+17,0,"dmem_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+11,0,"cache_mem_fh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("i_dcache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+68,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+68,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+70,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"core_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"core_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"core_write_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"core_wstrb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+9,0,"core_read_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"core_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"core_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"cleanup_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"dmem_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"dmem_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"dmem_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"dmem_wstrb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+16,0,"dmem_read_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"dmem_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+17,0,"dmem_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("dirty", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+35+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("tag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+39+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,4);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mem_array", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+43+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+12,0,"index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+18,0,"cache_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"perform_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+47,0,"latched_core_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,4);
    tracep->declBus(c+48,0,"latched_core_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+49,0,"latched_core_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"latched_core_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+51,0,"latched_core_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"writeback_buffer_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"writeback_buffer_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"writeback_buffer_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+76,0,"writeback_buffer_valid_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"writeback_buffer_valid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"curr_cache_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"next_cache_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+53,0,"curr_wb_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+22,0,"next_wb_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+54,0,"j_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+55,0,"j_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_dmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+68,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+69,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+77,0,"READ_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+77,0,"WRITE_LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+78,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+27,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+28,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+17,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"curr_state",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+24,0,"next_state",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+57,0,"read_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+25,0,"read_counter_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+58,0,"write_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+26,0,"write_counter_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+59,0,"latched_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+60,0,"latched_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"latched_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+62,0,"latched_operation",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+63,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+64,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    bufp->fullIData(oldp+68,(0x20U),32);
    bufp->fullIData(oldp+69,(0x400U),32);
    bufp->fullIData(oldp+70,(4U),32);
    bufp->fullBit(oldp+71,(0U));
    bufp->fullIData(oldp+72,(0U),32);
    bufp->fullIData(oldp+73,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_addr),32);
    bufp->fullIData(oldp+74,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wdata),32);
    bufp->fullCData(oldp+75,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_wstrb),4);
    bufp->fullBit(oldp+76,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_r));
    bufp->fullIData(oldp+77,(5U),32);
    bufp->fullIData(oldp+78,(0xaU),32);
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
    bufp->fullIData(oldp+1,(vlSelfRef.tb__DOT__tc_addr[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb__DOT__tc_addr[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.tb__DOT__tc_addr[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.tb__DOT__tc_addr[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.tb__DOT__core_addr),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb__DOT__core_wdata),32);
    bufp->fullBit(oldp+7,(vlSelfRef.tb__DOT__core_write));
    bufp->fullCData(oldp+8,(vlSelfRef.tb__DOT__core_wstrb),4);
    bufp->fullBit(oldp+9,(vlSelfRef.tb__DOT__core_read));
    bufp->fullBit(oldp+10,(vlSelfRef.tb__DOT__cleanup));
    bufp->fullIData(oldp+11,(vlSelfRef.tb__DOT__cache_mem_fh),32);
    bufp->fullCData(oldp+12,((3U & (vlSelfRef.tb__DOT__core_addr 
                                    >> 2U))),2);
    bufp->fullIData(oldp+13,(vlSelfRef.tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+14,(vlSelfRef.tb__DOT__core_ready));
    bufp->fullIData(oldp+15,(vlSelfRef.tb__DOT__dmem_addr),32);
    bufp->fullBit(oldp+16,(vlSelfRef.tb__DOT__dmem_read));
    bufp->fullBit(oldp+17,(vlSelfRef.tb__DOT__dmem_ready));
    bufp->fullBit(oldp+18,(vlSelfRef.tb__DOT__i_dcache__DOT__cache_hit));
    bufp->fullBit(oldp+19,(vlSelfRef.tb__DOT__i_dcache__DOT__perform_write));
    bufp->fullBit(oldp+20,(vlSelfRef.tb__DOT__i_dcache__DOT__writeback_buffer_valid_next));
    bufp->fullIData(oldp+21,(vlSelfRef.tb__DOT__i_dcache__DOT__next_cache_state),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb__DOT__i_dcache__DOT__next_wb_state),32);
    bufp->fullSData(oldp+23,((0x3ffU & (vlSelfRef.tb__DOT__dmem_addr 
                                        >> 2U))),10);
    bufp->fullIData(oldp+24,(vlSelfRef.tb__DOT__i_dmem__DOT__next_state),32);
    bufp->fullCData(oldp+25,(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter_next),4);
    bufp->fullCData(oldp+26,(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter_next),4);
    bufp->fullIData(oldp+27,(vlSelfRef.tb__DOT__dmem_wdata),32);
    bufp->fullBit(oldp+28,(vlSelfRef.tb__DOT__dmem_write));
    bufp->fullCData(oldp+29,(vlSelfRef.tb__DOT__dmem_wstrb),4);
    bufp->fullIData(oldp+30,(vlSelfRef.tb__DOT__dmem_rdata),32);
    bufp->fullBit(oldp+31,(vlSelfRef.tb__DOT__i_dcache__DOT__valid[0]));
    bufp->fullBit(oldp+32,(vlSelfRef.tb__DOT__i_dcache__DOT__valid[1]));
    bufp->fullBit(oldp+33,(vlSelfRef.tb__DOT__i_dcache__DOT__valid[2]));
    bufp->fullBit(oldp+34,(vlSelfRef.tb__DOT__i_dcache__DOT__valid[3]));
    bufp->fullBit(oldp+35,(vlSelfRef.tb__DOT__i_dcache__DOT__dirty[0]));
    bufp->fullBit(oldp+36,(vlSelfRef.tb__DOT__i_dcache__DOT__dirty[1]));
    bufp->fullBit(oldp+37,(vlSelfRef.tb__DOT__i_dcache__DOT__dirty[2]));
    bufp->fullBit(oldp+38,(vlSelfRef.tb__DOT__i_dcache__DOT__dirty[3]));
    bufp->fullIData(oldp+39,(vlSelfRef.tb__DOT__i_dcache__DOT__tag[0]),28);
    bufp->fullIData(oldp+40,(vlSelfRef.tb__DOT__i_dcache__DOT__tag[1]),28);
    bufp->fullIData(oldp+41,(vlSelfRef.tb__DOT__i_dcache__DOT__tag[2]),28);
    bufp->fullIData(oldp+42,(vlSelfRef.tb__DOT__i_dcache__DOT__tag[3]),28);
    bufp->fullIData(oldp+43,(vlSelfRef.tb__DOT__i_dcache__DOT__mem_array[0]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.tb__DOT__i_dcache__DOT__mem_array[1]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.tb__DOT__i_dcache__DOT__mem_array[2]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.tb__DOT__i_dcache__DOT__mem_array[3]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.tb__DOT__i_dcache__DOT__latched_core_tag),28);
    bufp->fullCData(oldp+48,(vlSelfRef.tb__DOT__i_dcache__DOT__latched_core_index),2);
    bufp->fullIData(oldp+49,(vlSelfRef.tb__DOT__i_dcache__DOT__latched_core_wdata),32);
    bufp->fullCData(oldp+50,(vlSelfRef.tb__DOT__i_dcache__DOT__latched_core_wstrb),4);
    bufp->fullBit(oldp+51,(vlSelfRef.tb__DOT__i_dcache__DOT__latched_core_write));
    bufp->fullIData(oldp+52,(vlSelfRef.tb__DOT__i_dcache__DOT__curr_cache_state),32);
    bufp->fullIData(oldp+53,(vlSelfRef.tb__DOT__i_dcache__DOT__curr_wb_state),32);
    bufp->fullIData(oldp+54,(vlSelfRef.tb__DOT__i_dcache__DOT__unnamedblk1__DOT__j_byte),32);
    bufp->fullIData(oldp+55,(vlSelfRef.tb__DOT__i_dcache__DOT__unnamedblk2__DOT__j_byte),32);
    bufp->fullIData(oldp+56,(vlSelfRef.tb__DOT__i_dmem__DOT__curr_state),32);
    bufp->fullCData(oldp+57,(vlSelfRef.tb__DOT__i_dmem__DOT__read_counter),4);
    bufp->fullCData(oldp+58,(vlSelfRef.tb__DOT__i_dmem__DOT__write_counter),4);
    bufp->fullSData(oldp+59,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_addr),10);
    bufp->fullIData(oldp+60,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wdata),32);
    bufp->fullCData(oldp+61,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_wstrb),4);
    bufp->fullBit(oldp+62,(vlSelfRef.tb__DOT__i_dmem__DOT__latched_operation));
    bufp->fullIData(oldp+63,(vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+64,(vlSelfRef.tb__DOT__i_dmem__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+65,(vlSelfRef.clk));
    bufp->fullBit(oldp+66,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+67,(vlSelfRef.tb__DOT__cycle_count),32);
}
