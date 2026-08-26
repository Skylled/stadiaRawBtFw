// 6004b394  FUN_6004b394  size=142 bytes
// --- callers ---
//   60046de8 FUN_60046de8
// --- callees ---
//   6004b37c FUN_6004b37c


float FUN_6004b394(float param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float local_24 [2];
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[8]) {
      iVar3 = 5;
      local_24[0] = param_1;
      while (iVar2 = iVar3, 0 < iVar2) {
        iVar3 = iVar2 >> 1;
        iVar1 = FUN_6004b37c(param_2 + iVar3 * 2,local_24);
        if (iVar1 != 0) {
          param_2 = param_2 + iVar3 * 2 + 2;
          iVar3 = (iVar2 - iVar3) + -1;
        }
      }
      fVar4 = ((param_2[1] - param_2[-1]) * (param_1 - param_2[-2])) / (*param_2 - param_2[-2]) +
              param_2[-1];
    }
    else {
      fVar4 = param_2[9];
    }
  }
  else {
    fVar4 = param_2[1];
  }
  return fVar4;
}


