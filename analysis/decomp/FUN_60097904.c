// 60097904  FUN_60097904  size=216 bytes
// --- callers ---
//   60097dc8 FUN_60097dc8
//   6009819c FUN_6009819c
// --- callees ---
//   600a1394 FUN_600a1394
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_60097904(char param_1,byte *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_3c [31];
  char local_1d;
  byte *local_1c;
  char local_15;
  char *local_14;
  
  if (param_2 == (byte *)0x0) {
    param_2 = (byte *)0x0;
  }
  local_14 = local_3c;
  local_15 = '\x02';
  local_1d = '\x05';
  local_1c = param_2;
  thunk_EXT_FUN_0000b5ba(local_3c,0,0x1f);
  pcVar1 = local_14 + 1;
  *local_14 = 9;
  local_14 = pcVar1;
  pcVar1 = local_14 + 1;
  *local_14 = param_1;
  local_14 = pcVar1;
  if ((param_1 == '\0') || (param_1 == '\x01')) {
    if (local_1c == (byte *)0x0) {
      return local_1d;
    }
    if (0x1d < *local_1c) {
      *local_1c = 0x1d;
    }
    for (iVar2 = 0; iVar2 < (int)(uint)*local_1c; iVar2 = iVar2 + 1) {
      pcVar1 = local_14 + 1;
      *local_14 = *(char *)(iVar2 + *(int *)(local_1c + 4));
      local_14 = pcVar1;
    }
    local_15 = local_15 + *local_1c;
  }
  local_1d = FUN_600a1394(0xfce9,local_15,local_3c,DAT_600979dc);
  if (local_1d != '\x03') {
    thunk_EXT_FUN_0000b5ba(DAT_600979e0,0,7);
  }
  return local_1d;
}


