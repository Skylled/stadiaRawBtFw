// 600b9d94  FUN_600b9d94  size=144 bytes
// --- callers ---
//   600a9f10 FUN_600a9f10
// --- callees ---
//   6006e008 FUN_6006e008
//   6006ddd8 FUN_6006ddd8
//   600b9408 FUN_600b9408
//   600bcbe0 FUN_600bcbe0


void FUN_600b9d94(int param_1)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 4));
  iVar1 = FUN_600bcbe0((ushort)(((uint)(ushort)((ushort)pbVar2[1] * 0x100 + (ushort)*pbVar2) << 0x14
                                ) >> 0x14));
  if (iVar1 == 0) {
    FUN_6006ddd8(param_1,DAT_600b9e24,0x84b);
  }
  else if (*(char *)(iVar1 + 1) == '\x04') {
    FUN_6006e008(iVar1 + 0x80,param_1);
    *(undefined1 *)(iVar1 + 0xa2) = 0;
    FUN_600b9408(iVar1,0,0);
  }
  else {
    FUN_6006ddd8(param_1,DAT_600b9e24,0x85e);
  }
  return;
}


