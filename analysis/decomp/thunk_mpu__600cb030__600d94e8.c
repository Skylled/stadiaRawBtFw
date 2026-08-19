// 600d94e8  mpu__600cb030  size=4 bytes
// --- callers ---
//   6006ff00 FUN_6006ff00
// --- callees ---


void mpu__600cb030(void)

{
  bool bVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 auStack_a0 [33];
  
  thunk_EXT_FUN_0000b5ba(auStack_a0,0,0x80);
  iVar7 = DAT_600cb1e8;
  uVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar10 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(DAT_600cb1e8 + 0x14) = *(uint *)(DAT_600cb1e8 + 0x14) & 0xfffdffff;
  *(undefined4 *)(iVar7 + 0x250) = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar7 + 0x84) = 0;
  DataSynchronizationBarrier(0xf);
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) & 0xfffeffff;
  DataSynchronizationBarrier(0xf);
  uVar11 = (*(uint *)(iVar7 + 0x80) & 0x1fff) >> 3;
  uVar9 = ((*(uint *)(iVar7 + 0x80) & 0xfffffff) >> 0xd) << 5;
  do {
    uVar6 = uVar11 << 0x1e;
    uVar8 = uVar11;
    do {
      uVar8 = uVar8 - 1;
      uVar13 = uVar6 | uVar9 & 0x3fe0;
      uVar6 = uVar6 + 0xc0000000;
      *(uint *)(iVar7 + 0x274) = uVar13;
      uVar4 = DAT_600cb1f8;
      uVar3 = DAT_600cb1f4;
      puVar2 = DAT_600cb1ec;
    } while (uVar8 != 0xffffffff);
    uVar9 = uVar9 - 0x20;
  } while (uVar9 != 0xffffffe0);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(iVar7 + 0x24) = *(uint *)(iVar7 + 0x24) & 0xfffeffff;
  puVar2[1] = puVar2[1] & 0xfffffffe;
  uVar11 = *puVar2;
  for (uVar9 = 0; uVar9 != (uVar11 & 0xffff) >> 8; uVar9 = uVar9 + 1) {
    cVar5 = FUN_600cafcc(uVar9);
    if (cVar5 != '\0') {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar10 & 1) == 1);
      }
      FUN_601016a2(uVar4,0xc6,uVar3,uVar9);
    }
  }
  iVar7 = gotham_16mb_mimxrt10xx_mpu__6006f660(DAT_600cb1f0,auStack_a0);
  uVar4 = DAT_600cb1fc;
  uVar3 = DAT_600cb1f8;
  for (iVar12 = 0; iVar12 != iVar7; iVar12 = iVar12 + 1) {
    cVar5 = FUN_600cafec(iVar12,auStack_a0[iVar12 * 2],auStack_a0[iVar12 * 2 + 1]);
    if (cVar5 != '\0') {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar10 & 1) == 1);
      }
      FUN_601016a2(uVar3,0xd1,uVar4,iVar12);
    }
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  puVar2[1] = 1;
  iVar7 = DAT_600cb1e8;
  *(uint *)(DAT_600cb1e8 + 0x24) = *(uint *)(DAT_600cb1e8 + 0x24) | 0x10000;
  *(undefined4 *)(iVar7 + 0x84) = 0;
  DataSynchronizationBarrier(0xf);
  uVar11 = (*(uint *)(iVar7 + 0x80) & 0x1fff) >> 3;
  uVar9 = ((*(uint *)(iVar7 + 0x80) & 0xfffffff) >> 0xd) << 5;
  do {
    uVar6 = uVar11 << 0x1e;
    uVar8 = uVar11;
    do {
      uVar8 = uVar8 - 1;
      uVar13 = uVar9 & 0x3fe0 | uVar6;
      uVar6 = uVar6 + 0xc0000000;
      *(uint *)(iVar7 + 0x260) = uVar13;
    } while (uVar8 != 0xffffffff);
    uVar9 = uVar9 - 0x20;
  } while (uVar9 != 0xffffffe0);
  DataSynchronizationBarrier(0xf);
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar7 + 0x250) = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x20000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar10 & 1) == 1);
  }
  return;
}


