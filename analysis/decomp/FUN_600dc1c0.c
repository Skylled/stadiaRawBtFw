// 600dc1c0  FUN_600dc1c0  size=50 bytes
// --- callers ---
//   600dc38e FUN_600dc38e
//   600dc1f2 FUN_600dc1f2
//   6007bb4c FUN_6007bb4c
// --- callees ---
//   600dc19e FUN_600dc19e


undefined4 * FUN_600dc1c0(undefined4 *param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  FUN_600dc19e();
  puVar2 = (undefined2 *)*param_1;
  uVar1 = *param_3;
  puVar3 = puVar2;
  for (iVar4 = param_2; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  }
  param_1[1] = puVar2 + param_2;
  return param_1;
}


