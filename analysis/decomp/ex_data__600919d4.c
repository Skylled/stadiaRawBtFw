// 600919d4  ex_data__600919d4  size=160 bytes
// src: ex_data.c
// --- callers ---
//   600910dc FUN_600910dc
//   600ebf76 bcm__600ebf76
//   6008ce00 FUN_6008ce00
//   600ea868 bcm__600ea868
//   6008ea5c FUN_6008ea5c
// --- callees ---
//   600edafe FUN_600edafe
//   600e0c82 FUN_600e0c82
//   600e0ab2 FUN_600e0ab2
//   600e0ae2 FUN_600e0ae2
//   600e0ab8 FUN_600e0ab8
//   600e0552 FUN_600e0552
//   600e0bfe FUN_600e0bfe
//   600e0c94 FUN_600e0c94


/* src: ex_data.c */

void ex_data__600919d4(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  
  if (*param_3 != 0) {
    uVar4 = param_2;
    piVar7 = param_3;
    FUN_600e0c82();
    iVar1 = FUN_600e0ab2(*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_600e0bfe(*(undefined4 *)(param_1 + 4));
    }
    FUN_600e0c94(param_1);
    uVar6 = 0;
    if (iVar1 != 0) {
      if (iVar2 == 0) {
        FUN_600e0552(0xe,0,0x41,DAT_60091a74,0xdd,uVar4,piVar7);
        return;
      }
      uVar6 = 0;
    }
    for (; uVar5 = FUN_600e0ab2(iVar2), uVar6 < uVar5; uVar6 = uVar6 + 1) {
      puVar3 = (undefined4 *)FUN_600e0ab8(iVar2,uVar6);
      if (puVar3[2] != 0) {
        uVar4 = FUN_600edafe(param_3,*(byte *)(param_1 + 8) + uVar6);
        (*(code *)puVar3[2])(param_2,uVar4,param_3,*(byte *)(param_1 + 8) + uVar6,*puVar3,puVar3[1])
        ;
      }
    }
    FUN_600e0ae2(iVar2);
    FUN_600e0ae2(*param_3);
    *param_3 = 0;
  }
  return;
}


