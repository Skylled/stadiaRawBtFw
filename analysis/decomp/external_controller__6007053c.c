// 6007053c  external_controller__6007053c  size=180 bytes
// src: external_controller.cc
// --- callers ---
//   600658b4 haptics_cluster__600658b4
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010165c FUN_6010165c
//   6006543c FUN_6006543c
//   600d7cdc FUN_600d7cdc
//   6007014c FUN_6007014c


/* src: external_controller.cc */

void external_controller__6007053c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if (*DAT_600705f0 == '\0') {
    return;
  }
  local_14 = CONCAT22((short)param_2,(short)param_1);
  thunk_EXT_FUN_0000b4c2(DAT_600705f4);
  iVar2 = FUN_6007014c(0);
  if ((iVar2 != 0) && (iVar2 = FUN_6007014c(0), *(int *)(iVar2 + 4) != 0)) {
    iVar2 = FUN_6007014c(0);
    cVar1 = FUN_6006543c(*(undefined4 *)(iVar2 + 4),DAT_600705f8,&local_14,&stack0xfffffff8,param_1,
                         param_2,param_3);
    if ((cVar1 == '\x0e') && (iVar2 = FUN_6007014c(0), *(int *)(iVar2 + 8) != -1)) {
      iVar2 = FUN_6007014c(0);
      iVar3 = *(int *)(iVar2 + 8) + 1;
    }
    else {
      iVar2 = FUN_6007014c(0);
      if (*(int *)(iVar2 + 8) == 0) goto LAB_60070562;
      iVar2 = FUN_600d7cdc();
      if (iVar2 != 0) {
        iVar2 = FUN_6007014c(0);
        FUN_6010165c(0x1e,DAT_600705fc,0xca,DAT_60070600,*(undefined4 *)(iVar2 + 8));
        (*(code *)*DAT_60070604)(DAT_60070604[1],DAT_60070608);
      }
      iVar2 = FUN_6007014c(0);
      iVar3 = 0;
    }
    *(int *)(iVar2 + 8) = iVar3;
  }
LAB_60070562:
  thunk_EXT_FUN_00007d10(DAT_600705f4);
  return;
}


