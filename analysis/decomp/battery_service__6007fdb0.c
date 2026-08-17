// 6007fdb0  battery_service__6007fdb0  size=100 bytes
// src: battery_service.cc
// --- callers ---
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600683f4 battery_charger_bq25601__600683f4
//   6010165c FUN_6010165c


/* src: battery_service.cc */

uint battery_service__6007fdb0(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = param_2;
  thunk_EXT_FUN_0000b4c2(param_1 + 300);
  if (*(byte *)(param_1 + 0x18c) == param_2) {
    uVar3 = 0;
  }
  else {
    puVar2 = PTR_s_Entering_6007fe18;
    if (param_2 == 0) {
      puVar2 = PTR_s_Exiting_6007fe14;
    }
    FUN_6010165c(0x14,PTR_s_battery_service_cc_6007fe1c,0x89,PTR_s__s_long_charge_mode_6007fe20,
                 puVar2,uVar3);
    uVar1 = 0x1004;
    if (param_2 == 0) {
      uVar1 = 0x10fe;
    }
    uVar3 = battery_charger_bq25601__600683f4(*(undefined4 *)(param_1 + 0xd0),uVar1);
    if ((uVar3 & 0xff) == 0) {
      *(char *)(param_1 + 0x18c) = (char)param_2;
    }
  }
  thunk_EXT_FUN_00007d10(param_1 + 300);
  return uVar3;
}


