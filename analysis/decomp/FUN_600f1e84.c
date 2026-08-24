// 600f1e84  FUN_600f1e84  size=72 bytes
// --- callers ---
//   600a7d0c FUN_600a7d0c
//   600a7b44 FUN_600a7b44
// --- callees ---
//   600a3014 FUN_600a3014


bool FUN_600f1e84(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = *(undefined1 *)(param_1 + 0x50);
  *(undefined1 *)(param_1 + 0x50) = 3;
  iVar2 = FUN_600a3014(param_1 + 0x10,0,2,0,0);
  if (iVar2 != 1) {
    *(undefined1 *)(param_1 + 0x50) = uVar1;
  }
  return iVar2 == 1;
}


