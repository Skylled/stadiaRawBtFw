// 600e7b96  FUN_600e7b96  size=150 bytes
// --- callers ---
//   600e957c FUN_600e957c
//   600e91e6 FUN_600e91e6
//   600e9680 FUN_600e9680
// --- callees ---
//   600e78a2 FUN_600e78a2
//   600e79cc FUN_600e79cc
//   600e7a32 FUN_600e7a32
//   600e77d4 FUN_600e77d4


void FUN_600e7b96(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = param_3 * 2;
  param_1[iVar7 + 0x3fffffff] = 0;
  *param_1 = 0;
  puVar2 = param_2;
  if (1 < param_3) {
    puVar2 = (undefined4 *)((param_3 + 0x3fffffff) * 4);
    uVar1 = FUN_600e78a2(param_1 + 1,param_2 + 1,param_3 - 1,*param_2,param_4,puVar2,param_3);
    (param_1 + 1)[param_3 + 0x3fffffff] = uVar1;
    if (param_3 != 2) {
      iVar4 = param_3 - 2;
      puVar3 = (undefined4 *)((int)(puVar2 + -2) + (int)(param_1 + 3));
      puVar5 = param_1 + 3;
      puVar6 = param_2 + 1;
      do {
        uVar1 = FUN_600e77d4(puVar5,puVar6 + 1,iVar4,*puVar6);
        iVar4 = iVar4 + -1;
        puVar3 = puVar3 + 1;
        *puVar3 = uVar1;
        puVar5 = puVar5 + 2;
        puVar6 = puVar6 + 1;
      } while (iVar4 != 0);
    }
  }
  FUN_600e7a32(param_1,param_1,param_1,iVar7,param_4,puVar2);
  FUN_600e79cc(param_4,param_2,param_3);
  FUN_600e7a32(param_1,param_1,param_4,iVar7);
  return;
}


