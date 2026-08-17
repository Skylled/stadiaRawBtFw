// 600bfb5a  FUN_600bfb5a  size=8 bytes
// --- callers ---
//   6013aad0 FUN_6013aad0
// --- callees ---


undefined4 FUN_600bfb5a(void)

{
  int unaff_r7;
  
  switch(*(byte *)(unaff_r7 + 0xb) & 7) {
  case 0:
    **(undefined4 **)(unaff_r7 + 4) = 1;
    break;
  case 1:
    **(undefined4 **)(unaff_r7 + 4) = 2;
    break;
  case 2:
    **(undefined4 **)(unaff_r7 + 4) = 4;
    break;
  case 3:
    **(undefined4 **)(unaff_r7 + 4) = 8;
    break;
  case 4:
    **(undefined4 **)(unaff_r7 + 4) = 0x10;
    break;
  case 5:
    *(undefined1 *)(unaff_r7 + 0x11) = **(undefined1 **)(unaff_r7 + 0xc);
    *(int *)(unaff_r7 + 0xc) = *(int *)(unaff_r7 + 0xc) + 1;
    **(uint **)(unaff_r7 + 4) = (uint)*(byte *)(unaff_r7 + 0x11);
    break;
  case 6:
    *(ushort *)(unaff_r7 + 0x12) =
         (ushort)*(byte *)(*(int *)(unaff_r7 + 0xc) + 1) +
         (ushort)**(byte **)(unaff_r7 + 0xc) * 0x100;
    *(int *)(unaff_r7 + 0xc) = *(int *)(unaff_r7 + 0xc) + 2;
    **(uint **)(unaff_r7 + 4) = (uint)*(ushort *)(unaff_r7 + 0x12);
    break;
  case 7:
    *(uint *)(unaff_r7 + 0x14) =
         (uint)**(byte **)(unaff_r7 + 0xc) * 0x1000000 +
         (uint)*(byte *)(*(int *)(unaff_r7 + 0xc) + 3) +
         (uint)*(byte *)(*(int *)(unaff_r7 + 0xc) + 2) * 0x100 +
         (uint)*(byte *)(*(int *)(unaff_r7 + 0xc) + 1) * 0x10000;
    *(int *)(unaff_r7 + 0xc) = *(int *)(unaff_r7 + 0xc) + 4;
    **(uint **)(unaff_r7 + 4) = *(uint *)(unaff_r7 + 0x14) & 0xffff;
  }
  return *(undefined4 *)(unaff_r7 + 0xc);
}


