// 600dfe9e  FUN_600dfe9e  size=134 bytes
// --- callers ---
//   60083730 FUN_60083730
//   60051890 FUN_60051890
// --- callees ---
//   60083c78 FUN_60083c78
//   600615d4 FUN_600615d4


int FUN_600dfe9e(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar4 = param_2;
  uVar5 = param_3;
  iVar1 = FUN_600615d4();
  if (((param_2 & 0xfffffffe) == param_1) || (iVar3 = FUN_600615d4(param_2), iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_60083c78(param_2,param_3,param_4,param_5 + 1,param_6 + -1,uVar4,uVar5);
    if ((iVar3 < 1) && (iVar1 == 0)) {
      return iVar3;
    }
    *param_5 = param_1;
    iVar3 = iVar3 + 1;
  }
  iVar2 = iVar3;
  if ((iVar1 != 0) &&
     (iVar2 = FUN_60083c78(param_1,param_3,param_4,param_5,param_6,uVar4,uVar5), iVar2 < iVar3)) {
    *param_5 = param_1;
    iVar2 = FUN_60083c78(param_2,param_3,param_4,param_5 + 1,param_6 + -1,uVar4,uVar5);
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


