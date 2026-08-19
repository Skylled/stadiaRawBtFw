// 600dadaa  FUN_600dadaa  size=50 bytes
// --- callers ---
//   6007694c FUN_6007694c
// --- callees ---
//   601019da FUN_601019da
//   600cc3cc FUN_600cc3cc
//   60050c18 FUN_60050c18


int * FUN_600dadaa(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  uVar2 = param_4;
  iVar1 = FUN_600cc3cc();
  if (iVar1 != 0) {
    uVar2 = FUN_60050c18(param_3,param_4,param_1[2] + *param_1,param_1[1] - param_1[2],uVar2);
    FUN_601019da(param_1,uVar2,iVar3,0x7d);
  }
  return param_1;
}


