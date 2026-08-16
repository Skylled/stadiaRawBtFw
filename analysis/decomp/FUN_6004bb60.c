// 6004bb60  FUN_6004bb60  size=34 bytes
// --- callers ---
//   60047974 tasks__60047974
//   6004970e FUN_6004970e
//   600478cc FUN_600478cc
//   60047aa8 tasks__60047aa8
//   60047f70 FUN_60047f70
//   60048014 tasks__60048014
//   60047e08 FUN_60047e08
//   60047d80 tasks__60047d80
// --- callees ---


int FUN_6004bb60(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  piVar3 = *(int **)(param_1 + 0x10);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 8);
  *(int *)(iVar2 + 4) = iVar1;
  if (piVar3[1] == param_1) {
    piVar3[1] = iVar2;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *piVar3 = *piVar3 + -1;
  return *piVar3;
}


