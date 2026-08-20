// 600e75de  FUN_600e75de  size=138 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   600e7668 FUN_600e7668
// --- callees ---
//   600e75c8 FUN_600e75c8
//   600e75c2 FUN_600e75c2
//   600e7668 FUN_600e7668
//   600e7434 FUN_600e7434
//   600e7372 FUN_600e7372


int FUN_600e75de(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_2 != 0) {
    iVar1 = FUN_600e75c2();
    if (iVar1 != 0) {
      iVar1 = FUN_600e7372(param_1,param_2);
      if (iVar1 == 0) {
        return 0;
      }
      FUN_600e75c8(param_1,1);
      return iVar1;
    }
    if (param_1[3] != 0) {
      param_1[3] = 0;
      iVar1 = FUN_600e7668(param_1,param_2);
      param_1[3] = 1;
      return iVar1;
    }
    iVar2 = FUN_600e7434(param_1);
    puVar4 = (uint *)*param_1;
    iVar1 = 0;
    if (iVar2 == 1) {
      uVar3 = *puVar4;
      if (uVar3 < param_2) {
        *puVar4 = param_2 - uVar3;
        param_1[3] = 1;
        return 1;
      }
    }
    else {
      while( true ) {
        uVar3 = *puVar4;
        if (param_2 <= uVar3) break;
        *puVar4 = uVar3 - param_2;
        iVar1 = iVar1 + 1;
        param_2 = 1;
        puVar4 = puVar4 + 1;
      }
    }
    *puVar4 = uVar3 - param_2;
    if ((uVar3 - param_2 == 0) && (param_1[1] + -1 == iVar1)) {
      param_1[1] = iVar1;
    }
  }
  return 1;
}


