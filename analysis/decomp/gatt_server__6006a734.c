// 6006a734  gatt_server__6006a734  size=70 bytes
// src: gatt_server.h
// --- callers ---
//   6006ae20 gatt_server__6006ae20
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


/* src: gatt_server.h */

void gatt_server__6006a734(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [148];
  
  if (600 < param_3) {
    local_a8 = DAT_6006a77c;
    local_a4 = 0x5b;
    FUN_600d3b3a(auStack_a0);
    FUN_600d37ac(auStack_a0,DAT_6006a780);
    FUN_60101740(&local_a8);
  }
  *(undefined1 *)(param_1 + 4) = 1;
  *(short *)(param_1 + 2) = (short)param_3;
  thunk_EXT_FUN_0000b572(param_1 + 5,param_2,param_3);
  return;
}


