// 60046e84  FUN_60046e84  size=74 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_60046e84(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (pcVar3 = *(code **)(*param_1 + 8), pcVar3 == (code *)0x0)) {
    uVar2 = 0x73;
    uVar4 = 0xa4;
  }
  else {
    if (param_1[1] != 0) {
      if (param_3 < 1) {
        return 0;
      }
      iVar1 = (*pcVar3)();
      if (iVar1 < 1) {
        return iVar1;
      }
      param_1[10] = param_1[10] + iVar1;
      return iVar1;
    }
    uVar2 = 0x72;
    uVar4 = 0xa8;
  }
  func_0x6004bf34(0x11,0,uVar2,_DAT_60046ed0,uVar4,param_2);
  return -2;
}


