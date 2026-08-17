// 600bcc30  FUN_600bcc30  size=116 bytes
// --- callers ---
//   600f7a34 FUN_600f7a34
//   600f7806 FUN_600f7806
//   600b4ed0 FUN_600b4ed0
//   600bb3b4 FUN_600bb3b4
//   600f7a68 FUN_600f7a68
//   600b9e28 FUN_600b9e28
//   600f7912 FUN_600f7912
//   600ba1c4 FUN_600ba1c4
//   600f79a8 FUN_600f79a8
// --- callees ---


ushort * FUN_600bcc30(int param_1,ushort param_2)

{
  byte local_d;
  ushort *local_c;
  
  local_c = (ushort *)0x0;
  if (0x3f < param_2) {
    local_d = 0;
    for (local_c = DAT_600bcca4;
        (local_d < 8 && ((param_2 != *local_c || (*(char *)((int)local_c + 5) == '\0'))));
        local_c = local_c + 0xac) {
      local_d = local_d + 1;
    }
    if (local_d < 8) {
      if ((param_1 != 0) && (param_1 != *(int *)(local_c + 0x96))) {
        local_c = (ushort *)0x0;
      }
    }
    else {
      local_c = (ushort *)0x0;
    }
  }
  return local_c;
}


