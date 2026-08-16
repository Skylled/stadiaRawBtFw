// 60041338  FUN_60041338  size=176 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60041338(uint param_1,uint param_2)

{
  undefined1 uVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  puVar3 = _DAT_600413e8;
  *(undefined1 *)(_DAT_600413e8 + 1) = 0;
  *(undefined1 *)((int)puVar3 + 5) = 0;
  iVar4 = _DAT_600413ec;
  *puVar3 = param_1;
  uVar1 = *(undefined1 *)(iVar4 + 0x1a);
  *(undefined1 *)((int)puVar3 + 7) = *(undefined1 *)(iVar4 + 0x1b);
  *(undefined1 *)((int)puVar3 + 6) = uVar1;
  iVar4 = _DAT_600413f0;
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((param_1 & 0x1f) != 0) {
    param_2 = param_2 + 0x20;
  }
  if ((param_2 & 0x1f) != 0) {
    param_2 = (param_2 & 0xffffffe0) + 0x20;
  }
  DataSynchronizationBarrier(0xf);
  iVar7 = (param_1 + 0x60000000 & 0xffffffe0) + param_2;
  for (uVar5 = param_2; 0 < (int)uVar5; uVar5 = uVar5 - 0x20) {
    *(uint *)(iVar4 + 0x268) = iVar7 - uVar5;
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  func_0x6004111c();
  iVar4 = func_0x60041090();
  if (((iVar4 == 0) && (iVar4 = func_0x60040cbc(_DAT_600413f4,_DAT_600413e8), iVar4 == 0)) &&
     (iVar4 = func_0x600410b4(), iVar4 == 0)) {
    func_0x60041164();
    iVar4 = _DAT_600413f0;
    DataSynchronizationBarrier(0xf);
    for (; 0 < (int)param_2; param_2 = param_2 - 0x20) {
      *(uint *)(iVar4 + 0x25c) = iVar7 - param_2;
    }
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    *(undefined4 *)(iVar4 + 0x250) = 0;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  return;
}


