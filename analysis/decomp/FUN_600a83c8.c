// 600a83c8  FUN_600a83c8  size=68 bytes
// --- callers ---
//   600a5ec8 FUN_600a5ec8
// --- callees ---


undefined4 FUN_600a83c8(int param_1)

{
  undefined4 uVar1;
  
  if (((*(char *)(DAT_600a840c + 0x1176) == '\0') || (*(char *)(DAT_600a840c + 0x118c) != '\b')) ||
     ((*(byte *)(param_1 + 0x5b) & 6) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


