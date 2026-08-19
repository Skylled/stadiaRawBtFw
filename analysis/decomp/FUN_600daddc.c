// 600daddc  FUN_600daddc  size=34 bytes
// --- callers ---
//   60076ba0 FUN_60076ba0
// --- callees ---
//   60101b0c FUN_60101b0c
//   60101ba2 FUN_60101ba2


int * FUN_600daddc(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60101b0c(param_2,param_2 >> 0x1f,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


