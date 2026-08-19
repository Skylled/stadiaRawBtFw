// 600d9644  FUN_600d9644  size=112 bytes
// --- callers ---
// --- callees ---
//   600d95c0 FUN_600d95c0


uint FUN_600d9644(byte *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_19;
  
  if (*param_1 < param_2) {
    if (param_2 < param_1[2]) {
      iVar4 = 2;
      while (iVar3 = iVar4, 0 < iVar3) {
        iVar4 = iVar3 >> 1;
        iVar2 = FUN_600d95c0(param_1 + iVar4 * 2,&local_19);
        if (iVar2 != 0) {
          param_1 = param_1 + iVar4 * 2 + 2;
          iVar4 = (iVar3 - iVar4) + -1;
        }
      }
      uVar1 = (((int)(char)param_1[1] - (int)(char)param_1[-1]) *
              ((int)(char)param_2 - (int)(char)param_1[-2])) /
              ((int)(char)*param_1 - (int)(char)param_1[-2]) + (uint)param_1[-1] & 0xff;
    }
    else {
      uVar1 = (uint)param_1[3];
    }
  }
  else {
    uVar1 = (uint)param_1[1];
  }
  return uVar1;
}


