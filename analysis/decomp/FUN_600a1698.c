// 600a1698  FUN_600a1698  size=94 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---


void FUN_600a1698(undefined1 *param_1)

{
  undefined1 local_10;
  undefined1 local_f;
  short local_e;
  code *local_c;
  
  local_c = *(code **)(DAT_600a16f8 + 0x700);
  *(undefined4 *)(DAT_600a16f8 + 0x700) = 0;
  if (local_c != (code *)0x0) {
    local_10 = 4;
    local_f = *param_1;
    local_e = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
    (*local_c)(&local_10);
  }
  return;
}


