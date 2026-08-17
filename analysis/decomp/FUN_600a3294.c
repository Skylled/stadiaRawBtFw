// 600a3294  FUN_600a3294  size=54 bytes
// --- callers ---
//   600a74dc FUN_600a74dc
// --- callees ---
//   600a30f0 FUN_600a30f0
//   600a59d0 FUN_600a59d0


void FUN_600a3294(void)

{
  if (*(char *)(DAT_600a32cc + 0xb26) == '\0') {
    FUN_600a30f0(0,0,0,0x1f);
  }
  else {
    FUN_600a30f0(DAT_600a32d0,0,0,0x1f);
  }
  FUN_600a59d0(0,0,0x1f);
  return;
}


