// 6009506c  FUN_6009506c  size=74 bytes
// --- callers ---
//   600ee9f6 FUN_600ee9f6
//   60094dc4 FUN_60094dc4
//   600ee89c FUN_600ee89c
//   600feba8 FUN_600feba8
//   600ef44c FUN_600ef44c
//   600c68fc FUN_600c68fc
//   60094ba4 FUN_60094ba4
//   60094a3c FUN_60094a3c
//   600ef974 FUN_600ef974
// --- callees ---


short * FUN_6009506c(short param_1)

{
  byte local_d;
  short *local_c;
  
  local_c = DAT_600950b8;
  local_d = 0;
  while( true ) {
    if (5 < local_d) {
      return (short *)0x0;
    }
    if ((*(char *)((int)local_c + 0x1b) != '\0') && (param_1 == *local_c)) break;
    local_d = local_d + 1;
    local_c = local_c + 0x10;
  }
  return local_c;
}


