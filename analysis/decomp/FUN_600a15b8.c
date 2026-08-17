// 600a15b8  FUN_600a15b8  size=140 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---


void FUN_600a15b8(char *param_1)

{
  undefined1 local_14;
  char local_13;
  short local_12;
  short local_10;
  code *local_c;
  
  local_c = *(code **)(DAT_600a1644 + 0x700);
  *(undefined4 *)(DAT_600a1644 + 0x700) = 0;
  if (local_c != (code *)0x0) {
    local_14 = 2;
    local_13 = *param_1;
    if (local_13 == '\0') {
      local_12 = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
      local_10 = (ushort)(byte)param_1[4] * 0x100 + (ushort)(byte)param_1[3];
    }
    else {
      local_12 = 0;
      local_10 = 0;
    }
    (*local_c)(&local_14);
  }
  return;
}


