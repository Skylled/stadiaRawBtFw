// 6004901e  FUN_6004901e  size=38 bytes
// --- callers ---
//   60048e2a FUN_60048e2a
// --- callees ---
//   60048580 FUN_60048580


void FUN_6004901e(undefined1 *param_1)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if (uVar3 != 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
      uVar2 = (undefined1)uVar4;
    }
    disableIRQinterrupts();
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x50);
    }
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    enableIRQinterrupts();
    *param_1 = uVar2;
    return;
  }
  FUN_60048580();
  return;
}


