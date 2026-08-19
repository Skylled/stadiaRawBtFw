// 600db9fa  FUN_600db9fa  size=42 bytes
// --- callers ---
//   600dba24 FUN_600dba24
//   6007a2c0 frames__6007a2c0
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


uint FUN_600db9fa(int *param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  if (param_3 <= (uint)param_1[1]) {
    uVar1 = param_3;
  }
  if ((*param_1 != 0) && (param_2 != 0)) {
    if (uVar1 != 0) {
      thunk_EXT_FUN_0000b588(*param_1,param_2,uVar1,param_4,param_4);
    }
    *param_1 = *param_1 + uVar1;
  }
  param_1[1] = param_1[1] - uVar1;
  return uVar1;
}


