// 600d2b6c  FUN_600d2b6c  size=68 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d2dba FUN_600d2dba
// --- callees ---
//   600d1692 FUN_600d1692
//   600d2b0e FUN_600d2b0e
//   600d16ae FUN_600d16ae


undefined4 FUN_600d2b6c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x18);
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  piVar2 = *(int **)(iVar3 + 8);
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  FUN_600d16ae(uVar1);
  while (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    uVar1 = FUN_600d2b0e(param_1,piVar2[9],piVar2[10]);
    if (*(char *)(param_2 + 0x13) == '\0') {
      uVar1 = piVar2[2];
    }
    piVar2[3] = uVar1;
    (*(code *)piVar2[4])(piVar2[5],piVar2,0xe,(code *)piVar2[4],param_4);
    piVar2 = (int *)iVar3;
  }
  return 0;
}


