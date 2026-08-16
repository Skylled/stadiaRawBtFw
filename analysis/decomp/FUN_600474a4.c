// 600474a4  FUN_600474a4  size=154 bytes
// --- callers ---
// --- callees ---
//   60048628 FUN_60048628
//   6004c084 thunk_FUN_601016a2
//   60047d80 tasks__60047d80


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_600474a4(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (int *)0x0) {
    thunk_FUN_601016a2(_DAT_60047544,0x43e,_DAT_60047540);
  }
  if (param_1[0x10] != 0) {
    thunk_FUN_601016a2(_DAT_60047544,0x442,_DAT_60047540);
  }
  if ((*param_1 == 0) && (param_1[1] != 0)) {
    thunk_FUN_601016a2(_DAT_60047544,0x447,_DAT_60047540);
  }
  FUN_60048628();
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  if ((uint)param_1[0xe] < (uint)param_1[0xf]) {
    param_1[0xe] = param_1[0xe] + 1;
    if (*(char *)((int)param_1 + 0x45) == -1) {
      if (((param_1[9] != 0) && (iVar3 = tasks__60047d80(param_1 + 9), iVar3 != 0)) &&
         (param_2 != (undefined4 *)0x0)) {
        uVar2 = 1;
        *param_2 = 1;
        goto LAB_6004752a;
      }
    }
    else {
      *(char *)((int)param_1 + 0x45) = *(char *)((int)param_1 + 0x45) + '\x01';
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
LAB_6004752a:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  return uVar2;
}


