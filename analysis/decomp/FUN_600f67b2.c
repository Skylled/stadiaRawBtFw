// 600f67b2  FUN_600f67b2  size=184 bytes
// --- callers ---
//   600ab110 FUN_600ab110
//   600ab088 FUN_600ab088
// --- callees ---


undefined4 FUN_600f67b2(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*param_1 == 0) {
      param_1[1] = (int)param_2;
      *param_1 = param_1[1];
      param_2[1] = 0;
      *param_2 = param_2[1];
    }
    else {
      for (local_c = (undefined4 *)*param_1; local_c != (undefined4 *)0x0;
          local_c = (undefined4 *)*local_c) {
        if (*(ushort *)((int)local_c + 0x32) < *(ushort *)((int)param_2 + 0x32)) {
          if (local_c == (undefined4 *)*param_1) {
            *param_1 = (int)param_2;
          }
          param_2[1] = local_c[1];
          *param_2 = local_c;
          local_c[1] = param_2;
          goto LAB_600f6850;
        }
      }
      *(undefined4 **)param_1[1] = param_2;
      param_2[1] = param_1[1];
      *param_2 = 0;
      param_1[1] = (int)param_2;
    }
LAB_600f6850:
    *(short *)(param_1 + 2) = (short)param_1[2] + 1;
    uVar1 = 1;
  }
  return uVar1;
}


