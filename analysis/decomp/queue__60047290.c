// 60047290  queue__60047290  size=326 bytes
// src: queue.c
// --- callers ---
//   60046ffc FUN_60046ffc
//   60042050 FUN_60042050
//   60048248 FUN_60048248
//   6004bab0 FUN_6004bab0
// --- callees ---
//   60047aa8 tasks__60047aa8
//   6004c084 thunk_FUN_601016a2
//   60047d80 tasks__60047d80
//   60047f50 FUN_60047f50
//   6004bb98 FUN_6004bb98
//   6004bc28 FUN_6004bc28
//   60047958 FUN_60047958
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8
//   60047e90 FUN_60047e90
//   60047cac tasks__60047cac
//   60047ea8 tasks__60047ea8


/* src: queue.c */

undefined4 queue__60047290(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_2c;
  int iStack_28;
  int iStack_24;
  
  iVar4 = param_1;
  local_2c = param_3;
  iStack_28 = param_3;
  iStack_24 = param_4;
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_600473dc,0x2db,DAT_600473d8,param_4,0);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    thunk_FUN_601016a2(DAT_600473dc,0x2dc,DAT_600473d8,*(int *)(param_1 + 0x40),iVar4);
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    thunk_FUN_601016a2(DAT_600473dc,0x2dd,DAT_600473d8,*(int *)(param_1 + 0x3c),iVar4);
  }
  iVar3 = FUN_60047f50();
  if ((iVar3 == 0) && (local_2c != 0)) {
    thunk_FUN_601016a2(DAT_600473dc,0x2e0,DAT_600473d8,local_2c,iVar4);
  }
  puVar2 = DAT_600473e0;
  bVar1 = false;
  while( true ) {
    FUN_60048580();
    if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
      iVar4 = FUN_6004bb98(param_1,param_2,param_4);
      if (*(int *)(param_1 + 0x24) != 0) {
        iVar4 = tasks__60047d80(param_1 + 0x24);
      }
      if (iVar4 != 0) {
        *DAT_600473e0 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
      FUN_600485c8();
      return 1;
    }
    if (local_2c == 0) {
      FUN_600485c8();
      return 0;
    }
    if (!bVar1) {
      FUN_60047e90(&iStack_28);
    }
    FUN_600485c8();
    FUN_60047958();
    FUN_60048580();
    if (*(char *)(param_1 + 0x44) == -1) {
      *(undefined1 *)(param_1 + 0x44) = 0;
    }
    if (*(char *)(param_1 + 0x45) == -1) {
      *(undefined1 *)(param_1 + 0x45) = 0;
    }
    FUN_600485c8();
    iVar4 = tasks__60047ea8(&iStack_28,&local_2c);
    if (iVar4 != 0) break;
    FUN_60048580();
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c)) {
      FUN_600485c8();
      tasks__60047cac(param_1 + 0x10,local_2c);
      FUN_6004bc28(param_1);
      iVar4 = tasks__60047aa8();
      if (iVar4 == 0) {
        *puVar2 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
    }
    else {
      FUN_600485c8();
      FUN_6004bc28(param_1);
      tasks__60047aa8();
    }
    bVar1 = true;
  }
  FUN_6004bc28(param_1);
  tasks__60047aa8();
  return 0;
}


