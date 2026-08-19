// 600dcb2e  FUN_600dcb2e  size=26 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
// --- callees ---


undefined4 * FUN_600dcb2e(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *param_2 = *param_3;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[4] = param_1;
  param_2[5] = param_1;
  param_2[6] = 0;
  return param_2;
}


