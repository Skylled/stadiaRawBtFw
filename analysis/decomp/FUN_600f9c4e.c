// 600f9c4e  FUN_600f9c4e  size=200 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
// --- callees ---


void FUN_600f9c4e(int param_1)

{
  int *local_c;
  
  local_c = (int *)0x0;
  if (*(int *)(param_1 + 300) != 0) {
    local_c = (int *)(*(int *)(param_1 + 300) + 0x5c);
  }
  if (((*(char *)(param_1 + 5) != '\0') && (local_c != (int *)0x0)) && (*local_c != 0)) {
    if (param_1 == *local_c) {
      *local_c = *(int *)(param_1 + 0x124);
      if (*local_c == 0) {
        local_c[1] = 0;
      }
      else {
        *(undefined4 *)(*local_c + 0x128) = 0;
      }
    }
    else if (param_1 == local_c[1]) {
      local_c[1] = *(int *)(param_1 + 0x128);
      *(undefined4 *)(local_c[1] + 0x124) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x124) = *(undefined4 *)(param_1 + 0x124);
      *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x128) = *(undefined4 *)(param_1 + 0x128);
    }
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x128);
  }
  return;
}


