// 600dc6e2  FUN_600dc6e2  size=48 bytes
// --- callers ---
//   6007c1a8 FUN_6007c1a8
//   6007c1d4 FUN_6007c1d4
// --- callees ---
//   600dc65c FUN_600dc65c


undefined4 * FUN_600dc6e2(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  FUN_600dc65c();
  puVar2 = (undefined4 *)*param_1;
  uVar1 = *param_3;
  puVar3 = puVar2;
  for (iVar4 = param_2; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  }
  param_1[1] = puVar2 + param_2;
  return param_1;
}


