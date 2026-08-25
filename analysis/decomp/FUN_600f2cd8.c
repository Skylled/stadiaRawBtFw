// 600f2cd8  FUN_600f2cd8  size=128 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   60099d8c FUN_60099d8c
//   600f1e24 FUN_600f1e24


void FUN_600f2cd8(char *param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (*param_1 == '\0') {
    sVar1 = (ushort)(byte)param_1[4] * 0x100 + (ushort)(byte)param_1[3];
    uVar2 = (ushort)(((uint)(ushort)((ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1]) <<
                     0x14) >> 0x14);
    FUN_60099d8c(uVar2,sVar1);
    FUN_600f1e24(uVar2,sVar1);
  }
  return;
}


