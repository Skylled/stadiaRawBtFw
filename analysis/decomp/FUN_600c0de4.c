// 600c0de4  FUN_600c0de4  size=44 bytes
// --- callers ---
//   600c15a8 FUN_600c15a8
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8


void FUN_600c0de4(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1f2) = 8;
  iVar1 = FUN_600b1368(DAT_600c0e10);
  if (iVar1 == 0) {
    FUN_600c15a8(0);
  }
  return;
}


