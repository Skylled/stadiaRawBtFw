// 6009e84c  FUN_6009e84c  size=158 bytes
// --- callers ---
//   6009cc7c FUN_6009cc7c
//   6009c848 FUN_6009c848
//   6009e95c FUN_6009e95c
//   600f1376 FUN_600f1376
//   6009dc14 FUN_6009dc14
//   6009f57c FUN_6009f57c
//   6009daac FUN_6009daac
// --- callees ---
//   6009f990 FUN_6009f990
//   6009e7d0 FUN_6009e7d0
//   6009c01c FUN_6009c01c
//   600b0c60 FUN_600b0c60


undefined1 FUN_6009e84c(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = DAT_6009e8ec;
  local_9 = 3;
  iVar2 = FUN_6009e7d0(DAT_6009e8f0,*(undefined1 *)(DAT_6009e8ec + 0x11));
  if (iVar2 == 0) {
    local_9 = 6;
  }
  else {
    if ((*(char *)(iVar1 + 0x11) != '\x04') && (*(char *)(iVar1 + 0x11) != '\x01')) {
      FUN_6009f990(4);
    }
    if (*(char *)(iVar1 + 0xe) != '\0') {
      FUN_6009c01c();
      *(byte *)(DAT_6009e8f4 + 0x9c6) = *(byte *)(DAT_6009e8f4 + 0x9c6) | 4;
    }
    iVar2 = FUN_600b0c60(1);
    if (iVar2 == 0) {
      *(undefined1 *)(iVar1 + 0x12) = 0;
      *(byte *)(DAT_6009e8f4 + 0x9c6) = *(byte *)(DAT_6009e8f4 + 0x9c6) & 0xfb;
    }
    else {
      *(undefined1 *)(iVar1 + 0x12) = 1;
      FUN_6009e7d0(DAT_6009e8f8,*(undefined1 *)(iVar1 + 0x11));
      local_9 = 0;
    }
  }
  return local_9;
}


