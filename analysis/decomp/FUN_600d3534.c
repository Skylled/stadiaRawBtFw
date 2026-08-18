// 600d3534  FUN_600d3534  size=48 bytes
// --- callers ---
//   6005dcc0 FUN_6005dcc0
// --- callees ---
//   60050c18 FUN_60050c18
//   601019da FUN_601019da
//   600cc3cc FUN_600cc3cc


int * FUN_600d3534(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  iVar1 = FUN_600cc3cc();
  if (iVar1 != 0) {
    uVar2 = FUN_60050c18(param_3,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
    FUN_601019da(param_1,uVar2,iVar3,0x7d);
  }
  return param_1;
}


