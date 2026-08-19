// 600dcc56  FUN_600dcc56  size=68 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
// --- callees ---
//   600de0c4 FUN_600de0c4
//   600de288 FUN_600de288
//   600dcc10 FUN_600dcc10
//   600dd65c FUN_600dd65c


undefined4 * FUN_600dcc56(undefined4 *param_1,undefined4 *param_2)

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
  uVar2 = param_2[6];
  param_1[4] = param_2[4];
  param_1[5] = uVar1;
  param_1[6] = uVar2;
  FUN_600de0c4(param_1 + 7);
  param_1[0x12] = 0;
  FUN_600de288(param_1 + 0x13,param_2 + 0x11);
  FUN_600dd65c(param_1 + 0x54);
  FUN_600dcc10(param_1,48000);
  return param_1;
}


