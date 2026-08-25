// 600f56fe  FUN_600f56fe  size=144 bytes
// --- callers ---
//   600f52ee FUN_600f52ee
//   600f539c FUN_600f539c
// --- callees ---


char FUN_600f56fe(int *param_1,int *param_2)

{
  char local_11;
  int *local_10;
  int *local_c;
  
  local_11 = '\0';
  if (*param_1 == 0) {
    local_11 = '\0';
  }
  else {
    local_c = (int *)*param_1;
    for (local_10 = (int *)*local_c; (local_c != (int *)0x0 && (local_10 != (int *)0x0));
        local_10 = (int *)*local_10) {
      if (local_10 == param_2) {
        *local_c = *local_10;
        local_11 = '\x01';
      }
      local_c = local_10;
    }
    if ((local_c == param_2) && (local_c == (int *)*param_1)) {
      *param_1 = *local_c;
      local_11 = '\x01';
    }
    if (local_11 != '\0') {
      *(short *)((int)param_1 + 0x1a) = *(short *)((int)param_1 + 0x1a) + -1;
    }
  }
  return local_11;
}


