// 600c1548  FUN_600c1548  size=42 bytes
// --- callers ---
//   600c0114 FUN_600c0114
//   600fbb14 FUN_600fbb14
//   600c0294 FUN_600c0294
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8


void FUN_600c1548(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1f2) = 0xd;
  iVar1 = FUN_600b1368(DAT_600c1574);
  if (iVar1 == 0) {
    FUN_600c15a8(0);
  }
  return;
}


