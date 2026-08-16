// 600a17ec  FUN_600a17ec  size=272 bytes
// --- callers ---
//   600c29d0 FUN_600c29d0
// --- callees ---
//   600b3640 FUN_600b3640
//   600b36e8 FUN_600b36e8


undefined4 FUN_600a17ec(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    if (((param_2 < 0x11) || (((0x1000 < param_2 || (param_1 < 0x12)) || (0x1000 < param_1)))) ||
       (param_1 < param_2)) {
      return 5;
    }
    if ((param_2 != *(ushort *)(DAT_600a18fc + 0xb18)) ||
       (param_1 != *(ushort *)(DAT_600a18fc + 0xb1a))) {
      iVar1 = FUN_600b36e8(param_1,param_2);
      if (iVar1 == 0) {
        return 3;
      }
      *(ushort *)(DAT_600a18fc + 0xb18) = param_2;
      *(ushort *)(DAT_600a18fc + 0xb1a) = param_1;
    }
  }
  if ((param_4 != 0) && (param_3 != 0)) {
    if ((param_4 < 0x11) ||
       ((((0x1000 < param_4 || (param_3 < 0x12)) || (0x1000 < param_3)) || (param_3 < param_4)))) {
      return 5;
    }
    if ((param_4 != *(ushort *)(DAT_600a18fc + 0xb14)) ||
       (param_3 != *(ushort *)(DAT_600a18fc + 0xb16))) {
      iVar1 = FUN_600b3640(param_3,param_4);
      if (iVar1 == 0) {
        return 3;
      }
      *(ushort *)(DAT_600a18fc + 0xb14) = param_4;
      *(ushort *)(DAT_600a18fc + 0xb16) = param_3;
    }
  }
  return 0;
}


