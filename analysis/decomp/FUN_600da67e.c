// 600da67e  FUN_600da67e  size=30 bytes
// --- callers ---
//   60075c50 headphone_state_machine__60075c50
// --- callees ---
//   60101ba2 FUN_60101ba2
//   600cc4a8 FUN_600cc4a8


int * FUN_600da67e(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_600cc4a8(*param_1 + param_1[2],param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


