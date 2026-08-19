// 600dcbb6  FUN_600dcbb6  size=66 bytes
// --- callers ---
//   600dcc10 FUN_600dcc10
// --- callees ---
//   60101fcc FUN_60101fcc
//   6013d378 thunk_EXT_FUN_0000b532


undefined4 * FUN_600dcbb6(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = param_3 - param_2;
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (uVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    if (0x3fffffff < uVar2) {
      FUN_60101fcc();
    }
    puVar1 = (undefined4 *)thunk_EXT_FUN_0000b532(uVar2 * 4);
  }
  puVar3 = puVar1 + uVar2;
  *param_1 = puVar1;
  param_1[1] = puVar1;
  param_1[2] = puVar3;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  param_1[1] = puVar3;
  return param_1;
}


