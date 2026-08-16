// 6004b9e0  FUN_6004b9e0  size=54 bytes
// --- callers ---
//   6004bab0 FUN_6004bab0
//   6004baa8 FUN_6004baa8
// --- callees ---
//   6004c3e4 thunk_FUN_6009257c


undefined4 FUN_6004b9e0(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  do {
    ExclusiveAccess(param_1);
    iVar3 = *param_1;
    if (iVar3 != -1) goto LAB_6004b9f8;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = -2;
LAB_6004b9f8:
  if (iVar3 == -1) {
    uVar2 = 0;
  }
  else {
    while (iVar3 == -2) {
      thunk_FUN_6009257c();
      iVar3 = *param_1;
      DataMemoryBarrier(0x1b);
    }
    uVar2 = 1;
  }
  return uVar2;
}


