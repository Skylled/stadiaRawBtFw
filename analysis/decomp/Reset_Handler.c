// 60040500  Reset_Handler  size=306 bytes
// --- callers ---
// --- callees ---
//   6006f634 FUN_6006f634
//   600520bc FUN_600520bc
//   6004072e FUN_6004072e
//   6004c700 FUN_6004c700


/* WARNING: Removing unreachable block (ram,0x600405f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Reset_Handler(void)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint extraout_r2;
  uint uVar8;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined2 *unaff_r6;
  undefined4 unaff_r8;
  undefined4 in_cr14;
  undefined8 uVar9;
  
  disableIRQinterrupts();
  if (_DAT_400f8034 == 1) {
    _DAT_400f8034 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setMainStackPointer(_DAT_00200000);
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
    InstructionSynchronizationBarrier(0xf);
                    /* WARNING: Could not recover jumptable at 0x6004072a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(DAT_60040810 + 0x28))();
    return uVar3;
  }
  _DAT_400ac040 = 0x200004;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  FUN_6006f634();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_400ac040 = 0x200007;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  puVar4 = &DAT_60040000;
  _DAT_e000ed08 = &DAT_60040000;
  bVar1 = (bool)isCurrentModePrivileged();
  uVar8 = DAT_60040000;
  if (bVar1) {
    setMainStackPointer(DAT_60040000);
  }
  do {
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
    FUN_600520bc(0x600520bd,puVar4,uVar8);
    if (_DAT_400f8034 != 0) {
      _DAT_400f8034 = 0;
      FUN_6004072e();
    }
    puVar4 = &DAT_6013d5a8;
    for (puVar6 = (undefined4 *)&DAT_20002740; (int)puVar6 < 0x20003fd8; puVar6 = puVar6 + 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    for (puVar6 = (undefined4 *)&DAT_20000000; (int)puVar6 < 0x20000000; puVar6 = puVar6 + 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    for (; (int)puVar6 < 0x20002740; puVar6 = puVar6 + 1) {
      *puVar6 = 0;
    }
    puVar4 = &DAT_6004081c;
    for (puVar6 = (undefined4 *)0x0; iVar7 = DAT_6004061c, puVar5 = DAT_60040618,
        (int)puVar6 < 0xbdf8; puVar6 = puVar6 + 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    for (; uVar3 = DAT_60040628, (int)puVar5 < iVar7; puVar5 = puVar5 + 1) {
      *puVar5 = 0;
    }
    iVar7 = DAT_60040624 + -0x40;
    for (puVar4 = DAT_60040620; (int)puVar4 < iVar7; puVar4 = puVar4 + 1) {
      *puVar4 = uVar3;
    }
    enableIRQinterrupts();
    uVar9 = (*DAT_6004062c)();
    puVar4 = (undefined4 *)((ulonglong)uVar9 >> 0x20);
    uVar3 = (undefined4)uVar9;
    *unaff_r6 = (short)unaff_r4;
    uVar8 = extraout_r2 & (uint)puVar4;
    coprocessor_store(0,in_cr14,unaff_r8);
    *(undefined4 *)uVar3 = uVar3;
    unaff_r4 = uVar3;
    _DAT_000000bd = unaff_r5;
  } while( true );
}


