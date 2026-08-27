// 600cc518  FUN_600cc518  size=40 bytes
// --- callers ---
//   600cc5ac FUN_600cc5ac
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600cc518(void)

{
  bool bVar1;
  char cVar2;
  undefined4 unaff_r8;
  undefined4 in_cr14;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(*_DAT_e000ed08);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged(1);
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  enableIRQinterrupts();
  enableFIQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(0);
  coprocessor_store(0,in_cr14,unaff_r8);
  *DAT_600cc550 = *DAT_600cc550 | 0xf00000;
  return;
}


