// 600f672a  FUN_600f672a  size=136 bytes
// --- callers ---
//   600ab564 FUN_600ab564
// --- callees ---
//   600f662c FUN_600f662c


undefined4 FUN_600f672a(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == (int *)0x0) || (*(int *)(param_1 + 4) == 0)) {
    uVar1 = 0;
  }
  else {
    if (param_2[1] == 0) {
      *(int *)(param_1 + 4) = *param_2;
      if (*param_2 != 0) {
        *(undefined4 *)(*param_2 + 4) = 0;
      }
    }
    else if (*param_2 == 0) {
      *(int *)(param_1 + 8) = param_2[1];
      *(undefined4 *)param_2[1] = 0;
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
      *(int *)param_2[1] = *param_2;
    }
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -1;
    FUN_600f662c(param_1);
    uVar1 = 1;
  }
  return uVar1;
}


