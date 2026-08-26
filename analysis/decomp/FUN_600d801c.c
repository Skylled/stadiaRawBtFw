// 600d801c  FUN_600d801c  size=34 bytes
// --- callers ---
//   60067e8c flash_memory__60067e8c
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


int * FUN_600d801c(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


