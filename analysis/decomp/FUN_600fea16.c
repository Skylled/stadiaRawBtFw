// 600fea16  FUN_600fea16  size=180 bytes
// --- callers ---
// --- callees ---
//   600d922e FUN_600d922e
//   600d91bc FUN_600d91bc
//   600c6318 FUN_600c6318
//   600fe05a FUN_600fe05a
//   60094c5c FUN_60094c5c


void FUN_600fea16(undefined2 *param_1,int param_2)

{
  FUN_600d922e(*(int *)(param_1 + 8) + 1,0);
  if (((*(char *)(param_2 + 8) == '\0') || (*(char *)(param_2 + 8) == -0x76)) &&
     (*(short *)(param_2 + 10) != 0)) {
    FUN_60094c5c(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_2 + 10),param_2 + 0xc,
                 *(undefined2 *)(*(int *)(param_1 + 8) + 0x32));
    if (*(char *)(param_2 + 8) == '\0') {
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = 0;
      FUN_600c6318(*(undefined4 *)(param_1 + 8),0);
    }
    else {
      *(short *)(*(int *)(param_1 + 8) + 0x32) =
           *(short *)(param_2 + 10) + *(short *)(*(int *)(param_1 + 8) + 0x32);
      FUN_600d91bc(*(int *)(param_1 + 8) + 1,0x1d14,*(undefined2 *)(*(int *)(param_1 + 8) + 0x32),
                   *param_1);
    }
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 8) + 8) = 3;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = 0;
    FUN_600fe05a(param_1,0);
  }
  return;
}


