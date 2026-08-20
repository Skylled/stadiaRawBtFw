// 600e7d98  FUN_600e7d98  size=40 bytes
// --- callers ---
//   600ea820 FUN_600ea820
//   6008b6a8 bcm__6008b6a8
// --- callees ---
//   600e7c2c FUN_600e7c2c
//   600e7412 FUN_600e7412


int FUN_600e7d98(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_600e7c2c(param_1,param_2,param_4,param_5,param_1,param_2,param_3);
  FUN_600e7412(param_1,param_3 - iVar1,param_2,param_1,param_5);
  return param_3 - iVar1;
}


