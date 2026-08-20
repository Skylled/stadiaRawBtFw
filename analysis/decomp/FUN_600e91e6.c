// 600e91e6  FUN_600e91e6  size=228 bytes
// --- callers ---
//   600e91e6 FUN_600e91e6
//   600e957c FUN_600e957c
// --- callees ---
//   600e8b7a FUN_600e8b7a
//   600e7c2c FUN_600e7c2c
//   600e91e6 FUN_600e91e6
//   600e7412 FUN_600e7412
//   600e7b96 FUN_600e7b96
//   600e7a32 FUN_600e7a32


void FUN_600e91e6(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_3 == 8) {
    FUN_600e8b7a();
    return;
  }
  if (param_3 < 0x10) {
    FUN_600e7b96();
    return;
  }
  uVar5 = param_3 >> 1;
  iVar8 = param_4 + param_3 * 8;
  iVar3 = param_2 + uVar5 * 4;
  iVar6 = param_4 + uVar5 * 4;
  iVar1 = FUN_600e7c2c(iVar6,param_2,iVar3,uVar5);
  FUN_600e7c2c(param_4,iVar3,param_2,uVar5);
  iVar7 = param_4 + param_3 * 4;
  FUN_600e7412(param_4,-iVar1,param_4,iVar6,uVar5);
  iVar1 = param_3 * 4 + param_1;
  FUN_600e91e6(iVar7,param_4,uVar5,iVar8);
  FUN_600e91e6(param_1,param_2,uVar5,iVar8);
  FUN_600e91e6(iVar1,iVar3,uVar5,iVar8);
  iVar1 = FUN_600e7a32(param_4,param_1,iVar1,param_3);
  iVar3 = FUN_600e7c2c(iVar7,param_4,iVar7,param_3);
  iVar6 = param_1 + uVar5 * 4;
  iVar6 = FUN_600e7a32(iVar6,iVar6,iVar7,param_3);
  uVar2 = (iVar6 + iVar1) - iVar3;
  for (uVar5 = uVar5 + param_3; uVar5 <= param_3 * 2 && param_3 * 2 - uVar5 != 0; uVar5 = uVar5 + 1)
  {
    uVar4 = *(uint *)(param_1 + uVar5 * 4);
    iVar1 = uVar2 + uVar4;
    uVar2 = (uint)CARRY4(uVar2,uVar4);
    *(int *)(param_1 + uVar5 * 4) = iVar1;
  }
  return;
}


