// 600e7504  FUN_600e7504  size=68 bytes
// --- callers ---
//   600ece3c FUN_600ece3c
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90


undefined4 FUN_600e7504(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar7;
  byte *pbVar6;
  
  iVar4 = *param_3;
  uVar1 = param_3[1] * 4;
  if (param_2 <= uVar1 && uVar1 - param_2 != 0) {
    bVar2 = 0;
    pbVar6 = (byte *)(iVar4 + param_2);
    do {
      pbVar5 = pbVar6 + 1;
      bVar2 = bVar2 | *pbVar6;
      pbVar6 = pbVar5;
    } while (pbVar5 != (byte *)(uVar1 + iVar4));
    uVar1 = param_2;
    if (bVar2 != 0) {
      return 0;
    }
  }
  puVar7 = (undefined1 *)(param_1 + param_2);
  for (uVar3 = 0; uVar1 != uVar3; uVar3 = uVar3 + 1) {
    puVar7 = puVar7 + -1;
    *puVar7 = *(undefined1 *)(iVar4 + uVar3);
  }
  thunk_EXT_FUN_0000af90(param_1,0,param_2 - uVar1);
  return 1;
}


