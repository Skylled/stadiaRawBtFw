// 600df2a6  FUN_600df2a6  size=32 bytes
// --- callers ---
//   6008099c state_machine__6008099c
// --- callees ---
//   6008067c FUN_6008067c
//   60101ba2 FUN_60101ba2


int * FUN_600df2a6(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_6008067c(param_2,*param_1 + param_1[2],param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


