// 600f2378  FUN_600f2378  size=90 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   60099bb8 FUN_60099bb8
//   60099adc FUN_60099adc


void FUN_600f2378(char *param_1)

{
  if (*param_1 == '\0') {
    FUN_60099adc(param_1);
  }
  else {
    FUN_60099bb8(*param_1,(ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1]);
  }
  return;
}


