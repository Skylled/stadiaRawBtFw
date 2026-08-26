// 6010196e  FUN_6010196e  size=22 bytes
// --- callers ---
//   60101aa4 FUN_60101aa4
//   601019da FUN_601019da
//   600cc450 FUN_600cc450
// --- callees ---


void FUN_6010196e(int *param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  *(undefined1 *)(*param_1 + iVar1) = param_2;
  *(undefined1 *)(*param_1 + param_1[2]) = 0;
  return;
}


