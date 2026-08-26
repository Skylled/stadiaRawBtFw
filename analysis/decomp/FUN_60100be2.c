// 60100be2  FUN_60100be2  size=50 bytes
// --- callers ---
//   60101198 FUN_60101198
// --- callees ---
//   60100b96 FUN_60100b96
//   60100bb0 FUN_60100bb0


byte FUN_60100be2(int *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  param_2 = param_2 / *(uint *)(*(int *)(*param_1 + 4) + 4);
  iVar3 = param_1[param_2 + 0x1a];
  iVar2 = FUN_60100b96();
  if (iVar3 == iVar2) {
    bVar1 = FUN_60100bb0(param_1,param_2);
    bVar1 = bVar1 ^ 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}


