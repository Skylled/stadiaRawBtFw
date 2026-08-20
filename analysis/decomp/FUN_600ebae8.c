// 600ebae8  FUN_600ebae8  size=334 bytes
// --- callers ---
//   600ebc36 FUN_600ebc36
//   6008deac FUN_6008deac
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e6996 FUN_600e6996
//   600e69ac FUN_600e69ac


void FUN_600ebae8(uint param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,
                 code *param_6)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  int iVar13;
  uint uVar14;
  uint local_38 [5];
  
  uVar2 = param_1;
  uVar14 = param_2;
  uVar5 = param_5;
  if (((param_1 < 0x20) || (param_1 - 0x20 < param_2)) && (param_2 <= param_1)) {
    for (; 0xf < (param_1 + param_3) - uVar2; uVar2 = uVar2 + 0x10) {
      iVar9 = 0;
      (*param_6)(uVar2,local_38,param_4);
      do {
        uVar4 = FUN_600e6996(uVar2 + iVar9);
        uVar6 = *(uint *)((int)local_38 + iVar9);
        iVar11 = param_5 + iVar9;
        uVar5 = FUN_600e6996(iVar11);
        FUN_600e69ac(uVar14 + iVar9,uVar6 ^ uVar5);
        iVar9 = iVar9 + 4;
        FUN_600e69ac(iVar11,uVar4);
      } while (iVar9 != 0x10);
      uVar14 = uVar14 + 0x10;
    }
  }
  else {
    while (uVar6 = uVar2, 0xf < (param_1 + param_3) - uVar6) {
      (*param_6)(uVar6,uVar14,param_4);
      iVar9 = 0;
      do {
        uVar2 = FUN_600e6996(uVar14 + iVar9);
        uVar3 = FUN_600e6996(uVar5 + iVar9);
        FUN_600e69ac(uVar14 + iVar9,uVar2 ^ uVar3);
        iVar9 = iVar9 + 4;
      } while (iVar9 != 0x10);
      uVar14 = uVar14 + 0x10;
      uVar5 = uVar6;
      uVar2 = uVar6 + 0x10;
    }
    thunk_EXT_FUN_0000af88(param_5,uVar5,0x10);
  }
  iVar9 = (param_3 >> 4) * 0x10;
  iVar13 = (param_3 >> 4) * -0x10 + param_3;
  iVar11 = param_1 + iVar9;
  if (iVar13 != 0) {
    (*param_6)(iVar11,local_38,param_4);
    pbVar7 = (byte *)(param_5 - 1);
    iVar10 = 0;
    do {
      pbVar7 = pbVar7 + 1;
      bVar1 = *(byte *)(iVar11 + iVar10);
      *(byte *)(param_2 + iVar9 + iVar10) = *(byte *)((int)local_38 + iVar10) ^ *pbVar7;
      iVar10 = iVar10 + 1;
      *pbVar7 = bVar1;
    } while (iVar10 != iVar13);
    puVar12 = (undefined1 *)(param_5 + iVar10);
    for (puVar8 = (undefined1 *)(iVar11 + iVar10); (undefined1 *)(iVar11 + 0x10) != puVar8;
        puVar8 = puVar8 + 1) {
      *puVar12 = *puVar8;
      puVar12 = puVar12 + 1;
    }
  }
  return;
}


