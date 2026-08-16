// 600977fc  FUN_600977fc  size=256 bytes
// --- callers ---
//   60097dc8 FUN_60097dc8
//   6009819c FUN_6009819c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a1394 FUN_600a1394


char FUN_600977fc(char param_1,undefined2 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_5c [63];
  char local_1d;
  undefined2 *local_1c;
  char local_15;
  char *local_14;
  
  if (param_2 == (undefined2 *)0x0) {
    param_2 = (undefined2 *)0x0;
  }
  local_14 = local_5c;
  local_15 = '\x02';
  local_1d = '\x05';
  local_1c = param_2;
  thunk_EXT_FUN_0000b5ba(local_5c,0,0x1f);
  pcVar1 = local_14 + 1;
  *local_14 = 10;
  local_14 = pcVar1;
  pcVar1 = local_14 + 1;
  *local_14 = param_1;
  local_14 = pcVar1;
  if ((param_1 == '\0') || (param_1 == '\x01')) {
    if (local_1c == (undefined2 *)0x0) {
      return local_1d;
    }
    if (0x1b < *(byte *)(local_1c + 1)) {
      *(undefined1 *)(local_1c + 1) = 0x1b;
    }
    pcVar1 = local_14 + 1;
    *local_14 = (char)*local_1c;
    local_14 = pcVar1;
    pcVar1 = local_14 + 1;
    *local_14 = (char)((ushort)*local_1c >> 8);
    local_14 = pcVar1;
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(local_1c + 1); iVar2 = iVar2 + 1) {
      pcVar1 = local_14 + 1;
      *local_14 = *(char *)(iVar2 + *(int *)(local_1c + 2));
      local_14 = pcVar1;
    }
    local_15 = local_15 + *(char *)(local_1c + 1) + '\x02';
  }
  local_1d = FUN_600a1394(0xfce9,local_15,local_5c,DAT_600978fc);
  if (local_1d != '\x03') {
    thunk_EXT_FUN_0000b5ba(DAT_60097900,0,7);
  }
  return local_1d;
}


