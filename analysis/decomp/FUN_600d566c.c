// 600d566c  FUN_600d566c  size=66 bytes
// --- callers ---
// --- callees ---


undefined4 *
FUN_600d566c(undefined4 *param_1,int param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5)

{
  undefined4 local_1c [2];
  char local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  (**(code **)(**(int **)(param_2 + 0x5c) + 0x1c))
            (local_1c,*(int **)(param_2 + 0x5c),param_3,param_4,param_5);
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


