// 6008c834  bcm__6008c834  size=276 bytes
// src: bcm.c
// --- callers ---
//   600e9fe2 FUN_600e9fe2
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e092c FUN_600e092c
//   600e9e02 FUN_600e9e02
//   600e0552 FUN_600e0552
//   6008c7f0 bcm__6008c7f0


/* src: bcm.c */

undefined4
bcm__6008c834(int *param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  if (param_6 == -1) {
    uVar5 = param_1[4];
  }
  else {
    uVar5 = (uint)(param_6 != 0);
    param_1[4] = uVar5;
  }
  if (param_2 == 0) {
    if (*param_1 == 0) {
      uVar4 = 0x72;
      uVar6 = 0xb3;
LAB_6008c8b0:
      FUN_600e0552(0x1e,0,uVar4,DAT_6008c950,uVar6);
      return 0;
    }
  }
  else {
    piVar3 = param_1;
    iVar2 = param_2;
    if (*param_1 != 0) {
      FUN_600e9e02(param_1);
      param_1[4] = uVar5;
    }
    iVar1 = *(int *)(param_2 + 0x10);
    *param_1 = param_2;
    if (iVar1 == 0) {
      param_1[2] = 0;
    }
    else {
      iVar1 = FUN_600e092c();
      param_1[2] = iVar1;
      if (iVar1 == 0) {
        *param_1 = 0;
        FUN_600e0552(0x1e,0,0x41,DAT_6008c950,0xa1);
        return 0;
      }
    }
    iVar1 = *(int *)(*param_1 + 0x14);
    param_1[3] = *(int *)(param_2 + 8);
    param_1[5] = 0;
    if ((iVar1 << 0x16 < 0) &&
       (iVar2 = bcm__6008c7f0(param_1,0,0,0,piVar3,iVar2,param_3), iVar2 == 0)) {
      uVar4 = 0x6b;
      *param_1 = 0;
      uVar6 = 0xae;
      goto LAB_6008c8b0;
    }
  }
  iVar2 = *param_1;
  if (-1 < (int)(*(uint *)(iVar2 + 0x14) << 0x17)) {
    switch(*(uint *)(iVar2 + 0x14) & 0x3f) {
    case 0:
    case 1:
      goto switchD_6008c8dc_caseD_0;
    case 3:
      param_1[0x17] = 0;
    case 2:
      piVar3 = param_1 + 6;
      if (param_5 != (int *)0x0) {
        thunk_EXT_FUN_0000af88(piVar3,param_5,*(undefined4 *)(iVar2 + 0xc));
      }
      uVar4 = *(undefined4 *)(*param_1 + 0xc);
      break;
    case 4:
    case 5:
      param_1[0x17] = 0;
      if (param_5 == (int *)0x0) goto switchD_6008c8dc_caseD_0;
      uVar4 = *(undefined4 *)(iVar2 + 0xc);
      piVar3 = param_5;
      break;
    default:
      return 0;
    }
    thunk_EXT_FUN_0000af88(param_1 + 10,piVar3,uVar4);
  }
switchD_6008c8dc_caseD_0:
  if (((param_4 == 0) && (-1 < *(int *)(*param_1 + 0x14) << 0x18)) ||
     (iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,param_4,param_5,uVar5), iVar2 != 0)) {
    uVar4 = 1;
    param_1[0x16] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = *(int *)(*param_1 + 4) + -1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


