// 600dfd7e  FUN_600dfd7e  size=48 bytes
// --- callers ---
//   60055704 FUN_60055704
// --- callees ---
//   60083534 private_heap__60083534
//   600dfd6a FUN_600dfd6a


void FUN_600dfd7e(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  *param_1 = 0xffffffff;
  param_1[1] = param_2 + -0x20;
  param_1[2] = 0x10;
  uVar1 = FUN_600dfd6a();
  param_1[3] = uVar1;
  piVar2 = (int *)private_heap__60083534(param_1);
  piVar2[2] = 0x10;
  *piVar2 = param_2 + -0x20;
  piVar2[1] = -1;
  iVar3 = FUN_600dfd6a();
  piVar2[3] = iVar3;
  return;
}


