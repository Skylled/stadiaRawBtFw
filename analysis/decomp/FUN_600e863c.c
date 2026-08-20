// 600e863c  FUN_600e863c  size=446 bytes
// --- callers ---
//   600e87fa FUN_600e87fa
//   600e863c FUN_600e863c
//   600e89f8 FUN_600e89f8
// --- callees ---
//   600e809a FUN_600e809a
//   600e7c2c FUN_600e7c2c
//   600e863c FUN_600e863c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e7930 FUN_600e7930
//   600e7412 FUN_600e7412
//   600e80e2 FUN_600e80e2
//   600e7a32 FUN_600e7a32


void FUN_600e863c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (param_4 == 8) {
    if ((param_5 == 0) && (param_6 == 0)) {
      FUN_600e80e2();
      return;
    }
  }
  else if (0xf < param_4) {
    iVar8 = param_4 >> 1;
    iVar10 = param_4 * 4;
    iVar9 = param_7 + iVar10;
    iVar3 = iVar8 * 4;
    iVar4 = param_2 + iVar3;
    uVar1 = FUN_600e809a(param_7,param_2,iVar4,param_5 + iVar8,-param_5,iVar9);
    iVar5 = iVar3 + param_7;
    iVar6 = param_3 + iVar3;
    uVar2 = FUN_600e809a(iVar5,iVar6,param_3,param_6 + iVar8,param_6,iVar9);
    iVar7 = param_1 + iVar10;
    iVar10 = iVar10 + iVar9;
    if (((iVar8 == 8) && (param_5 == 0)) && (param_6 == 0)) {
      FUN_600e80e2(iVar9,param_7,iVar5);
      FUN_600e80e2(param_1,param_2,param_3);
      FUN_600e80e2(iVar7,iVar4,iVar6);
    }
    else {
      FUN_600e863c(iVar9,param_7,iVar5,iVar8,0,0,iVar10);
      FUN_600e863c(param_1,param_2,param_3,iVar8,0,0,iVar10);
      FUN_600e863c(iVar7,iVar4,iVar6,iVar8,param_5,param_6,iVar10);
    }
    iVar4 = FUN_600e7a32(param_7,param_1,iVar7,param_4);
    iVar5 = FUN_600e7c2c(iVar10,param_7,iVar9,param_4);
    iVar6 = FUN_600e7a32(iVar9,param_7,iVar9,param_4);
    FUN_600e7412(iVar9,uVar1 ^ uVar2,iVar10,iVar9,param_4);
    iVar3 = FUN_600e7a32(iVar3 + param_1,iVar3 + param_1,iVar9,param_4);
    uVar1 = iVar3 + ((iVar4 - iVar5 ^ iVar4 + iVar6) & (uVar1 ^ uVar2) ^ iVar4 + iVar6);
    for (iVar8 = param_4 + iVar8; param_4 * 2 - iVar8 != 0 && iVar8 <= param_4 * 2;
        iVar8 = iVar8 + 1) {
      uVar2 = *(uint *)(param_1 + iVar8 * 4);
      iVar3 = uVar1 + uVar2;
      uVar1 = (uint)CARRY4(uVar1,uVar2);
      *(int *)(param_1 + iVar8 * 4) = iVar3;
    }
    return;
  }
  FUN_600e7930(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
  if (-1 < param_5 + param_6) {
    return;
  }
  thunk_EXT_FUN_0000af90
            (param_1 + (param_4 + param_4 + param_5 + param_6) * 4,0,(param_5 + param_6) * -4);
  return;
}


