// 600e9760  FUN_600e9760  size=126 bytes
// --- callers ---
//   600e98c6 FUN_600e98c6
//   600e97de FUN_600e97de
//   6008bb90 bcm__6008bb90
// --- callees ---
//   600e6a1a FUN_600e6a1a
//   6013cee8 thunk_EXT_FUN_0000af90


void FUN_600e9760(int param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar4 = param_3 >> 5;
  if (uVar4 < param_4) {
    iVar3 = uVar4 * 4;
    param_3 = param_3 & 0x1f;
    iVar5 = (param_4 - uVar4) * 4;
    puVar1 = (uint *)(param_2 + iVar3);
    if (param_3 == 0) {
      FUN_600e6a1a(param_1,puVar1,iVar5);
    }
    else {
      puVar6 = (uint *)(param_1 + -4);
      for (uVar2 = uVar4; uVar2 < param_4 - 1; uVar2 = uVar2 + 1) {
        uVar7 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar6 = puVar6 + 1;
        *puVar6 = *puVar1 << (0x20 - param_3 & 0xff) | uVar7 >> param_3;
      }
      *(uint *)(param_1 + ((param_4 + 0x3fffffff) - uVar4) * 4) =
           *(uint *)(param_2 + (param_4 + 0x3fffffff) * 4) >> param_3;
    }
    param_1 = param_1 + iVar5;
  }
  else {
    iVar3 = param_4 << 2;
  }
  thunk_EXT_FUN_0000af90(param_1,0,iVar3,param_4);
  return;
}


