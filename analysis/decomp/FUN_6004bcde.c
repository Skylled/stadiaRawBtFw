// 6004bcde  FUN_6004bcde  size=10 bytes
// --- callers ---
//   60043608 FUN_60043608
// --- callees ---


undefined4 FUN_6004bcde(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  piVar5 = *(int **)(param_1 + 0x50);
  iStack_24 = -1;
  piVar6 = piVar5;
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (piVar5 == (int *)0x0) {
    thunk_FUN_601016a2(DAT_600477dc,0x570,DAT_600477d8,param_4,0);
  }
  if (piVar5[0x10] != 0) {
    thunk_FUN_601016a2(DAT_600477dc,0x574,DAT_600477d8,piVar5[0x10],piVar6);
  }
  iVar3 = FUN_60047f50();
  if ((iVar3 == 0) && (iStack_24 != 0)) {
    thunk_FUN_601016a2(DAT_600477dc,0x579,DAT_600477d8,iStack_24,piVar6);
  }
  puVar2 = DAT_600477e0;
  iVar3 = 0;
  bVar1 = false;
  while( true ) {
    FUN_60048580();
    if (piVar5[0xe] != 0) {
      piVar5[0xe] = piVar5[0xe] + -1;
      if (*piVar5 == 0) {
        iVar3 = FUN_600480b4();
        piVar5[1] = iVar3;
      }
      if ((piVar5[4] != 0) && (iVar3 = tasks__60047d80(piVar5 + 4), iVar3 != 0)) {
        *DAT_600477e0 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
      FUN_600485c8();
      return 1;
    }
    if (iStack_24 == 0) break;
    if (!bVar1) {
      FUN_60047e90(&uStack_20);
    }
    FUN_600485c8();
    FUN_60047958();
    FUN_60048580();
    if ((char)piVar5[0x11] == -1) {
      *(undefined1 *)(piVar5 + 0x11) = 0;
    }
    if (*(char *)((int)piVar5 + 0x45) == -1) {
      *(undefined1 *)((int)piVar5 + 0x45) = 0;
    }
    FUN_600485c8();
    iVar4 = tasks__60047ea8(&uStack_20,&iStack_24);
    if (iVar4 == 0) {
      iVar4 = FUN_6004bb82(piVar5);
      if (iVar4 == 0) {
        FUN_6004bc28(piVar5);
        tasks__60047aa8();
      }
      else {
        if (*piVar5 == 0) {
          FUN_60048580();
          iVar3 = FUN_60047f70(piVar5[1]);
          FUN_600485c8();
        }
        tasks__60047cac(piVar5 + 9,iStack_24);
        FUN_6004bc28(piVar5);
        iVar4 = tasks__60047aa8();
        if (iVar4 == 0) {
          *puVar2 = 0x10000000;
          DataSynchronizationBarrier(0xf);
          InstructionSynchronizationBarrier(0xf);
        }
      }
    }
    else {
      FUN_6004bc28(piVar5);
      tasks__60047aa8();
      iVar4 = FUN_6004bb82(piVar5);
      if (iVar4 != 0) {
        if (iVar3 == 0) {
          return 0;
        }
        FUN_60048580();
        iVar3 = 0;
        if (piVar5[9] != 0) {
          iVar3 = 0x20 - *(int *)piVar5[0xc];
        }
        tasks__600ca9e8(piVar5[1],iVar3);
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


