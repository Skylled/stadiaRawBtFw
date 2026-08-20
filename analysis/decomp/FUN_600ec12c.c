// 600ec12c  FUN_600ec12c  size=180 bytes
// --- callers ---
//   600ec31c FUN_600ec31c
// --- callees ---
//   6004cdb8 FUN_6004cdb8
//   6013cf28 thunk_EXT_FUN_0000af88


undefined4 FUN_600ec12c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (param_3 == 0) {
    return 1;
  }
  uVar3 = param_3 >> 0x1d;
  uVar1 = param_3 * 8;
  uVar4 = *(uint *)(param_1 + 0x40);
  uVar6 = *(uint *)(param_1 + 0x44);
  if (CARRY4(uVar6,uVar3) || CARRY4(uVar6 + uVar3,(uint)CARRY4(uVar4,uVar1))) {
    uVar5 = *(uint *)(param_1 + 0x48);
    *(uint *)(param_1 + 0x48) = uVar5 + 1;
    *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (uint)(0xfffffffe < uVar5);
  }
  iVar2 = *(int *)(param_1 + 0xd0);
  iVar7 = param_1 + 0x50;
  *(uint *)(param_1 + 0x40) = uVar4 + uVar1;
  *(uint *)(param_1 + 0x44) = uVar6 + uVar3 + CARRY4(uVar4,uVar1);
  if (iVar2 == 0) {
    if (0x7f < param_3) {
LAB_600ec1b6:
      FUN_6004cdb8(param_1,param_2,param_3 >> 7);
      uVar1 = param_3 & 0x7f;
      param_2 = param_2 + (param_3 - uVar1);
      goto LAB_600ec1ca;
    }
  }
  else {
    uVar1 = 0x80 - iVar2;
    if (param_3 < uVar1) {
      thunk_EXT_FUN_0000af88(iVar2 + iVar7,param_2,param_3);
      param_3 = param_3 + *(int *)(param_1 + 0xd0);
      goto LAB_600ec18c;
    }
    thunk_EXT_FUN_0000af88(iVar2 + iVar7,param_2,uVar1);
    param_3 = param_3 - uVar1;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    param_2 = param_2 + uVar1;
    FUN_6004cdb8(param_1,iVar7,1);
    uVar1 = param_3;
    if (0x7f < param_3) goto LAB_600ec1b6;
LAB_600ec1ca:
    param_3 = uVar1;
    if (uVar1 == 0) {
      return 1;
    }
  }
  thunk_EXT_FUN_0000af88(iVar7,param_2,param_3);
LAB_600ec18c:
  *(uint *)(param_1 + 0xd0) = param_3;
  return 1;
}


