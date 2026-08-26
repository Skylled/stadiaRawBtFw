// 601024d8  FUN_601024d8  size=42 bytes
// --- callers ---
//   600d44b0 FUN_600d44b0
//   600c3558 FUN_600c3558
//   60083730 FUN_60083730
//   600c424c FUN_600c424c
//   600a62cc FUN_600a62cc
//   600a59d0 FUN_600a59d0
//   6006c2f4 FUN_6006c2f4
//   60065eb8 keys__60065eb8
//   600c5db0 FUN_600c5db0
//   6009fae0 FUN_6009fae0
//   6009a9c4 FUN_6009a9c4
//   600c4320 FUN_600c4320
//   600c3f04 FUN_600c3f04
//   600c43c4 FUN_600c43c4
//   60092e90 FUN_60092e90
//   600c4808 FUN_600c4808
//   600a10e0 FUN_600a10e0
//   600c3c00 FUN_600c3c00
//   600b0444 FUN_600b0444
//   600c5908 FUN_600c5908
//   600c4570 FUN_600c4570
//   600c5d3c FUN_600c5d3c
// --- callees ---


void FUN_601024d8(char *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar2 = (char *)(param_2 + -1);
  do {
    pcVar4 = param_1;
    iVar3 = param_3;
    if (iVar3 == 0) {
      return;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
    param_1 = pcVar4 + 1;
    *pcVar4 = cVar1;
    param_3 = iVar3 + -1;
  } while (cVar1 != '\0');
  for (; param_1 != pcVar4 + iVar3; param_1 = param_1 + 1) {
    *param_1 = '\0';
  }
  return;
}


