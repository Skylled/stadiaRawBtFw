// 60101a12  FUN_60101a12  size=66 bytes
// --- callers ---
//   60101aa4 FUN_60101aa4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60101a12(int *param_1,int *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_1 == param_2) {
    uVar1 = 3;
  }
  else {
    if (param_2[2] + 1U <= (uint)(param_1[1] - param_1[2])) {
      thunk_EXT_FUN_0000b572(param_1[2] + *param_1,*param_2,param_2[2]);
      param_1[2] = param_1[2] + param_2[2];
      *(undefined1 *)((int)param_1 + 0xd) = 0;
      return;
    }
    uVar1 = 8;
  }
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  *(undefined1 *)(param_1 + 3) = uVar1;
  param_1[2] = param_3 + -1;
  return;
}


