// 600c0d3c  FUN_600c0d3c  size=112 bytes
// --- callers ---
//   6013aad0 FUN_6013aad0
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600c0d3c(void)

{
  undefined4 in_r3;
  undefined1 *puVar1;
  int unaff_r7;
  
  puVar1 = *(undefined1 **)(unaff_r7 + 0x1c);
  *(undefined1 **)(unaff_r7 + 0x1c) = puVar1 + 1;
  *puVar1 = (char)((uint)in_r3 >> 0x10);
  puVar1 = *(undefined1 **)(unaff_r7 + 0x1c);
  *(undefined1 **)(unaff_r7 + 0x1c) = puVar1 + 1;
  *puVar1 = (char)((uint)*(undefined4 *)(unaff_r7 + 0xc) >> 0x18);
  *(undefined1 *)(unaff_r7 + 0x10) = 0;
  *(int *)(unaff_r7 + 0x14) = *(int *)(unaff_r7 + 4) + 0x1b6;
  if (**(int **)(unaff_r7 + 4) != 0) {
    (*(code *)**(undefined4 **)(unaff_r7 + 4))(3,*(int *)(unaff_r7 + 4) + 0x1d,unaff_r7 + 0xc);
  }
  if (*(char *)(*(int *)(unaff_r7 + 4) + 0x194) == '\a') {
    FUN_600c1a34(DAT_600c0db0,0x10,unaff_r7 + 0xc);
  }
  else {
    FUN_600c1a34(*(undefined4 *)(unaff_r7 + 4),0x10,unaff_r7 + 0x10);
  }
  return;
}


