// 600a0520  FUN_600a0520  size=134 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600b5bc0 FUN_600b5bc0
//   600a0260 FUN_600a0260


void FUN_600a0520(char *param_1)

{
  char cVar1;
  
  if (*param_1 == '\0') {
    *(ushort *)(DAT_600a05a8 + 0x5c) = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
    cVar1 = param_1[3];
    if (*(short *)(DAT_600a05a8 + 0x5c) == 0) {
      *(undefined2 *)(DAT_600a05a8 + 0x5c) = *(undefined2 *)(DAT_600a05a8 + 0x58);
    }
    *(short *)(DAT_600a05a8 + 0x5e) = *(short *)(DAT_600a05a8 + 0x5c) + 4;
    FUN_600b5bc0(cVar1);
  }
  FUN_600a0260();
  return;
}


