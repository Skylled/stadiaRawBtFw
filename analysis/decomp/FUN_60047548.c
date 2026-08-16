// 60047548  FUN_60047548  size=290 bytes
// --- callers ---
// --- callees ---
//   6004bb82 FUN_6004bb82
//   60047aa8 tasks__60047aa8
//   6004c084 thunk_FUN_601016a2
//   60047d80 tasks__60047d80
//   60047f50 FUN_60047f50
//   6004bc28 FUN_6004bc28
//   60047958 FUN_60047958
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8
//   60047e90 FUN_60047e90
//   60047cac tasks__60047cac
//   60047ea8 tasks__60047ea8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60047548(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iStack_2c;
  undefined1 auStack_28 [12];
  
  iStack_2c = param_3;
  if (param_1 == 0) {
    thunk_FUN_601016a2(_DAT_60047670,0x4de,_DAT_6004766c);
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    thunk_FUN_601016a2(_DAT_60047670,0x4e2,_DAT_6004766c);
  }
  iVar3 = FUN_60047f50();
  if ((iVar3 == 0) && (iStack_2c != 0)) {
    thunk_FUN_601016a2(_DAT_60047670,0x4e7,_DAT_6004766c);
  }
  puVar2 = _DAT_60047674;
  bVar1 = false;
  while( true ) {
    FUN_60048580();
    iVar3 = *(int *)(param_1 + 0x38);
    if (iVar3 != 0) {
      func_0x6004bbfe(param_1,param_2);
      *(int *)(param_1 + 0x38) = iVar3 + -1;
      if ((*(int *)(param_1 + 0x10) != 0) && (iVar3 = tasks__60047d80(param_1 + 0x10), iVar3 != 0))
      {
        *_DAT_60047674 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
      FUN_600485c8();
      return 1;
    }
    if (iStack_2c == 0) break;
    if (!bVar1) {
      FUN_60047e90(auStack_28);
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
    iVar3 = tasks__60047ea8(auStack_28,&iStack_2c);
    if (iVar3 == 0) {
      iVar3 = FUN_6004bb82(param_1);
      if (iVar3 == 0) {
        FUN_6004bc28(param_1);
        tasks__60047aa8();
      }
      else {
        tasks__60047cac(param_1 + 0x24,iStack_2c);
        FUN_6004bc28(param_1);
        iVar3 = tasks__60047aa8();
        if (iVar3 == 0) {
          *puVar2 = 0x10000000;
          DataSynchronizationBarrier(0xf);
          InstructionSynchronizationBarrier(0xf);
        }
      }
    }
    else {
      FUN_6004bc28(param_1);
      tasks__60047aa8();
      iVar3 = FUN_6004bb82(param_1);
      if (iVar3 != 0) {
        return 0;
      }
    }
    bVar1 = true;
  }
  FUN_600485c8();
  return 0;
}


