// 600a8494  FUN_600a8494  size=288 bytes
// --- callers ---
//   600f033a FUN_600f033a
//   60098f88 FUN_60098f88
// --- callees ---
//   600a5ec8 FUN_600a5ec8
//   600b4e40 FUN_600b4e40


void FUN_600a8494(undefined2 *param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [8];
  undefined1 *local_14;
  
  if ((*(byte *)(DAT_600a85b4 + 0x1174) < 4) || ((*(byte *)(param_1 + 0x8b) & 1) == 0)) {
    *(undefined1 *)(param_2 + 0x59) = 0x10;
    *(byte *)(param_2 + 0x5c) = *(byte *)(param_2 + 0x5c) & 0xfc;
  }
  else {
    *(undefined1 *)(param_2 + 0x59) = 0x11;
    if ((*(byte *)(param_1 + 0x8b) & 8) == 0) {
      *(byte *)(param_2 + 0x5c) = *(byte *)(param_2 + 0x5c) & 0xfe;
    }
    else {
      *(byte *)(param_2 + 0x5c) = *(byte *)(param_2 + 0x5c) | 1;
    }
    if (((*(byte *)((int)param_1 + 0x11f) & 1) == 0) || ((*(byte *)((int)param_1 + 0x11f) & 2) == 0)
       ) {
      *(byte *)(param_2 + 0x5c) = *(byte *)(param_2 + 0x5c) & 0xfd;
    }
    else {
      *(byte *)(param_2 + 0x5c) = *(byte *)(param_2 + 0x5c) | 2;
    }
  }
  if ((*(byte *)(DAT_600a85b4 + 0x88c) & 2) != 0) {
    FUN_600b4e40(*param_1);
  }
  if (*(char *)(param_2 + 0x5d) != '\0') {
    local_14 = local_1c;
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      puVar1 = local_14 + 1;
      *local_14 = *(undefined1 *)((param_2 - iVar2) + 0x15);
      local_14 = puVar1;
    }
    local_14 = local_1c;
    FUN_600a5ec8(local_14);
    *(undefined1 *)(param_2 + 0x5d) = 0;
  }
  return;
}


