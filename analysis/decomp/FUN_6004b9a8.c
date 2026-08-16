// 6004b9a8  FUN_6004b9a8  size=56 bytes
// --- callers ---
//   6004b49c FUN_6004b49c
// --- callees ---
//   6004c3e4 thunk_FUN_6009257c


undefined4 FUN_6004b9a8(int param_1,code *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 4);
  do {
    ExclusiveAccess(piVar3);
    iVar2 = *piVar3;
    if (iVar2 != 0) goto LAB_6004b9c0;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = 1;
LAB_6004b9c0:
  if (iVar2 == 0) {
    (*param_2)();
    DataMemoryBarrier(0x1b);
    *(undefined4 *)(param_1 + 4) = 2;
  }
  else {
    while (iVar2 == 1) {
      thunk_FUN_6009257c();
      iVar2 = *piVar3;
      DataMemoryBarrier(0x1b);
    }
  }
  return 0;
}


