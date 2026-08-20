// 600e70e2  FUN_600e70e2  size=312 bytes
// --- callers ---
// --- callees ---
//   600e22a2 FUN_600e22a2
//   600e22ee FUN_600e22ee
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600e6b3a FUN_600e6b3a
//   600e6c88 FUN_600e6c88
//   600e6f7a FUN_600e6f7a
//   600e6cf2 FUN_600e6cf2


void FUN_600e70e2(int param_1,undefined4 *param_2,uint param_3,int param_4,undefined4 *param_5,
                 int param_6)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 auStack_258 [12];
  undefined1 auStack_228 [32];
  undefined1 auStack_208 [484];
  
  param_3 = param_3 >> 4;
  if (param_3 != 0) {
    puVar6 = auStack_258;
    FUN_600e6b3a(auStack_208,param_4);
    puVar5 = param_5;
    puVar7 = puVar6;
    do {
      puVar4 = puVar5 + 2;
      uVar1 = puVar5[1];
      *puVar7 = *puVar5;
      puVar7[1] = uVar1;
      puVar7 = puVar7 + 2;
      puVar5 = puVar4;
    } while (puVar4 != param_5 + 4);
    if (param_6 == 0) {
      while( true ) {
        uVar8 = param_3;
        if (1 < param_3) {
          uVar8 = 2;
        }
        thunk_EXT_FUN_0000b572(auStack_258 + 4,param_1,uVar8 * 0x10);
        FUN_600e6c88(auStack_228,param_1,uVar8);
        FUN_600e6f7a(auStack_208,*(undefined4 *)(param_4 + 0xf0),auStack_228);
        FUN_600e6cf2(param_2,uVar8,auStack_228);
        FUN_600e22ee(param_2,param_2,puVar6);
        uVar3 = 1;
        while (uVar3 < uVar8) {
          FUN_600e22ee(param_2 + 4,param_2 + 4,auStack_258 + 4);
          uVar3 = 2;
        }
        param_3 = param_3 - uVar8;
        auStack_258[0] = puVar6[uVar8 * 4];
        auStack_258[1] = auStack_258[uVar8 * 4 + 1];
        auStack_258[2] = auStack_258[uVar8 * 4 + 2];
        auStack_258[3] = auStack_258[uVar8 * 4 + 3];
        if (param_3 == 0) break;
        param_1 = param_1 + 0x20;
        param_2 = param_2 + 8;
      }
      do {
        uVar1 = *puVar6;
        uVar2 = puVar6[1];
        puVar6 = puVar6 + 2;
        *param_5 = uVar1;
        param_5[1] = uVar2;
        param_5 = param_5 + 2;
      } while (puVar6 != auStack_258 + 4);
    }
    else {
      iVar9 = param_1 + param_3 * 0x10;
      do {
        FUN_600e22ee(puVar6,puVar6,param_1);
        FUN_600e6c88(auStack_228,extraout_r1,1);
        FUN_600e22a2(auStack_208,*(undefined4 *)(param_4 + 0xf0),auStack_228);
        FUN_600e6cf2(param_2,1,auStack_228);
        puVar5 = param_2;
        puVar7 = puVar6;
        do {
          puVar4 = puVar5 + 2;
          uVar1 = puVar5[1];
          *puVar7 = *puVar5;
          puVar7[1] = uVar1;
          puVar7 = puVar7 + 2;
          puVar5 = puVar4;
        } while (puVar4 != param_2 + 4);
        param_1 = param_1 + 0x10;
        param_2 = param_2 + 4;
      } while (param_1 != iVar9);
      do {
        uVar1 = *puVar6;
        uVar2 = puVar6[1];
        puVar6 = puVar6 + 2;
        *param_5 = uVar1;
        param_5[1] = uVar2;
        param_5 = param_5 + 2;
      } while (puVar6 != auStack_258 + 4);
    }
  }
  return;
}


