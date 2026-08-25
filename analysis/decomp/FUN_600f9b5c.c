// 600f9b5c  FUN_600f9b5c  size=242 bytes
// --- callers ---
//   600bbd3c FUN_600bbd3c
// --- callees ---


void FUN_600f9b5c(int param_1)

{
  int *local_10;
  int local_c;
  
  local_10 = (int *)0x0;
  if (*(int *)(param_1 + 300) != 0) {
    local_10 = (int *)(*(int *)(param_1 + 300) + 0x5c);
  }
  if ((*(char *)(param_1 + 5) != '\0') && (local_10 != (int *)0x0)) {
    if (*local_10 == 0) {
      local_10[1] = param_1;
      *local_10 = local_10[1];
      *(undefined4 *)(param_1 + 0x128) = 0;
      *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x128);
    }
    else {
      for (local_c = *local_10; local_c != 0; local_c = *(int *)(local_c + 0x124)) {
        if (*(byte *)(param_1 + 0xa4) < *(byte *)(local_c + 0xa4)) {
          if (local_c == *local_10) {
            *local_10 = param_1;
          }
          else {
            *(int *)(*(int *)(local_c + 0x128) + 0x124) = param_1;
          }
          *(int *)(param_1 + 0x124) = local_c;
          *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(local_c + 0x128);
          *(int *)(local_c + 0x128) = param_1;
          break;
        }
      }
      if (local_c == 0) {
        *(int *)(local_10[1] + 0x124) = param_1;
        *(undefined4 *)(param_1 + 0x124) = 0;
        *(int *)(param_1 + 0x128) = local_10[1];
        local_10[1] = param_1;
      }
    }
  }
  return;
}


