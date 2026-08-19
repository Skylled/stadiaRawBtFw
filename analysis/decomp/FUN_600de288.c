// 600de288  FUN_600de288  size=26 bytes
// --- callers ---
//   600dcc56 FUN_600dcc56
// --- callees ---
//   600de276 FUN_600de276


undefined4 * FUN_600de288(undefined4 *param_1,undefined4 *param_2)

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
  param_1[4] = param_2[4];
  FUN_600de276(param_1);
  return param_1;
}


