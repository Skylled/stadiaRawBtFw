// 60092ada  FUN_60092ada  size=40 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   6006ddd8 FUN_6006ddd8


undefined4 FUN_60092ada(void)

{
  undefined4 uVar1;
  undefined4 in_r3;
  int unaff_r7;
  
  uVar1 = FUN_6006dbac(in_r3,DAT_60092c9c);
  *(undefined4 *)(DAT_60092c90 + 0x14) = uVar1;
  FUN_6006ddd8(*(undefined4 *)(*(int *)(unaff_r7 + 0x14) + 0xc),DAT_60092c9c,0x99);
  return 1;
}


