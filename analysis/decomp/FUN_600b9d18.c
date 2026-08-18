// 600b9d18  FUN_600b9d18  size=120 bytes
// --- callers ---
//   60096a50 FUN_60096a50
// --- callees ---


undefined4 FUN_600b9d18(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  iVar1 = *(int *)(DAT_600b9d90 + 0xec8);
  if ((iVar1 == 0) || (iVar2 = *(int *)(iVar1 + 0x8c), iVar2 == 0)) {
    uVar3 = 1;
  }
  else {
    pbVar4 = (byte *)((uint)*(ushort *)(iVar2 + 4) + iVar2 + 0xc);
    if ((int)(*(ushort *)(iVar2 + 2) - 8) <
        (int)(uint)(ushort)((ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4)) {
      uVar3 = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x8c) = 0;
      uVar3 = 1;
    }
  }
  return uVar3;
}


