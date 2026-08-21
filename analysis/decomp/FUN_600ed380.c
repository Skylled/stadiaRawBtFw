// 600ed380  FUN_600ed380  size=24 bytes
// --- callers ---
//   600ed556 FUN_600ed556
//   600eda1c FUN_600eda1c
// --- callees ---


bool FUN_600ed380(int *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  if (param_2 <= uVar1) {
    param_1[1] = uVar1 - param_2;
    *param_1 = *param_1 + param_2;
  }
  return param_2 <= uVar1;
}


