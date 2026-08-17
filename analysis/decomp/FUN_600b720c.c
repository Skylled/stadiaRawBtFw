// 600b720c  FUN_600b720c  size=186 bytes
// --- callers ---
//   600b6900 FUN_600b6900
//   600b5264 FUN_600b5264
//   600b6d30 FUN_600b6d30
// --- callees ---
//   600bcf88 FUN_600bcf88
//   6006dfa4 FUN_6006dfa4


void FUN_600b720c(undefined2 *param_1,undefined2 *param_2)

{
  char *pcVar1;
  
  if (*(char *)(param_1 + 0x3f) == '\0') {
    *param_2 = *param_1;
    param_2[2] = param_2[2] + -4;
    param_2[1] = param_2[1] + 4;
    pcVar1 = (char *)((int)param_2 + (ushort)param_2[2] + 8);
    *pcVar1 = (char)param_2[1] + -4;
    pcVar1[1] = (char)((ushort)param_2[1] - 4 >> 8);
    pcVar1[2] = (char)param_1[1];
    pcVar1[3] = (char)((ushort)param_1[1] >> 8);
  }
  else {
    *param_2 = 0;
  }
  FUN_6006dfa4(param_1 + 0x98,param_2);
  FUN_600bcf88(param_1);
  if (*(short *)(*(int *)(param_1 + 0x96) + 0x1a) == 0) {
    *(undefined1 *)(DAT_600b72c8 + 8) = 1;
  }
  return;
}


