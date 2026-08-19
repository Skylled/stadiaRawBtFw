// 600de98e  FUN_600de98e  size=62 bytes
// --- callers ---
//   600ddc48 FUN_600ddc48
// --- callees ---


undefined4 * FUN_600de98e(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  
  param_1[9] = param_3;
  fVar4 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  param_1[0xd] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  param_1[3] = uVar1;
  param_1[4] = uVar2;
  param_1[5] = uVar3;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[6] = uVar1;
  param_1[7] = uVar2;
  param_1[8] = uVar3;
  param_1[10] = 1.0 / fVar4;
  return param_1;
}


