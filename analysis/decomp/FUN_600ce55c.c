// 600ce55c  FUN_600ce55c  size=58 bytes
// --- callers ---
//   60051b50 stats__60051b50
//   60059280 FUN_60059280
// --- callees ---
//   600cc3cc FUN_600cc3cc
//   600cc4a8 FUN_600cc4a8
//   601019da FUN_601019da


int * FUN_600ce55c(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2[2];
  iVar1 = FUN_600cc3cc();
  if (iVar1 != 0) {
    uVar2 = FUN_600cc4a8(param_1,*param_2 + param_2[2],param_2[1] - param_2[2]);
    FUN_601019da(param_2,uVar2,iVar3,0x7d);
  }
  return param_2;
}


