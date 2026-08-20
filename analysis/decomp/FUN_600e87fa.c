// 600e87fa  FUN_600e87fa  size=510 bytes
// --- callers ---
//   600e87fa FUN_600e87fa
//   600e89f8 FUN_600e89f8
// --- callees ---
//   600e809a FUN_600e809a
//   600e87fa FUN_600e87fa
//   600e7c2c FUN_600e7c2c
//   600e863c FUN_600e863c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e7930 FUN_600e7930
//   600e7412 FUN_600e7412
//   600e80e2 FUN_600e80e2
//   600e7a32 FUN_600e7a32


void FUN_600e87fa(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar10 = param_4 * 2;
  if (param_4 < 8) {
    FUN_600e7930(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
    thunk_EXT_FUN_0000af90
              (param_1 + (param_5 + param_6 + iVar10) * 4,0,(iVar10 - param_5) - param_6);
    return;
  }
  iVar3 = param_2 + param_4 * 4;
  iVar8 = param_7 + param_4 * 8;
  uVar1 = FUN_600e809a(param_7,param_2,iVar3,param_5,param_4 - param_5,iVar8);
  iVar4 = param_4 * 4 + param_7;
  iVar5 = param_3 + param_4 * 4;
  uVar2 = FUN_600e809a(iVar4,iVar5,param_3,param_6,param_6 - param_4,iVar8);
  iVar9 = param_1 + param_4 * 8;
  iVar6 = param_4 * 0xc + iVar4;
  if (param_4 == 8) {
    FUN_600e80e2(iVar8,param_7);
    FUN_600e80e2(param_1,param_2,param_3);
    FUN_600e7930(iVar9,iVar3,param_5,iVar5,param_6);
    thunk_EXT_FUN_0000af90
              (param_1 + (param_5 + 0x10 + param_6) * 4,0,((0x10 - param_5) - param_6) * 4);
  }
  else {
    FUN_600e863c(iVar8,param_7,iVar4,param_4,0,0,iVar6);
    FUN_600e863c(param_1,param_2,param_3,param_4,0,0,iVar6);
    thunk_EXT_FUN_0000af90(iVar9,0,param_4 << 3);
    iVar4 = param_4;
    if ((param_5 < 0x10) && (param_6 < 0x10)) {
      FUN_600e7930(iVar9,iVar3,param_5,iVar5,param_6);
    }
    else {
      do {
        iVar4 = iVar4 / 2;
        if ((iVar4 < param_5) || (iVar4 < param_6)) {
          FUN_600e87fa(iVar9,iVar3,iVar5,iVar4,param_5 - iVar4,param_6 - iVar4,iVar6);
          goto LAB_600e88da;
        }
        iVar7 = param_5;
      } while ((param_5 != iVar4) && (iVar7 = param_6, param_6 != iVar4));
      FUN_600e863c(iVar9,iVar3,iVar5,iVar7,param_5 - iVar7,param_6 - iVar7,iVar6);
    }
  }
LAB_600e88da:
  iVar3 = FUN_600e7a32(param_7,param_1,iVar9,iVar10);
  iVar4 = FUN_600e7c2c(iVar6,param_7,iVar8,iVar10);
  iVar5 = FUN_600e7a32(iVar8,param_7,iVar8,iVar10);
  FUN_600e7412(iVar8,uVar1 ^ uVar2,iVar6,iVar8,iVar10);
  iVar6 = param_4 * 4 + param_1;
  iVar10 = FUN_600e7a32(iVar6,iVar6,iVar8,iVar10);
  uVar1 = iVar10 + ((iVar3 - iVar4 ^ iVar3 + iVar5) & (uVar1 ^ uVar2) ^ iVar3 + iVar5);
  for (iVar10 = param_4 * 3; iVar10 < param_4 * 4; iVar10 = iVar10 + 1) {
    uVar2 = *(uint *)(param_1 + iVar10 * 4);
    iVar3 = uVar1 + uVar2;
    uVar1 = (uint)CARRY4(uVar1,uVar2);
    *(int *)(param_1 + iVar10 * 4) = iVar3;
  }
  return;
}


