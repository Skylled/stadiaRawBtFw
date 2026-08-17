// 6009837c  FUN_6009837c  size=110 bytes
// --- callers ---
//   600eff14 FUN_600eff14
//   600985f8 FUN_600985f8
// --- callees ---
//   60098284 FUN_60098284


undefined4 FUN_6009837c(void)

{
  undefined4 uVar1;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = DAT_600983ec;
  local_e = '\0';
  local_f = 1;
  for (local_d = 0; local_d < 4; local_d = local_d + 1) {
    if ((*(char *)(local_c + 0x128) != '\0') && (*(int *)(local_c + 0x148) != 0)) {
      local_e = local_e + '\x01';
    }
    local_c = local_c + 0x14c;
  }
  if ((local_e == '\0') && (*(int *)(DAT_600983f0 + 0xc4) == 0)) {
    local_f = 0;
  }
  uVar1 = FUN_60098284(local_f,4);
  return uVar1;
}


