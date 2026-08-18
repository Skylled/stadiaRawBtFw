// 600d2ace  FUN_600d2ace  size=64 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d2dba FUN_600d2dba
// --- callees ---
//   600d1692 FUN_600d1692
//   600d2a8e FUN_600d2a8e
//   600d16ae FUN_600d16ae


undefined4 FUN_600d2ace(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  piVar3 = *(int **)(param_2 + 8);
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  FUN_600d16ae(uVar1);
  while (piVar3 != (int *)0x0) {
    iVar4 = piVar3[2];
    iVar5 = *piVar3;
    iVar2 = FUN_600d2a8e(param_1,piVar3[9],piVar3[10]);
    piVar3[3] = iVar4 - iVar2;
    (*(code *)piVar3[4])(piVar3[5],piVar3,0xe,(code *)piVar3[4],param_4);
    piVar3 = (int *)iVar5;
  }
  return 0;
}


