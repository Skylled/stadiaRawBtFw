// 60099adc  FUN_60099adc  size=214 bytes
// --- callers ---
//   600f2378 FUN_600f2378
// --- callees ---
//   60099c0c FUN_60099c0c
//   600f03e2 FUN_600f03e2
//   60098f34 FUN_60098f34
//   600f033a FUN_600f033a


void FUN_60099adc(int param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined1 *local_24;
  
  sVar3 = (ushort)*(byte *)(param_1 + 2) * 0x100 + (ushort)*(byte *)(param_1 + 1);
  bVar1 = *(byte *)(param_1 + 3);
  bVar2 = *(byte *)(param_1 + 4);
  bVar4 = FUN_60098f34(sVar3);
  if ((bVar4 < 4) && (bVar2 < 3)) {
    iVar5 = (uint)bVar4 * 0x14c + 0x110 + DAT_60099bb4;
    local_24 = (undefined1 *)(param_1 + 5);
    for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {
      *(undefined1 *)((bVar1 + 0x21) * 8 + iVar5 + 6 + iVar6) = *local_24;
      local_24 = local_24 + 1;
    }
    if ((bVar1 < bVar2) && (bVar1 < 2)) {
      FUN_600f03e2(sVar3,bVar1 + 1);
    }
    else {
      FUN_600f033a(iVar5,bVar1 + 1);
      FUN_60099c0c(iVar5);
    }
  }
  return;
}


