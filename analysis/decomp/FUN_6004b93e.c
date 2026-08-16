// 6004b93e  FUN_6004b93e  size=62 bytes
// --- callers ---
// --- callees ---
//   6004c3e4 thunk_FUN_6009257c


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6004b93e(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  do {
    ExclusiveAccess(param_1);
    iVar3 = *param_1;
    if (iVar3 != -1) goto LAB_6004b956;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = -2;
LAB_6004b956:
  if (iVar3 != -1) {
    while (iVar3 == -2) {
      thunk_FUN_6009257c();
      iVar3 = *param_1;
      DataMemoryBarrier(0x1b);
    }
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x6004be94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*_DAT_6004be98)();
  return uVar2;
}


