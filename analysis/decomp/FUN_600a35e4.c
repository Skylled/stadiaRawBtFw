// 600a35e4  FUN_600a35e4  size=68 bytes
// --- callers ---
//   60094208 FUN_60094208
//   600941c4 FUN_600941c4
//   6009931c FUN_6009931c
// --- callees ---
//   600a3724 FUN_600a3724


undefined4 FUN_600a35e4(undefined4 param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600a3724(param_1);
  if (iVar1 == 4) {
    uVar2 = 7;
  }
  else {
    *param_2 = *(byte *)(iVar1 * 0x24 + DAT_600a3628 + 0x66c) & 0x7f;
    uVar2 = 0;
  }
  return uVar2;
}


