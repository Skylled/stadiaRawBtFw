// 600ee0c8  FUN_600ee0c8  size=56 bytes
// --- callers ---
//   600e0c7e thunk_FUN_600ee0c8
//   60092528 FUN_60092528
// --- callees ---
//   6013cff0 thunk_EXT_FUN_00008844
//   6013d0f0 thunk_EXT_FUN_00007018


undefined4 FUN_600ee0c8(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(param_1);
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = 0;
  DataMemoryBarrier(0x1b);
  if (iVar2 != -1) {
    if ((iVar2 == 0) || (iVar2 == -2)) {
      return 0x16;
    }
    if (*(int *)(iVar2 + 0xc) != 0) {
      thunk_EXT_FUN_00007018();
    }
    thunk_EXT_FUN_00008844(iVar2);
  }
  return 0;
}


