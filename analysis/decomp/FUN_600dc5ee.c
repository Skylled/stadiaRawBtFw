// 600dc5ee  FUN_600dc5ee  size=110 bytes
// --- callers ---
//   600dc30e FUN_600dc30e
// --- callees ---
//   600dd6d2 FUN_600dd6d2
//   600dc5ba FUN_600dc5ba
//   600dd812 FUN_600dd812
//   600dc5a4 FUN_600dc5a4
//   600dd7fc FUN_600dd7fc
//   600dc5de FUN_600dc5de
//   600dc71a FUN_600dc71a
//   6013d310 thunk_EXT_FUN_0000b52a
//   6013d068 thunk_EXT_FUN_0000b52e


int FUN_600dc5ee(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x13d0);
  if (iVar1 != 0) {
    FUN_600dc5a4(iVar1);
    thunk_EXT_FUN_0000b52e(iVar1,0x1c);
  }
  FUN_600dc5ba(param_1 + 0x13c4);
  if (*(int *)(param_1 + 0x13b8) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_600dd812(param_1 + 0x13a8);
  FUN_600dc5de(param_1 + 0x139c);
  FUN_600dd7fc(param_1 + 0x4c);
  FUN_600dc5ba(param_1 + 0x40);
  FUN_600dd6d2(param_1 + 0x24);
  FUN_600dc71a(param_1 + 0x14);
  FUN_600dc71a(param_1 + 4);
  return param_1;
}


