// 6006ab14  gatt_server__6006ab14  size=206 bytes
// src: gatt_server.cc
// --- callers ---
//   60069648 adapter__60069648
// --- callees ---
//   600d8bea FUN_600d8bea
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   6006a4d4 FUN_6006a4d4
//   600d8ac6 FUN_600d8ac6
//   600d37b8 FUN_600d37b8
//   600d3b24 FUN_600d3b24
//   60051120 FUN_60051120


/* src: gatt_server.cc */

void gatt_server__6006ab14
               (int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
               undefined2 param_5,undefined2 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  
  uVar1 = DAT_6006abe4;
  local_b8 = 0x7c;
  local_bc = DAT_6006abe4;
  FUN_600d3b3a(&uStack_b4);
  FUN_600d37ac(&uStack_b4,DAT_6006abe8);
  FUN_600d8bea(&uStack_b4,param_2);
  FUN_600d37ac(&uStack_b4,DAT_6006abec);
  FUN_600d8bea(&uStack_b4,param_3);
  FUN_600d37ac(&uStack_b4,DAT_6006abf0);
  FUN_600d8ac6(&uStack_b4,param_4);
  FUN_600d37ac(&uStack_b4,DAT_6006abf4);
  FUN_600d8ac6(&uStack_b4,param_5);
  FUN_600d37ac(&uStack_b4,DAT_6006abf8);
  FUN_600d8ac6(&uStack_b4,param_6);
  FUN_600d3b24(&local_bc);
  local_bc = CONCAT22(param_5,(short)param_4);
  local_b8 = *param_2;
  uStack_b4 = param_2[1];
  uStack_b0 = param_2[2];
  uStack_ac = param_2[3];
  local_a8 = param_2[4];
  local_a4 = *param_3;
  uStack_a0 = param_3[1];
  uStack_9c = param_3[2];
  uStack_98 = param_3[3];
  local_94 = param_3[4];
  uVar2 = FUN_6006a4d4(param_1 + 0xb10,param_6,&local_bc);
  if ((uVar2 & 0xff) != 0) {
    FUN_60051120(&local_bc,uVar1,0x81,uVar2);
    FUN_600d37ac(&uStack_b4,DAT_6006abfc);
    FUN_600d37b8(&local_bc);
  }
  return;
}


