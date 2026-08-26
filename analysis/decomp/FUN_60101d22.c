// 60101d22  FUN_60101d22  size=40 bytes
// --- callers ---
//   600d6866 FUN_600d6866
//   60076e1c FUN_60076e1c
//   600dae1c FUN_600dae1c
// --- callees ---


int FUN_60101d22(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar3 = *(int *)(param_1 + 4);
    while (iVar2 = iVar3, *(int *)(iVar2 + 0xc) == param_1) {
      param_1 = iVar2;
      iVar3 = *(int *)(iVar2 + 4);
    }
    if (iVar2 != *(int *)(param_1 + 0xc)) {
      param_1 = iVar2;
    }
  }
  else {
    do {
      piVar1 = (int *)(iVar3 + 8);
      param_1 = iVar3;
      iVar3 = *piVar1;
    } while (*piVar1 != 0);
  }
  return param_1;
}


