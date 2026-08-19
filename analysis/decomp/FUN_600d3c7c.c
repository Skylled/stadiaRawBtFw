// 600d3c7c  FUN_600d3c7c  size=64 bytes
// --- callers ---
// --- callees ---


undefined4 * FUN_600d3c7c(undefined4 *param_1,int param_2)

{
  undefined4 local_1c [2];
  char local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  (**(code **)(**(int **)(param_2 + 0x5c) + 0x1c))(local_1c);
  if (local_14 == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 9) = 0;
    *(undefined1 *)((int)param_1 + 10) = local_12;
  }
  else {
    *param_1 = local_1c[0];
    *(undefined1 *)((int)param_1 + 9) = local_13;
    *(undefined1 *)(param_1 + 1) = 1;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)((int)param_1 + 10) = 1;
  }
  return param_1;
}


