// 600ecb94  FUN_600ecb94  size=34 bytes
// --- callers ---
//   600ecc40 FUN_600ecc40
//   600ecc98 FUN_600ecc98
//   600ecbec FUN_600ecbec
//   600ecc0e FUN_600ecc0e
// --- callees ---


int FUN_600ecb94(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = *param_2;
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
        if ((*(uint *)(iVar2 + 4) & 2) != 0) {
          iVar1 = *(int *)(iVar2 + 0x10) + *param_1;
        }
      }
    }
  }
  return iVar1;
}


