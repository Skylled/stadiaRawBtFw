// 6005d9d0  gatt_server__6005d9d0  size=104 bytes
// src: gatt_server.h
// --- callers ---
//   60081ab4 gatt_server__60081ab4
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   600cbb14 FUN_600cbb14
//   601016f0 FUN_601016f0


/* src: gatt_server.h */

undefined1 gatt_server__6005d9d0(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_a8 [4];
  undefined *local_a4;
  undefined4 local_a0;
  undefined1 auStack_9c [144];
  undefined1 local_c;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 8) {
    local_a8[0] = 8;
    local_a4 = PTR_s_gatt_server_h_6005da38;
    local_a0 = 0x19;
    FUN_600d3b3a(auStack_9c);
    local_c = local_a8[0];
    uVar2 = FUN_600cbb14(local_a8);
    FUN_600d37ac(auStack_9c,uVar2);
    FUN_600d37ac(auStack_9c,PTR_LAB_6011c45c_1_6005da3c);
    FUN_600d37ac(auStack_9c,PTR_s_Insufficient_service_handles_ava_6005da40);
    uVar1 = local_c;
    FUN_601016f0(0x28,local_a4,local_a0,auStack_9c);
  }
  else {
    *(int *)(param_1 + 4) = iVar3 + 1;
    *(undefined4 *)(param_1 + iVar3 * 4 + 8) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}


