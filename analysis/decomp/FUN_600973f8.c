// 600973f8  FUN_600973f8  size=112 bytes
// --- callers ---
// --- callees ---
//   6009fa34 FUN_6009fa34


void FUN_600973f8(short *param_1)

{
  char *local_10;
  char local_9;
  
  local_9 = -1;
  if ((*param_1 == -0x2ad) && (param_1[1] != 0)) {
    local_9 = **(char **)(param_1 + 2);
    local_10 = *(char **)(param_1 + 2) + 1;
  }
  if (local_9 == '\0') {
    if ((local_10[4] != '\0') && (*(char *)(DAT_60097468 + 0xa6b) == '\0')) {
      FUN_6009fa34(local_10[4]);
    }
  }
  return;
}


