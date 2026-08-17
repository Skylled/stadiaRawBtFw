// 600a0484  FUN_600a0484  size=152 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a02b4 FUN_600a02b4
//   600b39a4 FUN_600b39a4
//   600b932c FUN_600b932c


void FUN_600a0484(char *param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (*param_1 == '\0') {
    *(ushort *)(DAT_600a051c + 0x58) = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
    bVar1 = param_1[4];
    bVar2 = param_1[5];
    *(short *)(DAT_600a051c + 0x5a) = *(short *)(DAT_600a051c + 0x58) + 4;
    FUN_600b932c((ushort)bVar2 * 0x100 + (ushort)bVar1);
    FUN_600b39a4(0x248,0xff,0x14,10);
  }
  FUN_600a02b4();
  return;
}


