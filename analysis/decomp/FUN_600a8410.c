// 600a8410  FUN_600a8410  size=126 bytes
// --- callers ---
//   600a0bc4 FUN_600a0bc4
// --- callees ---


void FUN_600a8410(void)

{
  int iVar1;
  
  iVar1 = DAT_600a8490;
  if ((*(byte *)(DAT_600a8490 + 299) & 8) == 0) {
    *(byte *)(DAT_600a8490 + 0x19c) = *(byte *)(DAT_600a8490 + 0x19c) & 0xfe;
  }
  else {
    *(byte *)(DAT_600a8490 + 0x19c) = *(byte *)(DAT_600a8490 + 0x19c) | 1;
  }
  if ((*(byte *)(iVar1 + 0x134) & 2) == 0) {
    *(byte *)(iVar1 + 0x19c) = *(byte *)(iVar1 + 0x19c) & 0xfd;
  }
  else {
    *(byte *)(iVar1 + 0x19c) = *(byte *)(iVar1 + 0x19c) | 2;
  }
  return;
}


