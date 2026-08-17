// 6009b9b0  FUN_6009b9b0  size=76 bytes
// --- callers ---
//   6009ba0c FUN_6009ba0c
// --- callees ---
//   600b1368 FUN_600b1368
//   6009b8b4 FUN_6009b8b4
//   600f0f26 FUN_600f0f26
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_6009b9b0(int param_1)

{
  if ((param_1 != 0) && (*(short *)(param_1 + 2) == 0x2017)) {
    thunk_EXT_FUN_0000b572(DAT_6009b9fc,param_1 + 4,0x10);
    FUN_6009b8b4(1);
    if (*(char *)(DAT_6009ba00 + 0xa6a) != '\0') {
      FUN_600f0f26(DAT_6009ba04);
    }
  }
  FUN_600b1368(DAT_6009ba08);
  return;
}


