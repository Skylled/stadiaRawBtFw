// 600c2b3c  FUN_600c2b3c  size=196 bytes
// --- callers ---
// --- callees ---
//   600f04e4 FUN_600f04e4
//   600efcfe FUN_600efcfe
//   600f16ae FUN_600f16ae
//   600945f8 FUN_600945f8
//   600f045e FUN_600f045e
//   6009470c FUN_6009470c


void FUN_600c2b3c(int param_1)

{
  int iVar1;
  byte local_9;
  
  iVar1 = FUN_600f045e(param_1 + 8,*(undefined1 *)(param_1 + 0xf));
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0xe) != '\0') {
      FUN_600f16ae(param_1 + 8);
      FUN_600945f8(0,param_1 + 8,0);
      FUN_6009470c(param_1 + 8);
    }
  }
  else {
    local_9 = 0;
    while ((local_9 < *(byte *)(DAT_600c2c00 + 0xe4) &&
           (iVar1 = FUN_600efcfe((uint)local_9 * 0x20 + DAT_600c2c00 + 4,param_1 + 8), iVar1 != 0)))
    {
      local_9 = local_9 + 1;
    }
    if ((local_9 != *(byte *)(DAT_600c2c00 + 0xe4)) && (*(char *)(param_1 + 0xe) != '\0')) {
      *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c2c00 + 0x1e) = 1;
    }
    FUN_600f04e4(param_1 + 8,*(undefined1 *)(param_1 + 0xf));
  }
  return;
}


