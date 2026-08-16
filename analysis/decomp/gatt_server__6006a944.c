// 6006a944  gatt_server__6006a944  size=124 bytes
// src: gatt_server.cc
// --- callers ---
// --- callees ---
//   600d8bea FUN_600d8bea
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   6006a5c8 gatt_server__6006a5c8
//   600d3b24 FUN_600d3b24
//   60095690 FUN_60095690
//   600d8ae8 FUN_600d8ae8


/* src: gatt_server.cc */

uint gatt_server__6006a944(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  ushort local_aa;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  local_a8 = DAT_6006a9c0;
  local_a4 = 0x13d;
  FUN_600d3b3a(auStack_a0);
  FUN_600d37ac(auStack_a0,DAT_6006a9c4);
  FUN_600d8bea(auStack_a0,*(undefined4 *)(param_2 + 4));
  FUN_600d3b24(&local_a8);
  uVar1 = FUN_600d8ae8(param_1,*(undefined4 *)(param_2 + 4),&local_aa);
  if ((uVar1 & 0xff) == 0) {
    iVar2 = (uint)local_aa * 0x11c + param_1;
    *(undefined4 *)(iVar2 + 0x348) = 0;
    *(int *)(iVar2 + 0x244) = param_2;
    gatt_server__6006a5c8(&local_a8,*(undefined4 *)(param_2 + 4));
    FUN_60095690(*(undefined1 *)(param_1 + 0x22c),&local_a8,(undefined1)local_aa,
                 *(undefined2 *)(param_2 + 0xc),1);
    *(ushort *)(param_2 + 8) = local_aa;
  }
  return uVar1;
}


