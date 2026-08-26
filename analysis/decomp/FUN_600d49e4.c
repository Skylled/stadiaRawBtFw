// 600d49e4  FUN_600d49e4  size=24 bytes
// --- callers ---
//   60060040 FUN_60060040
//   60060c70 FUN_60060c70
//   60060940 FUN_60060940
// --- callees ---


bool FUN_600d49e4(ushort *param_1)

{
  if (*param_1 - 0x50 < 10) {
    return true;
  }
  return *param_1 < 0x10;
}


