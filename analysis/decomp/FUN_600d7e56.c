// 600d7e56  FUN_600d7e56  size=80 bytes
// --- callers ---
// --- callees ---
//   6013d1b0 thunk_EXT_FUN_00006668
//   600e02a8 FUN_600e02a8
//   600ea74a FUN_600ea74a


undefined4 FUN_600d7e56(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_54;
  undefined1 auStack_50 [68];
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    return 0;
  }
  local_54 = 0;
  iVar2 = FUN_600ea74a(*(undefined4 *)(param_1 + 0xc),auStack_50,&local_54);
  iVar1 = local_54;
  if (iVar2 != 0) {
    if ((*(int *)(param_1 + 4) == 0) || (iVar2 = FUN_600e02a8(), iVar2 == 0)) {
      return 9;
    }
    uVar3 = FUN_600e02a8(*(undefined4 *)(param_1 + 4));
    iVar2 = thunk_EXT_FUN_00006668(uVar3,auStack_50,iVar1);
    if (-1 < iVar2) {
      if (iVar1 == iVar2) {
        return 0;
      }
      return 0xf;
    }
  }
  return 0xd;
}


