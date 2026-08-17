// 600a1efc  FUN_600a1efc  size=200 bytes
// --- callers ---
//   600c309c FUN_600c309c
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600a25f8 FUN_600a25f8
//   6009e70c FUN_6009e70c
//   600b1ef8 FUN_600b1ef8


undefined1 FUN_600a1efc(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = DAT_600a1fc4;
  local_9 = 1;
  iVar2 = FUN_600a01a0();
  if (iVar2 == 0) {
    local_9 = 6;
  }
  else if (((*(byte *)(iVar1 + 0x61e) & 0x3b) == 0) || ((*(byte *)(iVar1 + 0x61e) & 8) != 0)) {
    local_9 = 6;
  }
  else {
    if (*(char *)(iVar1 + 0x61a) == '\0') {
      if (((*(byte *)(iVar1 + 0x608) & 3) != 0) && (iVar2 = FUN_600b1ef8(), iVar2 == 0)) {
        local_9 = 3;
      }
      if ((*(byte *)(iVar1 + 0x608) & 0x30) != 0) {
        FUN_6009e70c();
      }
    }
    else {
      *(undefined1 *)(iVar1 + 0x61e) = 0;
      *(undefined1 *)(iVar1 + 0x61d) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
      *(undefined4 *)(iVar1 + 0x34) = 0;
      *(undefined1 *)(iVar1 + 0x61a) = 0;
      *(char *)(iVar1 + 0x61b) = *(char *)(iVar1 + 0x61b) + '\x01';
      local_9 = 0;
    }
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 1;
    FUN_600a25f8();
  }
  return local_9;
}


