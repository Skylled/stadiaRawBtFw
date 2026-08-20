// 600e94ca  FUN_600e94ca  size=120 bytes
// --- callers ---
//   6008eb24 bcm__6008eb24
// --- callees ---
//   600e7554 FUN_600e7554
//   600e7718 FUN_600e7718
//   600e77c0 FUN_600e77c0
//   600e76ee FUN_600e76ee
//   6008b9f0 bcm__6008b9f0
//   6008b570 bcm__6008b570
//   6008b79c bcm__6008b79c


int FUN_600e94ca(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = param_1;
  uVar3 = param_2;
  FUN_600e7718(param_6);
  iVar1 = bcm__6008b570(param_6);
  if ((iVar1 != 0) &&
     (iVar2 = bcm__6008b9f0(iVar1,param_2,param_3,param_6,puVar4,uVar3), iVar2 != 0)) {
    iVar2 = bcm__6008b79c(0,iVar1,iVar1,param_4,param_6);
    if (iVar2 != 0) {
      uVar3 = FUN_600e76ee(iVar1);
      *param_1 = uVar3;
      if (param_5 == 0) {
        param_5 = 1;
      }
      else if ((*(int *)(param_3 + 0xc) != 0) || (iVar1 = FUN_600e7554(param_3,param_4), -1 < iVar1)
              ) {
        *param_1 = 0;
      }
      goto LAB_600e94ec;
    }
  }
  param_5 = 0;
LAB_600e94ec:
  FUN_600e77c0(param_6);
  return param_5;
}


