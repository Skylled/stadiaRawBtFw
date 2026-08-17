// 60090cbc  tasn_utl__60090cbc  size=100 bytes
// src: tasn_utl.c
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
//   600902e4 FUN_600902e4
//   60090940 FUN_60090940
// --- callees ---
//   60091b94 FUN_60091b94
//   600e0552 FUN_600e0552
//   600ec514 FUN_600ec514


/* src: tasn_utl.c */

uint * tasn_utl__60090cbc(int *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if ((*param_2 & 0x300) != 0) {
    uVar5 = param_2[4];
    if (*(int *)(*param_1 + *(int *)(uVar5 + 4)) == 0) {
      puVar1 = *(uint **)(uVar5 + 0x18);
      puVar6 = param_2;
    }
    else {
      if ((int)(*param_2 << 0x17) < 0) {
        iVar2 = FUN_60091b94();
      }
      else {
        iVar2 = FUN_600ec514();
      }
      piVar3 = *(int **)(uVar5 + 0xc);
      for (iVar4 = 0; iVar4 < *(int *)(uVar5 + 0x10); iVar4 = iVar4 + 1) {
        if (*piVar3 == iVar2) {
          return (uint *)(piVar3 + 1);
        }
        piVar3 = piVar3 + 6;
      }
      puVar1 = *(uint **)(uVar5 + 0x14);
      puVar6 = param_2;
    }
    param_2 = puVar1;
    if (param_2 == (uint *)0x0) {
      if (param_3 != 0) {
        FUN_600e0552(0xc,0,0xba,DAT_60090d20,0x115,puVar6);
      }
      param_2 = (uint *)0x0;
    }
  }
  return param_2;
}


