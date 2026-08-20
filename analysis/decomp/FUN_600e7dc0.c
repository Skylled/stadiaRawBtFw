// 600e7dc0  FUN_600e7dc0  size=42 bytes
// --- callers ---
//   6008b79c bcm__6008b79c
//   600e7dea FUN_600e7dea
//   600e97de FUN_600e97de
// --- callees ---
//   600e7c2c FUN_600e7c2c
//   600e7412 FUN_600e7412


int FUN_600e7dc0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_600e7c2c(param_4,param_1,param_3,param_5,param_1,param_2,param_3);
  FUN_600e7412(param_1,param_2 - iVar1,param_1,param_4,param_5);
  return param_2 - iVar1;
}


