// 60101302  FUN_60101302  size=88 bytes
// --- callers ---
//   6010138c FUN_6010138c
//   601013d0 FUN_601013d0
// --- callees ---


char FUN_60101302(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  cVar5 = '\0';
  for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 0x58); uVar4 = uVar4 + 1) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x54) + uVar4 * 4);
    if (((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0xc))(), iVar3 != 0)) &&
       ((*(int *)(param_1 + 0x60) == 0 || (*(byte *)(*(int *)(param_1 + 0x5c) + uVar4) <= param_4)))
       ) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x54) + uVar4 * 4);
      cVar1 = (**(code **)(*piVar2 + 8))(piVar2,param_2,param_3);
      if (cVar1 != '\0') {
        cVar5 = cVar1;
      }
    }
  }
  return cVar5;
}


