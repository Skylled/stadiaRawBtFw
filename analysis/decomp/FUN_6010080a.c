// 6010080a  FUN_6010080a  size=64 bytes
// --- callers ---
//   6010088c FUN_6010088c
//   6010084a FUN_6010084a
// --- callees ---


bool FUN_6010080a(int param_1,code *param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((((param_1 == 0) || ((*(int *)(param_1 + 4) != 0 && (iVar2 = (*param_2)(), iVar2 == 0)))) ||
      ((*(int *)(param_1 + 8) != 0 && (iVar2 = (*param_2)(), iVar2 == 0)))) ||
     ((*(int *)(param_1 + 0xc) != 0 && (iVar2 = (*param_2)(), iVar2 == 0)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar2 = (*param_2)();
      bVar1 = iVar2 == 0;
    }
  }
  return bVar1;
}


