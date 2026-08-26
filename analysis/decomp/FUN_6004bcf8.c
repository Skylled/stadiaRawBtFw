// 6004bcf8  FUN_6004bcf8  size=46 bytes
// --- callers ---
//   6004bd26 FUN_6004bd26
// --- callees ---


void FUN_6004bcf8(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = (param_1[1] + -1) - param_1[2];
  uVar1 = uVar2;
  if (param_2 <= uVar2) {
    uVar1 = param_2;
  }
  bVar4 = uVar2 < param_2;
  iVar3 = param_1[2] + uVar1;
  if (bVar4) {
    uVar2 = 8;
  }
  param_1[2] = iVar3;
  *(undefined1 *)(*param_1 + iVar3) = 0;
  if (bVar4) {
    *(char *)((int)param_1 + 0xd) = (char)uVar2;
    *(char *)(param_1 + 3) = (char)uVar2;
  }
  else {
    *(undefined1 *)((int)param_1 + 0xd) = 0;
  }
  return;
}


