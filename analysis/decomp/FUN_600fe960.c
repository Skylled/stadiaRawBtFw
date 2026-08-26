// 600fe960  FUN_600fe960  size=182 bytes
// --- callers ---
// --- callees ---
//   600d91bc FUN_600d91bc
//   600c6318 FUN_600c6318
//   600ef0f4 FUN_600ef0f4
//   600d922e FUN_600d922e
//   600fe05a FUN_600fe05a


void FUN_600fe960(undefined2 *param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(*(int *)(param_1 + 8) + 8) == '\x01') {
    if (*(char *)(param_2 + 8) == '\0') {
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = 0;
      FUN_600d91bc(*(int *)(param_1 + 8) + 1,0x1d14,*(undefined2 *)(*(int *)(param_1 + 8) + 0x32),
                   *param_1);
    }
    else {
      *(undefined1 *)(*(int *)(param_1 + 8) + 8) = 3;
      FUN_600fe05a(param_1,0);
    }
  }
  if (*(char *)(*(int *)(param_1 + 8) + 8) == '\x02') {
    if ((*(char *)(param_2 + 8) == '\0') &&
       (iVar1 = FUN_600ef0f4(*(undefined4 *)(param_1 + 8),*param_1), iVar1 == 0)) {
      *(undefined1 *)(param_2 + 8) = 0x85;
    }
    if (*(char *)(param_2 + 8) != '\0') {
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = 0;
      FUN_600d922e(*(int *)(param_1 + 8) + 1,*param_1);
      FUN_600c6318(*(undefined4 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x1d));
    }
  }
  return;
}


