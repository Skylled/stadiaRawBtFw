// 60041498  FUN_60041498  size=256 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60041498(uint param_1,uint param_2,uint param_3,undefined1 *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  iVar4 = _DAT_60041598;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar10 = param_3;
  if ((param_1 & 0x1f) != 0) {
    uVar10 = param_3 + 0x20;
  }
  if ((uVar10 & 0x1f) != 0) {
    uVar10 = (uVar10 & 0xffffffe0) + 0x20;
  }
  DataSynchronizationBarrier(0xf);
  iVar12 = (param_1 + 0x60000000 & 0xffffffe0) + uVar10;
  for (uVar9 = uVar10; iVar2 = _DAT_6004159c, 0 < (int)uVar9; uVar9 = uVar9 - 0x20) {
    *(uint *)(iVar4 + 0x268) = iVar12 - uVar9;
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  for (uVar9 = 0; iVar4 = _DAT_60041598, uVar9 < param_3; uVar9 = uVar9 + uVar11) {
    uVar3 = uVar9 + param_1;
    uVar11 = *(uint *)(iVar2 + 0x10);
    if ((*(char *)(iVar2 + 2) != '\0') && ((uVar3 & 0xf) != 0)) {
      uVar11 = 0x10;
    }
    puVar5 = (undefined1 *)(param_2 + uVar9);
    uVar11 = uVar11 - (uVar3 - uVar11 * (uVar3 / uVar11));
    if (param_3 - uVar9 <= uVar11) {
      uVar11 = param_3 - uVar9;
    }
    if ((0x5fffffff < param_2) && (param_2 < param_5 + 0x60000000U)) {
      puVar6 = puVar5;
      for (puVar7 = param_4; puVar5 = param_4, puVar7 != param_4 + uVar11; puVar7 = puVar7 + 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
      }
    }
    iVar4 = func_0x60041430(uVar3,puVar5,uVar11);
    if (iVar4 != 0) goto LAB_6004158c;
  }
  DataSynchronizationBarrier(0xf);
  for (; 0 < (int)uVar10; uVar10 = uVar10 - 0x20) {
    *(uint *)(iVar4 + 0x25c) = iVar12 - uVar10;
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar4 + 0x250) = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
LAB_6004158c:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar8 & 1) == 1);
  }
  return;
}


