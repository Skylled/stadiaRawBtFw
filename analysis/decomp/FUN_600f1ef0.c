// 600f1ef0  FUN_600f1ef0  size=48 bytes
// --- callers ---
//   600a7b44 FUN_600a7b44
// --- callees ---
//   600b26d0 FUN_600b26d0


bool FUN_600f1ef0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600b26d0(*(undefined2 *)(param_1 + 0xc),1);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  return iVar1 != 0;
}


