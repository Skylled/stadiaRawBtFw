// 600afd28  FUN_600afd28  size=86 bytes
// --- callers ---
//   600f74a8 FUN_600f74a8
//   600ab620 FUN_600ab620
//   600f395a FUN_600f395a
//   600afdf8 FUN_600afdf8
//   600ab318 FUN_600ab318
//   600b05f0 FUN_600b05f0
//   600abb14 FUN_600abb14
//   600ab424 FUN_600ab424
//   600ab110 FUN_600ab110
//   600f3b0a FUN_600f3b0a
//   600f3caa FUN_600f3caa
//   600ab9b8 FUN_600ab9b8
//   600f6b96 FUN_600f6b96
//   600f3e00 FUN_600f3e00
//   600f3e6a FUN_600f3e6a
//   600f38d0 FUN_600f38d0
//   600f367e FUN_600f367e
//   600f39fc FUN_600f39fc
//   600ab778 FUN_600ab778
//   600f3c42 FUN_600f3c42
//   600f37d2 FUN_600f37d2
//   600f3ed6 FUN_600f3ed6
// --- callees ---


int FUN_600afd28(char param_1)

{
  int iVar1;
  
  if (((param_1 == '\0') ||
      (iVar1 = DAT_600afd80 + (uint)(byte)(param_1 - 1U) * 0x30 + 0x1068, 9 < (byte)(param_1 - 1U)))
     || (*(char *)(iVar1 + 0x2d) == '\0')) {
    iVar1 = 0;
  }
  return iVar1;
}


