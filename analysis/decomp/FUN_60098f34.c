// 60098f34  FUN_60098f34  size=78 bytes
// --- callers ---
//   60099584 FUN_60099584
//   600a3d8c FUN_600a3d8c
//   600999bc FUN_600999bc
//   60099cc0 FUN_60099cc0
//   600983f4 FUN_600983f4
//   60099adc FUN_60099adc
//   60099a1c FUN_60099a1c
//   60099d8c FUN_60099d8c
//   600994b8 FUN_600994b8
//   60099bb8 FUN_60099bb8
//   600a6b20 FUN_600a6b20
// --- callees ---


byte FUN_60098f34(short param_1)

{
  byte local_d;
  short *local_c;
  
  local_d = 0;
  for (local_c = DAT_60098f84;
      (local_d < 4 && (((char)local_c[0x94] == '\0' || (param_1 != *local_c))));
      local_c = local_c + 0xa6) {
    local_d = local_d + 1;
  }
  return local_d;
}


