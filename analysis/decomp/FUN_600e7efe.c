// 600e7efe  FUN_600e7efe  size=124 bytes
// --- callers ---
//   6008e700 bcm__6008e700
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e7766 FUN_600e7766
//   6008b43c bcm__6008b43c
//   600e7ecc FUN_600e7ecc
//   600e778c FUN_600e778c
//   600e7718 FUN_600e7718


undefined4
FUN_600e7efe(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  
  FUN_600e7718(param_5);
  puVar1 = (undefined4 *)FUN_600e778c(param_2,param_4[1],param_5);
  puVar2 = (undefined4 *)FUN_600e778c(param_3,param_4[1],param_5);
  puVar3 = (undefined4 *)FUN_600e7766(param_4[1],param_5);
  if ((((puVar1 == (undefined4 *)0x0) || (puVar2 == (undefined4 *)0x0)) ||
      (puVar3 == (undefined4 *)0x0)) || (iVar4 = bcm__6008b43c(param_1,param_4[1]), iVar4 == 0)) {
    uVar5 = 0;
  }
  else {
    FUN_600e7ecc(*param_1,*puVar1,*puVar2,*param_4,*puVar3,param_4[1]);
    uVar5 = 1;
    param_1[1] = param_4[1];
    param_1[3] = 0;
  }
  FUN_600e77c0(param_5,uVar5);
  return extraout_r1;
}


