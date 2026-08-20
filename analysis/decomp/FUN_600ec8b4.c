// 600ec8b4  FUN_600ec8b4  size=166 bytes
// --- callers ---
//   600902e4 FUN_600902e4
// --- callees ---
//   600ec6ba FUN_600ec6ba
//   600ec6a6 FUN_600ec6a6
//   600ec600 FUN_600ec600
//   600ec7ca FUN_600ec7ca


int FUN_600ec8b4(undefined4 param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_2c [2];
  
  local_2c[0] = *(int *)(param_3 + 4);
  iVar2 = FUN_600ec7ca(param_1,0,local_2c,param_3);
  if (local_2c[0] - 0x10U < 2) {
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (local_2c[0] != -3) {
      bVar1 = true;
    }
  }
  if (iVar2 == -1) {
    iVar2 = 0;
  }
  else {
    if (iVar2 == -2) {
      iVar3 = 2;
      iVar2 = 0;
    }
    else {
      iVar3 = 0;
    }
    if (param_4 == -1) {
      param_4 = local_2c[0];
    }
    if (param_2 != (int *)0x0) {
      if (bVar1) {
        FUN_600ec600(param_2,iVar3,iVar2,param_4,param_5);
      }
      FUN_600ec7ca(param_1,*param_2,local_2c,param_3);
      if (iVar3 == 0) {
        *param_2 = *param_2 + iVar2;
      }
      else {
        FUN_600ec6a6(param_2);
      }
    }
    if (bVar1) {
      iVar2 = FUN_600ec6ba(iVar3,iVar2,param_4);
    }
  }
  return iVar2;
}


