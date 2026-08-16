// 600979e4  FUN_600979e4  size=306 bytes
// --- callers ---
//   6009819c FUN_6009819c
// --- callees ---
//   6009f644 FUN_6009f644
//   600a1394 FUN_600a1394
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f1746 FUN_600f1746
//   6009beb0 FUN_6009beb0
//   6009f93c FUN_6009f93c
//   6009ff18 FUN_6009ff18


char FUN_600979e4(char param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_2c [12];
  int local_20;
  char *local_1c;
  char local_15;
  char *local_14;
  
  local_14 = local_2c;
  local_15 = '\x05';
  if (param_2 == (char *)0x0) {
    param_2 = (char *)0x0;
  }
  local_20 = 0;
  local_1c = param_2;
  thunk_EXT_FUN_0000b5ba(local_2c,0,9);
  pcVar1 = local_14 + 1;
  *local_14 = 6;
  local_14 = pcVar1;
  pcVar1 = local_14 + 1;
  *local_14 = param_1;
  local_14 = pcVar1;
  if (((local_1c != (char *)0x0) && (local_20 = FUN_6009ff18(local_1c + 1), local_20 != 0)) &&
     ((*(byte *)(local_20 + 0x72) & 2) != 0)) {
    FUN_6009f93c(2);
    FUN_6009beb0(local_1c + 1,local_1c);
  }
  if ((param_1 == '\0') || (param_1 == '\x01')) {
    if (local_1c == (char *)0x0) {
      return local_15;
    }
    local_20 = FUN_600f1746(local_1c + 1);
    if ((*(byte *)(local_20 + 0x72) & 2) == 0) {
      FUN_6009f644(2,1);
    }
    else {
      FUN_6009f93c(2);
      FUN_6009beb0(local_1c + 1,local_1c);
    }
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      pcVar1 = local_14 + 1;
      *local_14 = local_1c[6 - iVar2];
      local_14 = pcVar1;
    }
    pcVar1 = local_14 + 1;
    *local_14 = *local_1c;
    local_14 = pcVar1;
  }
  local_15 = FUN_600a1394(0xfce9,9,local_2c,DAT_60097b18);
  if (local_15 != '\x03') {
    thunk_EXT_FUN_0000b5ba(DAT_60097b1c,0,7);
  }
  return local_15;
}


