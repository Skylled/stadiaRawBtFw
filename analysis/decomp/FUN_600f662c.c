// 600f662c  FUN_600f662c  size=60 bytes
// --- callers ---
//   600f672a FUN_600f672a
//   600f6668 FUN_600f6668
// --- callees ---


void FUN_600f662c(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = (undefined4 *)param_1[1];
  *param_1 = 0;
  for (; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
    if (*(char *)(local_c + 3) != '\0') {
      *param_1 = local_c;
    }
  }
  return;
}


