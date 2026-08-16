// 600b7cba  FUN_600b7cba  size=232 bytes
// --- callers ---
//   60139ace FUN_60139ace
// --- callees ---
//   600b7674 FUN_600b7674
//   600f82c4 FUN_600f82c4
//   6006ddd8 FUN_6006ddd8
//   600b842c FUN_600b842c


void FUN_600b7cba(void)

{
  undefined1 uVar1;
  uint in_r3;
  int unaff_r7;
  
  if ((in_r3 & 0x10) != 0) {
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 8) = 0;
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 0xc) = 1;
  }
  switch(*(undefined2 *)(unaff_r7 + 0x16)) {
  case 0:
    *(undefined1 *)(unaff_r7 + 0x15) = *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 6);
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 6) = 0;
    if (((*(ushort *)(unaff_r7 + 6) & 0x80) != 0) || (*(char *)(unaff_r7 + 0x15) != '\0')) {
      uVar1 = FUN_600b842c(*(undefined4 *)(unaff_r7 + 0xc),0xff);
      *(undefined1 *)(unaff_r7 + 0x1f) = uVar1;
    }
    break;
  case 1:
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 6) = 0;
    uVar1 = FUN_600b842c(*(undefined4 *)(unaff_r7 + 0xc),0xff);
    *(undefined1 *)(unaff_r7 + 0x1f) = uVar1;
    break;
  case 2:
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 6) = 1;
    FUN_600f82c4(*(undefined4 *)(unaff_r7 + 0xc));
    break;
  case 3:
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 6) = 0;
    uVar1 = FUN_600b842c(*(undefined4 *)(unaff_r7 + 0xc),*(ushort *)(unaff_r7 + 6) >> 8 & 0x3f);
    *(undefined1 *)(unaff_r7 + 0x1f) = uVar1;
  }
  if ((*(char *)(unaff_r7 + 0x1f) != '\0') && (*(char *)(*(int *)(unaff_r7 + 0x18) + 0xc) != '\0'))
  {
    if (*(char *)(*(int *)(unaff_r7 + 0x18) + 9) == '\0') {
      if (*(char *)(*(int *)(unaff_r7 + 0x18) + 7) == '\0') {
        FUN_600b7674(*(undefined4 *)(unaff_r7 + 0xc),0,0x80);
      }
      else {
        FUN_600b7674(*(undefined4 *)(unaff_r7 + 0xc),2,0x80);
      }
    }
    else {
      FUN_600b7674(*(undefined4 *)(unaff_r7 + 0xc),3,0x80);
    }
    *(undefined1 *)(*(int *)(unaff_r7 + 0x18) + 0xc) = 0;
  }
  FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 8),DAT_600b7db4,0x439);
  return;
}


