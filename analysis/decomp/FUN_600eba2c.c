// 600eba2c  FUN_600eba2c  size=188 bytes
// --- callers ---
//   600ebc36 FUN_600ebc36
//   6008deac FUN_6008deac
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e6996 FUN_600e6996
//   600e69ac FUN_600e69ac


void FUN_600eba2c(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,code *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  
  iVar7 = param_5;
  iVar8 = param_1;
  for (iVar4 = param_2; 0xf < (param_2 + param_3) - iVar4; iVar4 = iVar4 + 0x10) {
    iVar5 = 0;
    do {
      uVar1 = FUN_600e6996(iVar8 + iVar5);
      uVar2 = FUN_600e6996(iVar7 + iVar5);
      iVar3 = iVar4 + iVar5;
      iVar5 = iVar5 + 4;
      FUN_600e69ac(iVar3,uVar1 ^ uVar2);
    } while (iVar5 != 0x10);
    (*param_6)(iVar4,iVar4,param_4);
    iVar8 = iVar8 + 0x10;
    iVar7 = iVar4;
  }
  iVar4 = (param_3 >> 4) * 0x10;
  param_2 = param_2 + iVar4;
  iVar8 = (param_3 >> 4) * -0x10 + param_3;
  if (iVar8 != 0) {
    iVar5 = 0;
    do {
      *(byte *)(param_2 + iVar5) = *(byte *)(param_1 + iVar4 + iVar5) ^ *(byte *)(iVar7 + iVar5);
      iVar5 = iVar5 + 1;
    } while (iVar8 != iVar5);
    puVar9 = (undefined1 *)(iVar8 + param_2);
    for (puVar6 = (undefined1 *)(iVar7 + iVar8); (undefined1 *)(iVar7 + 0x10) != puVar6;
        puVar6 = puVar6 + 1) {
      *puVar9 = *puVar6;
      puVar9 = puVar9 + 1;
    }
    (*param_6)(param_2,param_2,param_4);
    iVar7 = param_2;
  }
  thunk_EXT_FUN_0000af88(param_5,iVar7,0x10);
  return;
}


