// 600afee4  FUN_600afee4  size=46 bytes
// --- callers ---
//   60132e5c FUN_60132e5c
// --- callees ---


undefined4 FUN_600afee4(void)

{
  int unaff_r7;
  char in_ZR;
  
  while (in_ZR == '\0') {
    do {
      *(short *)(unaff_r7 + 0xe) = *(short *)(unaff_r7 + 0xe) + 1;
      if (9 < *(ushort *)(unaff_r7 + 0xe)) goto LAB_600aff04;
    } while (*(char *)((uint)*(ushort *)(unaff_r7 + 0xe) * 0x10c + DAT_600aff14 + 0xfa) == '\0');
    in_ZR = *(short *)(unaff_r7 + 6) ==
            *(short *)((uint)*(ushort *)(unaff_r7 + 0xe) * 0x10c + DAT_600aff14 + 0x18);
  }
  *(uint *)(unaff_r7 + 8) = (uint)*(ushort *)(unaff_r7 + 0xe) * 0x10c + DAT_600aff14;
LAB_600aff04:
  return *(undefined4 *)(unaff_r7 + 8);
}


