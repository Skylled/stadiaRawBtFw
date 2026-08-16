// 600a7b44  FUN_600a7b44  size=450 bytes
// --- callers ---
//   600a6b20 FUN_600a6b20
//   600a4c5c FUN_600a4c5c
//   600a67ec FUN_600a67ec
//   600a59d0 FUN_600a59d0
//   600a7fb4 FUN_600a7fb4
//   600a6d70 FUN_600a6d70
//   600a51a8 FUN_600a51a8
//   600f1b72 FUN_600f1b72
//   600f1a0e FUN_600f1a0e
// --- callees ---
//   600f1f20 FUN_600f1f20
//   600a7d0c FUN_600a7d0c
//   600f1ef0 FUN_600f1ef0
//   600f1ecc FUN_600f1ecc
//   600f1e84 FUN_600f1e84


undefined4 FUN_600a7b44(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x50) == '\0') {
    if (((*(ushort *)(param_1 + 0x2a) & 8) == 0) && (*(short *)(param_1 + 0xc) != -1)) {
      iVar1 = FUN_600f1e84(param_1);
      if (iVar1 == 0) {
        return 3;
      }
      return 1;
    }
    if (((*(ushort *)(param_1 + 0x2a) & 2) == 0) &&
       ((((*(char *)(param_1 + 0x51) != '\0' && ((*(ushort *)(param_1 + 0x54) & 0x10) != 0)) ||
         ((*(char *)(param_1 + 0x51) == '\0' && ((*(ushort *)(param_1 + 0x54) & 2) != 0)))) &&
        (*(short *)(param_1 + 0xc) != -1)))) {
      iVar1 = FUN_600f1ecc(param_1);
      if (iVar1 == 0) {
        return 3;
      }
      return 1;
    }
    if ((((*(ushort *)(param_1 + 0x2a) & 4) == 0) &&
        (((*(char *)(param_1 + 0x51) != '\0' && ((*(ushort *)(param_1 + 0x54) & 0x20) != 0)) ||
         ((*(char *)(param_1 + 0x51) == '\0' && ((*(ushort *)(param_1 + 0x54) & 4) != 0)))))) &&
       (*(short *)(param_1 + 0xc) != -1)) {
      iVar1 = FUN_600f1ef0(param_1);
      if (iVar1 == 0) {
        return 3;
      }
      return 1;
    }
    if (((*(ushort *)(param_1 + 0x54) & 0x40) == 0) || (*(char *)(param_1 + 0x57) == '\b')) {
      if ((((*(ushort *)(param_1 + 0x2a) & 1) == 0) &&
          (((*(char *)(param_1 + 0x51) != '\0' && ((*(ushort *)(param_1 + 0x54) & 8) != 0)) ||
           ((*(char *)(param_1 + 0x51) == '\0' && ((*(ushort *)(param_1 + 0x54) & 1) != 0)))))) &&
         (((iVar1 = FUN_600f1f20(param_1 + 4), iVar1 == 0 &&
           (*(byte *)(*(int *)(param_1 + 0xf0) + 0x10) < 0x37)) &&
          ((1 << (*(byte *)(*(int *)(param_1 + 0xf0) + 0x10) & 0x1f) &
           *(uint *)((uint)(*(byte *)(*(int *)(param_1 + 0xf0) + 0x10) >> 5) * 4 + param_1 + 4)) ==
           0)))) {
        uVar2 = FUN_600a7d0c(param_1);
        return uVar2;
      }
      *(ushort *)(param_1 + 0x54) = (ushort)DAT_600a7d08 & *(ushort *)(param_1 + 0x54);
      uVar2 = 0;
    }
    else {
      uVar2 = 0x12;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


