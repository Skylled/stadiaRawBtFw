// 600feaca  FUN_600feaca  size=78 bytes
// --- callers ---
// --- callees ---
//   600d922e FUN_600d922e
//   600c6318 FUN_600c6318
//   600ef0f4 FUN_600ef0f4


void FUN_600feaca(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_600ef0f4(*(undefined4 *)(param_1 + 8),*param_1,*(undefined4 *)(param_1 + 8),*param_1,
                       param_2);
  if (iVar1 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = 0;
    FUN_600d922e(*(int *)(param_1 + 8) + 1,0);
    FUN_600c6318(*(undefined4 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x1d));
  }
  return;
}


