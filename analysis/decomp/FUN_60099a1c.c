// 60099a1c  FUN_60099a1c  size=188 bytes
// --- callers ---
//   600f235e FUN_600f235e
// --- callees ---
//   60098f34 FUN_60098f34
//   60099c0c FUN_60099c0c
//   600f03e2 FUN_600f03e2
//   600f033a FUN_600f033a


void FUN_60099a1c(char *param_1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  char *local_24;
  
  if (*param_1 == '\0') {
    sVar1 = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
    bVar2 = FUN_60098f34(sVar1);
    if (bVar2 < 4) {
      iVar3 = (uint)bVar2 * 0x14c + 0x110 + DAT_60099ad8;
      local_24 = param_1 + 3;
      for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
        *(char *)(iVar3 + 0x10e + iVar4) = *local_24;
        local_24 = local_24 + 1;
      }
      if ((*(char *)(iVar3 + 0x115) < '\0') && ((*(byte *)(DAT_60099ad8 + 0x891) & 0x40) != 0)) {
        FUN_600f03e2(sVar1,1);
      }
      else {
        FUN_600f033a(iVar3,1);
        FUN_60099c0c(iVar3);
      }
    }
  }
  return;
}


