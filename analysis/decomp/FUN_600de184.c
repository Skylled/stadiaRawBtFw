// 600de184  FUN_600de184  size=38 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
// --- callees ---


undefined4 * FUN_600de184(undefined4 *param_1,undefined4 *param_2)

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
  param_1[6] = 0x3f800000;
  param_1[7] = 0xa0;
  param_1[8] = 0;
  return param_1;
}


