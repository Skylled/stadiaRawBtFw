// 600c9ef0  queue__600c9ef0  size=154 bytes
// src: queue.c
// --- callers ---
//   600cc000 FUN_600cc000
// --- callees ---
//   6013d108 thunk_EXT_FUN_00007e0c
//   601016a2 FUN_601016a2
//   6013cf68 thunk_EXT_FUN_0000b3e2
//   6013cf08 thunk_EXT_FUN_00007564


/* src: queue.c */

undefined4 queue__600c9ef0(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600c9f90,0x6dc,DAT_600c9f8c,param_4,param_4);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    FUN_601016a2(DAT_600c9f90,0x6dd,DAT_600c9f8c,*(int *)(param_1 + 0x40),param_4);
  }
  thunk_EXT_FUN_00007e0c();
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
  iVar4 = *(int *)(param_1 + 0x38);
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x44);
    thunk_EXT_FUN_0000b3e2(param_1,param_2);
    *(int *)(param_1 + 0x38) = iVar4 + -1;
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x10) != 0) &&
          (iVar4 = thunk_EXT_FUN_00007564(param_1 + 0x10), iVar4 != 0)) &&
         (param_3 != (undefined4 *)0x0)) {
        uVar3 = 1;
        *param_3 = 1;
        goto LAB_600c9f74;
      }
    }
    else {
      *(char *)(param_1 + 0x44) = cVar1 + '\x01';
    }
    uVar3 = 1;
  }
LAB_600c9f74:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  return uVar3;
}


