// 600b4e8a  FUN_600b4e8a  size=54 bytes
// --- callers ---
//   601323f6 FUN_601323f6
// --- callees ---
//   600a9234 FUN_600a9234


undefined4 FUN_600b4e8a(void)

{
  undefined1 *in_r3;
  undefined1 *puVar1;
  int unaff_r7;
  
  *(undefined1 **)(unaff_r7 + 8) = in_r3 + 1;
  *in_r3 = 2;
  puVar1 = *(undefined1 **)(unaff_r7 + 8);
  *(undefined1 **)(unaff_r7 + 8) = puVar1 + 1;
  *puVar1 = (char)*(undefined2 *)(unaff_r7 + 6);
  puVar1 = *(undefined1 **)(unaff_r7 + 8);
  *(undefined1 **)(unaff_r7 + 8) = puVar1 + 1;
  *puVar1 = (char)((ushort)*(undefined2 *)(unaff_r7 + 6) >> 8);
  FUN_600a9234(0,*(undefined4 *)(unaff_r7 + 0xc));
  return 1;
}


