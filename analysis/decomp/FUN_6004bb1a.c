// 6004bb1a  FUN_6004bb1a  size=24 bytes
// --- callers ---
//   60047974 tasks__60047974
//   60047ce4 tasks__60047ce4
//   6004970e FUN_6004970e
//   600478cc FUN_600478cc
//   60047aa8 tasks__60047aa8
//   60047f70 FUN_60047f70
//   60048014 tasks__60048014
//   60047e08 FUN_60047e08
//   60047d3c tasks__60047d3c
//   60047d80 tasks__60047d80
// --- callees ---


void FUN_6004bb1a(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  uVar1 = *(undefined4 *)(iVar2 + 8);
  *(int *)(param_2 + 4) = iVar2;
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(int *)(*(int *)(iVar2 + 8) + 4) = param_2;
  *(int *)(iVar2 + 8) = param_2;
  iVar2 = *param_1;
  *(int **)(param_2 + 0x10) = param_1;
  *param_1 = iVar2 + 1;
  return;
}


