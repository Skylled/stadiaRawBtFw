// 600d2d94  FUN_600d2d94  size=38 bytes
// --- callers ---
// --- callees ---
//   600d15f8 FUN_600d15f8
//   600d168e thunk_FUN_600d1662
//   600d15e4 thunk_EXT_FUN_000080d8


undefined4 FUN_600d2d94(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(iVar2 + 0x148) = 0;
  *(undefined4 *)(iVar2 + 0x140) = 0;
  thunk_FUN_600d1662(uVar1);
  FUN_600d15f8(*(undefined4 *)(param_1 + 0x40));
  thunk_EXT_FUN_000080d8(param_1);
  return 0;
}


