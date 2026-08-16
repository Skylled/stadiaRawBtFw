// 600b5844  FUN_600b5844  size=420 bytes
// --- callers ---
//   600f7bd8 FUN_600f7bd8
//   600f7d88 FUN_600f7d88
//   600f7b48 FUN_600f7b48
//   600f7d46 FUN_600f7d46
// --- callees ---
//   600b1124 FUN_600b1124
//   60098ec8 FUN_60098ec8
//   600f8122 FUN_600f8122


void FUN_600b5844(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_60098ec8(param_1 + 4,2);
  if ((*(byte *)(param_1 + 0x38) & 4) == 0) {
    if ((*(byte *)(param_1 + 0x38) & 1) == 0) {
      if ((*(byte *)(param_1 + 0x38) & 2) != 0) {
        if ((*(char *)(param_1 + 10) == '\0') ||
           (((*(byte *)(DAT_600b59e8 + 0x831) & 2) != 0 && ((*(byte *)(iVar1 + 0x13d) & 2) != 0))))
        {
          FUN_600b1124(*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 0x3a),
                       *(undefined2 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x3e),
                       *(undefined2 *)(param_1 + 0x40),0,0);
          *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 4;
        }
        else {
          FUN_600f8122(param_1,*(undefined2 *)(param_1 + 0x3a),*(undefined2 *)(param_1 + 0x3c),
                       *(undefined2 *)(param_1 + 0x3e),*(undefined2 *)(param_1 + 0x40));
        }
        *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfd;
        *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 8;
      }
    }
    else if (((*(byte *)(param_1 + 0x38) & 8) != 0) && (6 < *(ushort *)(param_1 + 0x3a))) {
      if ((*(char *)(param_1 + 10) == '\0') ||
         (((*(byte *)(DAT_600b59e8 + 0x831) & 2) != 0 && ((*(byte *)(iVar1 + 0x13d) & 2) != 0)))) {
        FUN_600b1124(*(undefined2 *)(param_1 + 2),6,6,0,700,0,0);
        *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 4;
      }
      else {
        FUN_600f8122(param_1,6,6,0,700);
      }
      *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xf7;
      *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 2;
    }
  }
  return;
}


