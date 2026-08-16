// 60047678  queue__60047678  size=350 bytes
// src: queue.c
// --- callers ---
//   60046ffc FUN_60046ffc
//   6004b8ce FUN_6004b8ce
//   6004ba16 FUN_6004ba16
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   600480b4 FUN_600480b4
//   6004bc28 FUN_6004bc28
//   60047958 FUN_60047958
//   600485c8 FUN_600485c8
//   60047e90 FUN_60047e90
//   6004bb82 FUN_6004bb82
//   60047aa8 tasks__60047aa8
//   60047d80 tasks__60047d80
//   60047f50 FUN_60047f50
//   6004c1fc tasks__600ca9e8
//   60047f70 FUN_60047f70
//   60048580 FUN_60048580
//   60047cac tasks__60047cac
//   60047ea8 tasks__60047ea8


/* src: queue.c */

undefined4 queue__60047678(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  piVar5 = param_1;
  local_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (param_1 == (int *)0x0) {
    thunk_FUN_601016a2(DAT_600477dc,0x570,DAT_600477d8,param_4,0);
  }
  if (param_1[0x10] != 0) {
    thunk_FUN_601016a2(DAT_600477dc,0x574,DAT_600477d8,param_1[0x10],piVar5);
  }
  iVar3 = FUN_60047f50();
  if ((iVar3 == 0) && (local_24 != 0)) {
    thunk_FUN_601016a2(DAT_600477dc,0x579,DAT_600477d8,local_24,piVar5);
  }
  puVar2 = DAT_600477e0;
  iVar3 = 0;
  bVar1 = false;
  while( true ) {
    FUN_60048580();
    if (param_1[0xe] != 0) {
      param_1[0xe] = param_1[0xe] + -1;
      if (*param_1 == 0) {
        iVar3 = FUN_600480b4();
        param_1[1] = iVar3;
      }
      if ((param_1[4] != 0) && (iVar3 = tasks__60047d80(param_1 + 4), iVar3 != 0)) {
        *DAT_600477e0 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
      FUN_600485c8();
      return 1;
    }
    if (local_24 == 0) break;
    if (!bVar1) {
      FUN_60047e90(&uStack_20);
    }
    FUN_600485c8();
    FUN_60047958();
    FUN_60048580();
    if ((char)param_1[0x11] == -1) {
      *(undefined1 *)(param_1 + 0x11) = 0;
    }
    if (*(char *)((int)param_1 + 0x45) == -1) {
      *(undefined1 *)((int)param_1 + 0x45) = 0;
    }
    FUN_600485c8();
    iVar4 = tasks__60047ea8(&uStack_20,&local_24);
    if (iVar4 == 0) {
      iVar4 = FUN_6004bb82(param_1);
      if (iVar4 == 0) {
        FUN_6004bc28(param_1);
        tasks__60047aa8();
      }
      else {
        if (*param_1 == 0) {
          FUN_60048580();
          iVar3 = FUN_60047f70(param_1[1]);
          FUN_600485c8();
        }
        tasks__60047cac(param_1 + 9,local_24);
        FUN_6004bc28(param_1);
        iVar4 = tasks__60047aa8();
        if (iVar4 == 0) {
          *puVar2 = 0x10000000;
          DataSynchronizationBarrier(0xf);
          InstructionSynchronizationBarrier(0xf);
        }
      }
    }
    else {
      FUN_6004bc28(param_1);
      tasks__60047aa8();
      iVar4 = FUN_6004bb82(param_1);
      if (iVar4 != 0) {
        if (iVar3 == 0) {
          return 0;
        }
        FUN_60048580();
        iVar3 = 0;
        if (param_1[9] != 0) {
          iVar3 = 0x20 - *(int *)param_1[0xc];
        }
        tasks__600ca9e8(param_1[1],iVar3);
        goto LAB_60047712;
      }
    }
    bVar1 = true;
  }
  if (iVar3 != 0) {
    thunk_FUN_601016a2(DAT_600477dc,0x5c1,DAT_600477d8);
  }
LAB_60047712:
  FUN_600485c8();
  return 0;
}


