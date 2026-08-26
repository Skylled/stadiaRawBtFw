// 600d6ba8  FUN_600d6ba8  size=64 bytes
// --- callers ---
// --- callees ---
//   600d6ac6 FUN_600d6ac6


undefined4 *
FUN_600d6ba8(undefined4 *param_1,int param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5)

{
  undefined4 local_14 [2];
  char local_c;
  undefined1 local_b;
  undefined1 local_a;
  
  FUN_600d6ac6(local_14,*(undefined4 *)(param_2 + 0x5c),param_3,param_4,param_5);
  if (local_c == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 9) = 0;
    *(undefined1 *)((int)param_1 + 10) = local_a;
  }
  else {
    *param_1 = local_14[0];
    *(undefined1 *)((int)param_1 + 9) = local_b;
    *(undefined1 *)(param_1 + 1) = 1;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)((int)param_1 + 10) = 1;
  }
  return param_1;
}


