// 600dfb7e  FUN_600dfb7e  size=46 bytes
// --- callers ---
//   60082814 FUN_60082814
// --- callees ---
//   600dfb00 FUN_600dfb00


undefined4 FUN_600dfb7e(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while ((**(int **)(param_1 + 4) != param_2 || ((*(byte *)(*(int **)(param_1 + 4) + 1) & 0xf) == 8)
         )) {
    FUN_600dfb00(param_1);
    if (*(int *)(param_1 + 4) == iVar1) {
      return 0;
    }
  }
  return 1;
}


