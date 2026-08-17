// 600a1cac  FUN_600a1cac  size=134 bytes
// --- callers ---
//   600a24c8 FUN_600a24c8
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600b203c FUN_600b203c


undefined1 FUN_600a1cac(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = DAT_600a1d34;
  local_9 = 0;
  iVar2 = FUN_600a01a0();
  if (iVar2 == 0) {
    local_9 = 6;
  }
  else if ((*(byte *)(DAT_600a1d38 + 0x1112) & 8) != 0) {
    *(undefined1 *)(DAT_600a1d38 + 0x1112) = 0;
    *(undefined4 *)(DAT_600a1d38 + 0xb2c) = 0;
    iVar2 = FUN_600b203c();
    if (iVar2 == 0) {
      local_9 = 3;
    }
    if (*(char *)(iVar1 + 0x61a) != '\0') {
      *(char *)(iVar1 + 0x61b) = *(char *)(iVar1 + 0x61b) + '\x01';
    }
    *(undefined1 *)(iVar1 + 0x61a) = 0;
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 1;
  }
  return local_9;
}


