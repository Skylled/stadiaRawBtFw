// 600c0ed4  FUN_600c0ed4  size=44 bytes
// --- callers ---
//   600fc302 FUN_600fc302
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8


void FUN_600c0ed4(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1f2) = 5;
  iVar1 = FUN_600b1368(DAT_600c0f00);
  if (iVar1 == 0) {
    FUN_600c15a8(0);
  }
  return;
}


