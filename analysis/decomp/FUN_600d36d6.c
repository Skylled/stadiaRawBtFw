// 600d36d6  FUN_600d36d6  size=100 bytes
// --- callers ---
// --- callees ---
//   600d3664 FUN_600d3664


uint FUN_600d36d6(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  
  if (*param_1 < param_2) {
    if (param_2 < param_1[4]) {
      iVar4 = 3;
      local_1c = param_2;
      while (iVar3 = iVar4, 0 < iVar3) {
        iVar4 = iVar3 >> 1;
        iVar2 = FUN_600d3664(param_1 + iVar4 * 2,&local_1c);
        if (iVar2 != 0) {
          param_1 = param_1 + iVar4 * 2 + 2;
          iVar4 = (iVar3 - iVar4) + -1;
        }
      }
      uVar1 = (uint)*(byte *)(param_1 + -1) +
              (int)(((uint)*(byte *)(param_1 + 1) - (uint)*(byte *)(param_1 + -1)) *
                   (param_2 - param_1[-2])) / (*param_1 - param_1[-2]) & 0xff;
    }
    else {
      uVar1 = (uint)*(byte *)(param_1 + 5);
    }
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 1);
  }
  return uVar1;
}


