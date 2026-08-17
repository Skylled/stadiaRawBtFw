// 600a0804  FUN_600a0804  size=186 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a02d8 FUN_600a02d8
//   600a0300 FUN_600a0300


void FUN_600a0804(char *param_1)

{
  byte *pbVar1;
  
  pbVar1 = DAT_600a08c0;
  if (*param_1 == '\0') {
    *DAT_600a08c0 = param_1[1];
    *(ushort *)(pbVar1 + 2) = (ushort)(byte)param_1[3] * 0x100 + (ushort)(byte)param_1[2];
    pbVar1[4] = param_1[4];
    *(ushort *)(pbVar1 + 6) = (ushort)(byte)param_1[6] * 0x100 + (ushort)(byte)param_1[5];
    *(ushort *)(pbVar1 + 8) = (ushort)(byte)param_1[8] * 0x100 + (ushort)(byte)param_1[7];
  }
  if (*pbVar1 < 2) {
    FUN_600a0300();
  }
  else {
    FUN_600a02d8(0);
  }
  return;
}


