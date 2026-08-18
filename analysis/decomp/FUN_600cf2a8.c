// 600cf2a8  FUN_600cf2a8  size=22 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600cf2a8(undefined4 param_1,int param_2,int *param_3)

{
  if (*(char *)(param_2 + 0x2c) != '\0') {
    *param_3 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4);
    return 0;
  }
  return 6;
}


