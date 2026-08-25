// 600f686a  FUN_600f686a  size=134 bytes
// --- callers ---
//   600ab110 FUN_600ab110
//   600ab318 FUN_600ab318
// --- callees ---


undefined4 FUN_600f686a(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == (int *)0x0) || (*param_1 == 0)) {
    uVar1 = 0;
  }
  else {
    if (param_2[1] == 0) {
      *param_1 = *param_2;
      if (*param_2 != 0) {
        *(undefined4 *)(*param_2 + 4) = 0;
      }
    }
    else if (*param_2 == 0) {
      param_1[1] = param_2[1];
      *(undefined4 *)param_2[1] = 0;
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
      *(int *)param_2[1] = *param_2;
    }
    *(short *)(param_1 + 2) = (short)param_1[2] + -1;
    uVar1 = 1;
  }
  return uVar1;
}


