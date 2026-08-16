// 600411dc  FUN_600411dc  size=330 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600411dc(uint param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar2 = _DAT_60041328;
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(_DAT_60041328 + 0x14) = *(uint *)(_DAT_60041328 + 0x14) & 0xfffdffff;
  *(undefined4 *)(iVar2 + 0x250) = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  DataSynchronizationBarrier(0xf);
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffeffff;
  DataSynchronizationBarrier(0xf);
  uVar11 = (*(uint *)(iVar2 + 0x80) & 0x1fff) >> 3;
  uVar8 = ((*(uint *)(iVar2 + 0x80) & 0xfffffff) >> 0xd) << 5;
  do {
    uVar7 = uVar11;
    uVar10 = uVar11 << 0x1e;
    do {
      uVar7 = uVar7 - 1;
      uVar12 = uVar8 & 0x3fe0 | uVar10;
      uVar10 = uVar10 + 0xc0000000;
      *(uint *)(iVar2 + 0x274) = uVar12;
      puVar6 = _DAT_60041334;
      puVar5 = _DAT_60041330;
      puVar4 = _DAT_6004132c;
    } while (uVar7 != 0xffffffff);
    uVar8 = uVar8 - 0x20;
  } while (uVar8 != 0xffffffe0);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *_DAT_6004132c = *_DAT_6004132c | 2;
  *puVar5 = *puVar5 & 0xfffff3ff;
  *puVar6 = (param_1 & 3) << 0x1d | *puVar6 & 0x9fffffff;
  func_0x6004114c(param_2);
  *puVar5 = *puVar5 | 0xc00;
  *puVar4 = *puVar4 & 0xfffffffd;
  func_0x60041164();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar2 + 0x250) = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x20000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  iVar3 = _DAT_60041328;
  DataSynchronizationBarrier(0xf);
  uVar11 = (*(uint *)(iVar2 + 0x80) & 0x1fff) >> 3;
  uVar8 = ((*(uint *)(iVar2 + 0x80) & 0xfffffff) >> 0xd) << 5;
  do {
    uVar7 = uVar11 << 0x1e;
    uVar10 = uVar11;
    do {
      uVar10 = uVar10 - 1;
      uVar12 = uVar8 & 0x3fe0 | uVar7;
      uVar7 = uVar7 + 0xc0000000;
      *(uint *)(iVar3 + 0x260) = uVar12;
    } while (uVar10 != 0xffffffff);
    uVar8 = uVar8 - 0x20;
  } while (uVar8 != 0xffffffe0);
  DataSynchronizationBarrier(0xf);
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar9 & 1) == 1);
  }
  return;
}


