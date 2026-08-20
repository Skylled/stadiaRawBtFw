// 600e99a2  FUN_600e99a2  size=116 bytes
// --- callers ---
//   6008eb24 bcm__6008eb24
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e98c6 FUN_600e98c6
//   6008b79c bcm__6008b79c
//   6008b9f0 bcm__6008b9f0
//   6008bf44 bcm__6008bf44
//   600e7718 FUN_600e7718
//   6008b570 bcm__6008b570


undefined4 FUN_600e99a2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_1c;
  
  uVar4 = param_1;
  uVar5 = param_2;
  uVar6 = param_3;
  local_1c = param_4;
  FUN_600e7718(param_4);
  iVar1 = bcm__6008b570(param_4);
  if ((((iVar1 == 0) ||
       (iVar2 = bcm__6008b9f0(param_1,param_2,param_3,param_4,uVar4,uVar5,uVar6), iVar2 == 0)) ||
      (iVar2 = bcm__6008bf44(iVar1,&local_1c,param_2,param_3,param_4), iVar2 == 0)) ||
     (iVar1 = bcm__6008b79c(param_1,0,param_1,iVar1,param_4), iVar1 == 0)) {
    bVar3 = false;
  }
  else {
    iVar1 = FUN_600e98c6(param_1,param_1,local_1c,param_4);
    bVar3 = iVar1 != 0;
  }
  FUN_600e77c0(param_4,bVar3);
  return extraout_r1;
}


