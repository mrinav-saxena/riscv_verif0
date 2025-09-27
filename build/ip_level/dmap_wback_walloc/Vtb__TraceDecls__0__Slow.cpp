// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vtb___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"CacheReady", "Wait4ReadData", "Wait4WriteData", 
                                "Stall4WB", "Cleanup"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100"};
        tracep->declDTypeEnum(1, "dmap_wback_walloc.cache_state_e", 5, 32, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"WBReady", "Wait4WB"};
        const char* __VenumItemValues[]
        = {"0", "1"};
        tracep->declDTypeEnum(2, "dmap_wback_walloc.wb_state_e", 2, 32, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"Idle", "GettingRdata", "ProcessingWdata", 
                                "Ready"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(3, "mem_nzlat.state_e", 4, 32, __VenumItemNames, __VenumItemValues);
    }
}

void Vtb___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtb___024root__traceDeclTypesSub0(tracep);
}
