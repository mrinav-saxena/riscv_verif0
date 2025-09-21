`ifndef STAL4MEM_PIP_STATE_ENUMS_SV
`define STAL4MEM_PIP_STATE_ENUMS_SV

typedef enum {group_UJ, group_B, group_RI_nonload, group_I_load, group_S, group_UNKNOWN} instr_group_e ;
typedef enum {ReqInstr, Wait4Instr, StallInstr} ifidex_state_e ;
typedef enum {Idle, Wait4DataWrite, Wait4ReadData} dmem_state_e ;

`endif