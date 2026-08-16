// 6009afd4  FUN_6009afd4  size=206 bytes
// --- callers ---
//   600f0bb8 FUN_600f0bb8
//   600fb626 FUN_600fb626
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600b13dc FUN_600b13dc


char FUN_6009afd4(undefined4 param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  char local_9;
  
  local_10 = DAT_6009b0a4;
  local_14 = FUN_6009ff18(param_1);
  local_1c = 0;
  local_18 = 0;
  local_9 = '\x03';
  if (local_14 == 0) {
    local_9 = '\x06';
  }
  else if (*(char *)(local_14 + 0x50) == '\x02') {
    local_9 = '\x02';
  }
  else {
    *(undefined2 *)(local_10 + 0xae0) = *(undefined2 *)(local_14 + 0x5e);
    if (param_2 == '\0') {
      if (((*(byte *)(local_14 + 0x7b) & 1) != 0) &&
         (iVar1 = FUN_600b13dc(*(undefined2 *)(local_14 + 0x5e),local_14 + 0xcc,
                               *(undefined2 *)(local_14 + 0xd4),local_14 + 0x8c), iVar1 != 0)) {
        local_9 = '\x01';
      }
    }
    else {
      iVar1 = FUN_600b13dc(*(undefined2 *)(local_14 + 0x5e),&local_1c,0,param_3);
      if (iVar1 != 0) {
        local_9 = '\x01';
      }
    }
    if ((local_9 == '\x01') && (*(char *)(local_14 + 0x50) == '\0')) {
      *(undefined1 *)(local_14 + 0x50) = 2;
    }
  }
  return local_9;
}


