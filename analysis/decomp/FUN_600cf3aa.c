// 600cf3aa  FUN_600cf3aa  size=24 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600cf3aa(undefined4 param_1,int param_2,int *param_3)

{
  if (*(char *)(param_2 + 0x2d) != '\x02') {
    *param_3 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10);
    return 0;
  }
  return 6;
}


