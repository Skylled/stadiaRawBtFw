// 600e7c2c  FUN_600e7c2c  size=160 bytes
// --- callers ---
//   600e7d98 FUN_600e7d98
//   6008b60c bcm__6008b60c
//   600e7f7a FUN_600e7f7a
//   6008bf44 bcm__6008bf44
//   600e7ecc FUN_600e7ecc
//   6008bbdc bcm__6008bbdc
//   600e91e6 FUN_600e91e6
//   600e7dc0 FUN_600e7dc0
//   600e863c FUN_600e863c
//   600e87fa FUN_600e87fa
//   600eb19c FUN_600eb19c
// --- callees ---


int FUN_600e7c2c(int *param_1,uint *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (; uVar2 = 0, (param_4 & 0xfffffffc) != 0; param_4 = param_4 - 4) {
      uVar3 = *param_2;
      uVar2 = *param_3;
      *param_1 = (uVar3 - uVar2) - iVar1;
      if (uVar3 != uVar2) {
        if (uVar3 < uVar2) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
      uVar3 = param_2[1];
      uVar2 = param_3[1];
      param_1[1] = (uVar3 - uVar2) - iVar1;
      if (uVar3 != uVar2) {
        if (uVar3 < uVar2) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
      uVar3 = param_2[2];
      uVar2 = param_3[2];
      param_1[2] = (uVar3 - uVar2) - iVar1;
      if (uVar3 != uVar2) {
        if (uVar3 < uVar2) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
      uVar3 = param_2[3];
      uVar2 = param_3[3];
      param_1[3] = (uVar3 - uVar2) - iVar1;
      if (uVar3 != uVar2) {
        if (uVar3 < uVar2) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
      param_2 = param_2 + 4;
      param_3 = param_3 + 4;
      param_1 = param_1 + 4;
    }
    for (; param_4 != uVar2; uVar2 = uVar2 + 1) {
      uVar4 = param_2[uVar2];
      uVar3 = param_3[uVar2];
      param_1[uVar2] = (uVar4 - uVar3) - iVar1;
      if (uVar4 != uVar3) {
        if (uVar4 < uVar3) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}


