// 600daec0  FUN_600daec0  size=42 bytes
// --- callers ---
//   60076e1c FUN_60076e1c
// --- callees ---


int FUN_600daec0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 + 4;
  iVar1 = iVar2;
  iVar3 = *(int *)(param_1 + 8);
  while (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x10) < *param_2) {
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar1 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
  }
  if ((iVar2 == iVar1) || (*param_2 < *(int *)(iVar1 + 0x10))) {
    iVar1 = iVar2;
  }
  return iVar1;
}


