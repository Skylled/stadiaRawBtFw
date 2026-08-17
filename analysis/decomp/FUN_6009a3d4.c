// 6009a3d4  FUN_6009a3d4  size=194 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600aa3cc FUN_600aa3cc


void FUN_6009a3d4(char *param_1)

{
  undefined1 local_20;
  char local_1f;
  char local_1e;
  undefined1 auStack_1d [7];
  short local_16;
  code *local_14;
  ushort local_e;
  short *local_c;
  
  local_14 = *(code **)(DAT_6009a498 + 0x770);
  local_c = DAT_6009a49c;
  FUN_600aa3cc(DAT_6009a4a0);
  *(undefined4 *)(DAT_6009a498 + 0x770) = 0;
  if (local_14 != (code *)0x0) {
    local_1f = *param_1;
    if (local_1f == '\0') {
      local_20 = 0;
      local_16 = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
      local_1e = param_1[3];
      for (local_e = 0; local_e < 4; local_e = local_e + 1) {
        if (((char)local_c[0x94] != '\0') && (local_16 == *local_c)) {
          thunk_EXT_FUN_0000b572(auStack_1d,local_c + 3,6);
          break;
        }
        local_c = local_c + 0xa6;
      }
    }
    else {
      local_20 = 10;
    }
    (*local_14)(&local_20);
  }
  return;
}


