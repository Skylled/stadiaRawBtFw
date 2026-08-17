// 600c0c84  FUN_600c0c84  size=44 bytes
// --- callers ---
//   600bffe8 FUN_600bffe8
//   600c0114 FUN_600c0114
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8


void FUN_600c0c84(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1f2) = 6;
  iVar1 = FUN_600b1368(DAT_600c0cb0);
  if (iVar1 == 0) {
    FUN_600c15a8(0);
  }
  return;
}


