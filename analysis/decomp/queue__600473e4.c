// 600473e4  queue__600473e4  size=184 bytes
// src: queue.c
// --- callers ---
//   60042050 FUN_60042050
//   60048248 FUN_60048248
// --- callees ---
//   60048628 FUN_60048628
//   6004c084 thunk_FUN_601016a2
//   60047d80 tasks__60047d80
//   6004bb98 FUN_6004bb98


/* src: queue.c */

undefined4 queue__600473e4(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = param_4;
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_600474a0,0x3a1,DAT_6004749c,param_4,param_4);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    thunk_FUN_601016a2(DAT_600474a0,0x3a2,DAT_6004749c,*(int *)(param_1 + 0x40),iVar4);
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    thunk_FUN_601016a2(DAT_600474a0,0x3a3,DAT_6004749c,*(int *)(param_1 + 0x3c),iVar4);
  }
  FUN_60048628();
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  disableIRQinterrupts();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
    cVar1 = *(char *)(param_1 + 0x45);
    FUN_6004bb98(param_1,param_2,param_4);
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x24) != 0) && (iVar4 = tasks__60047d80(param_1 + 0x24), iVar4 != 0))
         && (param_3 != (undefined4 *)0x0)) {
        uVar3 = 1;
        *param_3 = 1;
        goto LAB_60047486;
      }
    }
    else {
      *(char *)(param_1 + 0x45) = cVar1 + '\x01';
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
LAB_60047486:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  return uVar3;
}


