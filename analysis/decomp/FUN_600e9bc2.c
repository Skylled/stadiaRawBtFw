// 600e9bc2  FUN_600e9bc2  size=410 bytes
// --- callers ---
//   600e9d5c FUN_600e9d5c
// --- callees ---
//   600e6a6c FUN_600e6a6c
//   600e93ca FUN_600e93ca
//   600e9ba8 FUN_600e9ba8
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e7276 FUN_600e7276
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   600e96c6 FUN_600e96c6


void FUN_600e9bc2(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar7;
  undefined1 *puVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  undefined1 auStack_4ac [68];
  undefined1 auStack_468 [68];
  undefined1 auStack_424 [1024];
  int iVar6;
  
  piVar3 = (int *)(param_4 + param_5 * 4);
  while( true ) {
    if (param_5 == 0) {
      FUN_600e93ca(param_1,*param_6,param_3);
      return;
    }
    piVar3 = piVar3 + -1;
    if (*piVar3 != 0) break;
    param_5 = param_5 + -1;
  }
  iVar1 = FUN_600e7276();
  iVar1 = iVar1 + (param_5 + 0x7ffffff) * 0x20;
  uVar2 = FUN_600e6a6c(iVar1);
  uVar4 = uVar2;
  if (4 < uVar2) {
    uVar4 = 5;
  }
  thunk_EXT_FUN_0000af88(auStack_468,param_2,param_3 << 2);
  if (1 < uVar2) {
    FUN_600e96c6(auStack_4ac,auStack_468,auStack_468,param_3,param_6);
    iVar6 = 0;
    while (iVar5 = iVar6 + 0x44, iVar5 != 0x44 << (uVar4 - 1 & 0xff)) {
      FUN_600e96c6(auStack_468 + iVar5,auStack_468 + iVar6,auStack_4ac,param_3,param_6);
      iVar6 = iVar5;
    }
  }
  uVar2 = iVar1 - 1;
  bVar9 = true;
  while( true ) {
    while (iVar1 = FUN_600e9ba8(param_4,param_5,uVar2), iVar1 != 0) {
      uVar11 = 1;
      uVar7 = 0;
      for (uVar10 = 1; (uVar10 < uVar4 && (uVar10 <= uVar2)); uVar10 = uVar10 + 1) {
        iVar1 = FUN_600e9ba8(param_4,param_5,uVar2 - uVar10);
        if (iVar1 != 0) {
          uVar11 = uVar11 << (uVar10 - uVar7 & 0xff) | 1;
          uVar7 = uVar10;
        }
      }
      puVar8 = auStack_468 + (uVar11 >> 1) * 0x44;
      if (bVar9) {
        thunk_EXT_FUN_0000af88(param_1,puVar8,param_3 << 2);
      }
      else {
        for (uVar10 = 0; uVar10 < uVar7 + 1; uVar10 = uVar10 + 1) {
          FUN_600e96c6(param_1,param_1,param_1,param_3,param_6);
        }
        FUN_600e96c6(param_1,param_1,puVar8,param_3,param_6);
      }
      if (uVar2 == uVar7) goto LAB_600e9d22;
      bVar9 = false;
      uVar2 = (uVar2 - 1) - uVar7;
    }
    if (!bVar9) {
      FUN_600e96c6(param_1,param_1,param_1,param_3,param_6);
    }
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
  }
LAB_600e9d22:
  thunk_EXT_FUN_0000ac52(auStack_468,0x440);
  return;
}


