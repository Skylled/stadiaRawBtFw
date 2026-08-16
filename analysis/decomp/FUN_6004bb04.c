// 6004bb04  FUN_6004bb04  size=22 bytes
// --- callers ---
//   600471bc queue__600471bc
// --- callees ---


void FUN_6004bb04(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 2;
  param_1[1] = puVar1;
  param_1[4] = puVar1;
  param_1[2] = 0xffffffff;
  param_1[3] = puVar1;
  *param_1 = 0;
  return;
}


