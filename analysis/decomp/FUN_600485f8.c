// 600485f8  FUN_600485f8  size=44 bytes
// --- callers ---
// --- callees ---
//   60047974 tasks__60047974


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600485f8(void)

{
  bool bVar1;
  int iVar2;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  iVar2 = tasks__60047974();
  if (iVar2 != 0) {
    *_DAT_60048624 = 0x10000000;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  return;
}


