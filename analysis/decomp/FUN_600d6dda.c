// 600d6dda  FUN_600d6dda  size=58 bytes
// --- callers ---
//   60074658 timer__60074658
//   60080fb8 FUN_60080fb8
//   60065d80 FUN_60065d80
//   6005d3b4 thermal__6005d3b4
// --- callees ---
//   600653f8 FUN_600653f8
//   600653f0 FUN_600653f0


undefined4 * FUN_600d6dda(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = FUN_600653f8();
  *param_1 = uVar1;
  piVar2 = (int *)FUN_600653f0();
  iVar5 = 0;
  do {
    if (piVar2[1] == iVar5) {
      iVar5 = 0;
LAB_600d6e06:
      param_1[1] = iVar5;
      return param_1;
    }
    piVar4 = *(int **)(*piVar2 + iVar5 * 4);
    iVar3 = *piVar4;
    if ((*(char *)(iVar3 + 8) == '\x05') && (*(char *)(iVar3 + 9) == '\x01')) {
      iVar5 = piVar4[2];
      goto LAB_600d6e06;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


