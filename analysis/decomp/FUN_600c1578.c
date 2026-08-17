// 600c1578  FUN_600c1578  size=42 bytes
// --- callers ---
//   600c15a8 FUN_600c15a8
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8


void FUN_600c1578(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1f2) = 0xe;
  iVar1 = FUN_600b1368(DAT_600c15a4);
  if (iVar1 == 0) {
    FUN_600c15a8(0);
  }
  return;
}


