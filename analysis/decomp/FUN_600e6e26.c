// 600e6e26  FUN_600e6e26  size=174 bytes
// --- callers ---
// --- callees ---
//   600e22a2 FUN_600e22a2
//   600e22ee FUN_600e22ee
//   600e6b3a FUN_600e6b3a
//   600e6c88 FUN_600e6c88
//   600e6cf2 FUN_600e6cf2


void FUN_600e6e26(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint local_268 [5];
  undefined4 uStack_254;
  undefined4 local_250;
  uint local_24c;
  undefined1 auStack_248 [32];
  undefined1 auStack_228 [32];
  undefined1 auStack_208 [484];
  
  puVar6 = local_268;
  FUN_600e6b3a(auStack_208,param_4);
  puVar2 = param_5;
  do {
    puVar3 = puVar2 + 2;
    uVar1 = puVar2[1];
    *puVar6 = *puVar2;
    puVar6[1] = uVar1;
    puVar6 = puVar6 + 2;
    puVar2 = puVar3;
  } while (puVar3 != param_5 + 4);
  local_268[4] = *param_5;
  uStack_254 = param_5[1];
  local_250 = param_5[2];
  uVar5 = local_268[3] << 0x18 | (local_268[3] >> 8 & 0xff) << 0x10 |
          (local_268[3] >> 0x10 & 0xff) << 8 | local_268[3] >> 0x18;
  while( true ) {
    local_268[3] = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                   uVar5 >> 0x18;
    uVar4 = uVar5 + 1;
    uVar8 = param_3;
    if (1 < param_3) {
      uVar8 = 2;
    }
    local_24c = uVar4 * 0x1000000 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                uVar4 >> 0x18;
    FUN_600e6c88(auStack_228,local_268,uVar8);
    FUN_600e22a2(auStack_208,*(undefined4 *)(param_4 + 0xf0),auStack_228);
    FUN_600e6cf2(auStack_248,uVar8,auStack_228);
    for (iVar7 = 0; uVar8 * 0x10 != iVar7; iVar7 = iVar7 + 0x10) {
      FUN_600e22ee(param_2 + iVar7,param_1 + iVar7,auStack_248 + iVar7);
    }
    param_3 = param_3 - uVar8;
    if (param_3 == 0) break;
    param_1 = param_1 + 0x20;
    param_2 = param_2 + 0x20;
    uVar5 = uVar5 + 2;
  }
  return;
}


