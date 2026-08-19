// 600dca7a  FUN_600dca7a  size=30 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
// --- callees ---
//   6007c7ac FUN_6007c7ac


undefined4 * FUN_600dca7a(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  uVar1 = param_2[5];
  param_1[4] = param_2[4];
  param_1[5] = uVar1;
  FUN_6007c7ac(param_1);
  return param_1;
}


