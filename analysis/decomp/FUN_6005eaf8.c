// 6005eaf8  FUN_6005eaf8  size=190 bytes
// --- callers ---
//   6005c07c FUN_6005c07c
// --- callees ---
//   600d45e8 FUN_600d45e8
//   600cc8f8 FUN_600cc8f8
//   6010138c FUN_6010138c
//   600cc984 FUN_600cc984
//   600cc450 FUN_600cc450
//   6010135a FUN_6010135a
//   60101a80 FUN_60101a80
//   60061d38 FUN_60061d38
//   600d46fe FUN_600d46fe
//   600cc3b4 FUN_600cc3b4


uint FUN_6005eaf8(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  pbVar1 = DAT_6005ebb8;
  DataMemoryBarrier(0x1b);
  if ((-1 < (int)((uint)*DAT_6005ebb8 << 0x1f)) && (iVar2 = FUN_600cc8f8(DAT_6005ebb8), iVar2 != 0))
  {
    FUN_600d46fe(DAT_6005ebbc);
    FUN_600cc984(pbVar1);
  }
  pbVar1 = DAT_6005ebc0;
  DataMemoryBarrier(0x1b);
  if ((-1 < (int)((uint)*DAT_6005ebc0 << 0x1f)) && (iVar2 = FUN_600cc8f8(DAT_6005ebc0), iVar2 != 0))
  {
    FUN_600d45e8(DAT_6005ebc8,DAT_6005ebc4,1);
    FUN_600cc984(pbVar1);
  }
  pbVar1 = DAT_6005ebcc;
  DataMemoryBarrier(0x1b);
  bVar6 = *DAT_6005ebcc & 1;
  if (((*DAT_6005ebcc & 1) == 0) && (iVar2 = FUN_600cc8f8(DAT_6005ebcc), iVar2 != 0)) {
    FUN_6010135a(DAT_6005ebd4,DAT_6005ebd0,bVar6,bVar6,DAT_6005ebbc,DAT_6005ebc8);
    FUN_600cc984(pbVar1);
  }
  iVar2 = DAT_6005ebd4;
  uVar3 = FUN_60101a80(DAT_6005ebbc);
  FUN_600cc450(uVar3,DAT_6005ebdc,DAT_6005ebd8);
  uVar4 = FUN_6010138c(iVar2,DAT_6005ebbc);
  if ((((uVar4 & 0xff) == 0) && (uVar4 = FUN_60061d38(iVar2), (uVar4 & 0xff) == 0)) &&
     ((iVar5 = FUN_600cc3b4(*(undefined4 *)(iVar2 + 0x14)), iVar5 != 0 ||
      (uVar4 = FUN_6010138c(iVar2,*(undefined4 *)(iVar2 + 0x14)), (uVar4 & 0xff) == 0)))) {
    uVar4 = 0;
  }
  return uVar4;
}


