// 600d3ac4  FUN_600d3ac4  size=34 bytes
// --- callers ---
//   6005a0ac device_info__6005a0ac
// --- callees ---
//   60101b0c FUN_60101b0c
//   60101ba2 FUN_60101ba2


int * FUN_600d3ac4(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60101b0c(param_2,param_2 >> 0x1f,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


