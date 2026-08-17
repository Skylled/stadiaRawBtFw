// 60092514  FUN_60092514  size=14 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_60092514(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_60092524[1];
  uVar2 = DAT_60092524[2];
  *param_1 = *DAT_60092524;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return 0;
}


