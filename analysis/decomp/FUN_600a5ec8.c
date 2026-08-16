// 600a5ec8  FUN_600a5ec8  size=682 bytes
// --- callers ---
//   600f2dfa FUN_600f2dfa
//   600a8494 FUN_600a8494
// --- callees ---
//   600f1746 FUN_600f1746
//   600f8bd4 FUN_600f8bd4
//   600a83c8 FUN_600a83c8
//   600a8108 FUN_600a8108
//   600b3d28 FUN_600b3d28
//   600b3c74 FUN_600b3c74
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600a5ec8(byte *param_1)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  byte *local_2c;
  undefined1 auStack_28 [5];
  byte local_23 [7];
  int local_1c;
  undefined2 local_16;
  char local_13;
  char local_12;
  char local_11;
  
  local_11 = '\0';
  local_12 = '\x01';
  local_13 = 0;
  local_16 = 0;
  pbVar2 = local_23;
  local_2c = param_1;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    *pbVar2 = *local_2c;
    pbVar2 = pbVar2 + -1;
    local_2c = local_2c + 1;
  }
  local_23[1] = *(undefined1 *)(DAT_600a6174 + 0x882);
  local_23[2] = 0;
  local_23[3] = 0;
  local_1c = FUN_600f1746(auStack_28);
  if ((*(char *)(DAT_600a6174 + 0x1174) == '\x06') && (*(char *)(local_1c + 0x4f) == '\0')) {
    *(undefined1 *)(local_1c + 0x5d) = 1;
  }
  else {
    *(byte *)(local_1c + 0x59) = *(byte *)(local_1c + 0x59) | 0x11;
    cVar1 = *(char *)(DAT_600a6174 + 0x118c);
    if (cVar1 == '\x02') {
      iVar3 = thunk_EXT_FUN_0000b554(auStack_28,DAT_600a6178,6);
      if (iVar3 == 0) {
        local_23[3] = 3;
      }
      else {
        local_11 = '8';
      }
    }
    else if (cVar1 == '\b') {
      local_12 = '\0';
      if ((*(byte *)(DAT_600a6174 + 0x118d) & 2) != 0) {
        local_23[3] = 3;
      }
    }
    else if (cVar1 == '\0') {
      local_16 = *(undefined2 *)(local_1c + 0x54);
    }
    else {
      local_11 = '8';
    }
    if (*(char *)(DAT_600a6174 + 0x1175) == '\0') {
      iVar3 = FUN_600a83c8(local_1c);
      if (iVar3 == 0) {
        if ((*(char *)(DAT_600a6174 + 0x1174) == '\x06') &&
           (((*(byte *)(DAT_600a6174 + 0x88c) & 1) == 0 || ((*(byte *)(local_1c + 0x5c) & 1) == 0)))
           ) {
          local_11 = '\x18';
        }
      }
      else {
        local_11 = '\x18';
      }
    }
    else {
      local_11 = '\x18';
    }
    if (local_11 == '\0') {
      local_23[4] = local_12;
      if ((((local_12 != '\0') && ((*(byte *)(DAT_600a6174 + 0x118d) & 1) == 0)) &&
          (*(int *)(local_1c + 0xf0) != 0)) &&
         ((*(ushort *)(*(int *)(local_1c + 0xf0) + 0xe) & 0x10) != 0)) {
        if (*(char *)(DAT_600a6174 + 0x1174) == '\x06') {
          local_23[3] = 1;
        }
        else {
          local_23[3] = (byte)((int)(uint)*(ushort *)(*(int *)(local_1c + 0xf0) + 0xe) >> 0xd) & 1;
        }
      }
      FUN_600f8bd4(auStack_28);
      thunk_EXT_FUN_0000b572(DAT_600a6178,auStack_28,6);
      iVar3 = thunk_EXT_FUN_0000b554(auStack_28,DAT_600a617c,6);
      if (iVar3 == 0) {
        thunk_EXT_FUN_0000b572(local_1c + 0x16,DAT_600a6180,3);
      }
      FUN_600a8108(7);
      local_13 = '\0';
      if ((*(byte *)(local_1c + 0x59) & 4) == 0) {
        if (*(int *)(DAT_600a6174 + 0x1134) != 0) {
          local_13 = (**(code **)(DAT_600a6174 + 0x1134))(0,auStack_28);
        }
      }
      else {
        *(byte *)(local_1c + 0x59) = *(byte *)(local_1c + 0x59) & 0xfb;
        local_23[3] = 5;
      }
      if (local_13 == '\0') {
        if ((*(byte *)(DAT_600a6174 + 0x118d) & 1) != 0) {
          local_23[3] = local_23[3] & 1 | 2;
        }
        if (*(char *)(DAT_600a6174 + 0x1174) == '\x06') {
          local_23[3] = local_23[3] | 1;
        }
        *(byte *)(DAT_600a6174 + 0x883) = local_23[3];
        *(byte *)(DAT_600a6174 + 0x882) = local_23[1];
        FUN_600b3c74(auStack_28,local_23[1],local_23[2],local_23[3]);
      }
    }
    else {
      FUN_600b3d28(auStack_28,local_11);
    }
  }
  return;
}


