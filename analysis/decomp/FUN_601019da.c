// 601019da  FUN_601019da  size=56 bytes
// --- callers ---
//   600cbccc FUN_600cbccc
//   6007fe74 FUN_6007fe74
//   600d37ce FUN_600d37ce
//   6005e020 power_rpcs__6005e020
//   60083900 FUN_60083900
//   600d37fe FUN_600d37fe
//   6005dcc0 FUN_6005dcc0
//   600ce52c FUN_600ce52c
//   600ce4fc FUN_600ce4fc
//   6006185c FUN_6006185c
//   60061d38 FUN_60061d38
//   600ce55c FUN_600ce55c
//   60058318 FUN_60058318
//   600d3534 FUN_600d3534
//   600d4566 FUN_600d4566
//   600df072 FUN_600df072
//   600cc450 FUN_600cc450
//   600d38c8 FUN_600d38c8
//   6007f7a0 FUN_6007f7a0
//   600d3938 FUN_600d3938
//   600d398a FUN_600d398a
//   600dadaa FUN_600dadaa
// --- callees ---
//   6010196e FUN_6010196e
//   601019a6 FUN_601019a6


void FUN_601019da(int param_1,uint param_2)

{
  undefined4 uVar1;
  int extraout_r2;
  int iVar2;
  undefined4 extraout_r3;
  
  if ((int)param_2 < 0) {
    uVar1 = 3;
  }
  else if (param_2 < (uint)(*(int *)(param_1 + 4) - *(int *)(param_1 + 8))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  FUN_601019a6(param_1,uVar1);
  if (*(char *)(param_1 + 0xd) == '\0') {
    iVar2 = *(int *)(param_1 + 8) + param_2;
  }
  else {
    iVar2 = extraout_r2 + -1;
  }
  *(int *)(param_1 + 8) = iVar2;
  FUN_6010196e(param_1,extraout_r3);
  return;
}


