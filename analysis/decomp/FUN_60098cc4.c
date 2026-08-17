// 60098cc4  FUN_60098cc4  size=98 bytes
// --- callers ---
// --- callees ---
//   600a0bc4 FUN_600a0bc4


void FUN_60098cc4(short *param_1)

{
  char *local_10;
  char local_9;
  
  local_9 = -1;
  if ((*param_1 == -0x387) && (param_1[1] != 0)) {
    local_9 = **(char **)(param_1 + 2);
    local_10 = *(char **)(param_1 + 2) + 1;
  }
  if (local_9 == '\0') {
    if (*local_10 == '-') {
      *(undefined1 *)(DAT_60098d28 + 0x1113) = 1;
    }
  }
  FUN_600a0bc4();
  return;
}


