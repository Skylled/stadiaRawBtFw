// 600df286  FUN_600df286  size=32 bytes
// --- callers ---
//   6008099c state_machine__6008099c
// --- callees ---
//   60079bb4 FUN_60079bb4
//   60101ba2 FUN_60101ba2


int * FUN_600df286(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60079bb4(param_2,*param_1 + param_1[2],param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


