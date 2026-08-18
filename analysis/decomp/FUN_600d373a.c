// 600d373a  FUN_600d373a  size=100 bytes
// --- callers ---
// --- callees ---
//   600d3672 FUN_600d3672


uint FUN_600d373a(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  
  if (*param_1 < param_2) {
    if (param_2 < param_1[2]) {
      iVar4 = 2;
      local_1c = param_2;
      while (iVar3 = iVar4, 0 < iVar3) {
        iVar4 = iVar3 >> 1;
        iVar2 = FUN_600d3672(param_1 + iVar4 * 2,&local_1c);
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
      uVar1 = (uint)*(byte *)(param_1 + 3);
    }
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 1);
  }
  return uVar1;
}


