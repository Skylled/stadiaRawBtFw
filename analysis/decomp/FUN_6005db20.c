// 6005db20  FUN_6005db20  size=150 bytes
// --- callers ---
//   60080fb8 FUN_60080fb8
//   6005dbbc FUN_6005dbbc
// --- callees ---
//   600d4550 FUN_600d4550
//   6013d378 thunk_EXT_FUN_0000b532
//   600d3b80 FUN_600d3b80
//   60101fd8 FUN_60101fd8


int * FUN_6005db20(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_1[1];
  uVar4 = param_3 + iVar5;
  if ((int *)*param_1 == param_1 + 2) {
    if (0xf < uVar4) {
      uVar2 = 0xf;
      goto LAB_6005dbac;
    }
  }
  else {
    uVar2 = param_1[2];
    if (uVar2 < uVar4) {
LAB_6005dbac:
      if ((int)uVar4 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_60101fd8(DAT_6005dbb8);
      }
      uVar2 = uVar2 * 2;
      uVar3 = uVar4;
      if ((uVar4 < uVar2) && (uVar3 = uVar2, (int)uVar2 < 0)) {
        uVar3 = 0x7fffffff;
      }
      iVar1 = thunk_EXT_FUN_0000b532(uVar3 + 1);
      if (iVar5 != 0) {
        FUN_600d3b80(iVar1,*param_1,iVar5);
      }
      if ((param_2 != 0) && (param_3 != 0)) {
        FUN_600d3b80(iVar1 + iVar5,param_2,param_3);
      }
      FUN_600d4550(param_1);
      *param_1 = iVar1;
      param_1[2] = uVar3;
      goto LAB_6005db4e;
    }
  }
  if (param_3 != 0) {
    FUN_600d3b80(*param_1 + iVar5,param_2,param_3);
  }
LAB_6005db4e:
  param_1[1] = uVar4;
  *(undefined1 *)(*param_1 + uVar4) = 0;
  return param_1;
}


