// 600e0a14  FUN_600e0a14  size=46 bytes
// --- callers ---
//   60085f2c pem_lib__60085f2c
// --- callees ---
//   6004cb28 FUN_6004cb28
//   600e09e0 FUN_600e09e0


uint FUN_600e0a14(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  if ((((param_1 == 0) || (param_4 == 0)) || ((int)param_2 < 0)) ||
     (uVar1 = FUN_6004cb28(param_4), param_2 <= uVar1)) {
    uVar1 = 0;
  }
  else {
    FUN_600e09e0(param_1,param_4,param_2);
  }
  return uVar1;
}


