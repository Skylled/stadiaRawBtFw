// 600e9e24  FUN_600e9e24  size=248 bytes
// --- callers ---
//   600e9f1c FUN_600e9f1c
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88


bool FUN_600e9e24(int *param_1,int param_2,uint *param_3,int param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  uVar3 = *(uint *)(iVar2 + 0x14);
  if ((uVar3 & 0x400) == 0) {
    if ((int)param_5 < 1) {
      *param_3 = 0;
      return param_5 == 0;
    }
    iVar6 = param_1[0x16];
    iVar7 = param_4;
    if (iVar6 == 0) {
      if ((param_5 & param_1[0x19]) == 0) {
        iVar2 = (**(code **)(iVar2 + 0x20))(param_1,param_2,param_4,param_5);
        if (iVar2 == 0) {
          *param_3 = 0;
          return false;
        }
        *param_3 = param_5;
      }
      else {
        *param_3 = 0;
LAB_600e9ed6:
        uVar3 = param_1[0x19];
        uVar4 = param_5 & uVar3;
        iVar2 = param_5 - uVar4;
        if (0 < iVar2) {
          iVar6 = (**(code **)(*param_1 + 0x20))(param_1,param_2,param_4,iVar2);
          if (iVar6 == 0) goto LAB_600e9e48;
          uVar3 = *param_3 + iVar2;
          *param_3 = uVar3;
        }
        if (uVar4 != 0) {
          thunk_EXT_FUN_0000af88(param_1 + 0xe,param_4 + iVar2,uVar4,uVar3,iVar7);
        }
        param_1[0x16] = uVar4;
      }
    }
    else {
      uVar4 = *(uint *)(iVar2 + 4);
      iVar5 = uVar4 - iVar6;
      iVar2 = iVar6 + 0x38 + (int)param_1;
      if (iVar5 <= (int)param_5) {
        thunk_EXT_FUN_0000af88(iVar2,param_4,iVar5,uVar3,param_4);
        iVar2 = (**(code **)(*param_1 + 0x20))(param_1,param_2,param_1 + 0xe,uVar4);
        if (iVar2 == 0) goto LAB_600e9e48;
        param_5 = param_5 - iVar5;
        param_4 = param_4 + iVar5;
        param_2 = param_2 + uVar4;
        *param_3 = uVar4;
        goto LAB_600e9ed6;
      }
      thunk_EXT_FUN_0000af88(iVar2,param_4,param_5,uVar3,param_4);
      param_1[0x16] = param_5 + param_1[0x16];
      *param_3 = 0;
    }
LAB_600e9e50:
    bVar1 = true;
  }
  else {
    uVar3 = (**(code **)(iVar2 + 0x20))(param_1,param_2,param_4,param_5);
    if (-1 < (int)uVar3) {
      *param_3 = uVar3;
      goto LAB_600e9e50;
    }
LAB_600e9e48:
    bVar1 = false;
  }
  return bVar1;
}


