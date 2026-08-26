// 600d4652  FUN_600d4652  size=18 bytes
// --- callers ---
//   6005e58c bug_report__6005e58c
//   6005e3d0 bug_report__6005e3d0
// --- callees ---


int FUN_600d4652(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))();
  return *(int *)(param_1[1] + 4) * iVar1;
}


