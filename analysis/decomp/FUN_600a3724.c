// 600a3724  FUN_600a3724  size=92 bytes
// --- callers ---
//   600a3424 FUN_600a3424
//   600a35e4 FUN_600a35e4
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


byte FUN_600a3724(undefined4 param_1)

{
  int iVar1;
  byte local_d;
  int local_c;
  
  local_d = 0;
  for (local_c = DAT_600a3780;
      (local_d < 4 &&
      (((*(char *)(local_c + 0x128) == '\0' ||
        (iVar1 = thunk_EXT_FUN_0000b554(local_c + 6,param_1,6), iVar1 != 0)) ||
       (*(char *)(local_c + 0x12e) != '\x01')))); local_c = local_c + 0x14c) {
    local_d = local_d + 1;
  }
  return local_d;
}


