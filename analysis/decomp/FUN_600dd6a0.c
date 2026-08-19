// 600dd6a0  FUN_600dd6a0  size=50 bytes
// --- callers ---
// --- callees ---
//   6013d348 thunk_EXT_FUN_00004cd0


void FUN_600dd6a0(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *extraout_r1;
  undefined4 *puVar1;
  undefined4 *extraout_r2;
  undefined4 *puVar2;
  undefined4 *extraout_r3;
  undefined4 extraout_s0;
  undefined4 *puVar3;
  
  puVar1 = param_1 + param_2;
  puVar2 = param_1;
  puVar3 = param_3;
  while (puVar2 != puVar1) {
    param_1 = (undefined4 *)
              thunk_EXT_FUN_00004cd0(*puVar2,param_1,param_3,puVar1,puVar2 + 1,puVar3,param_4);
    *extraout_r1 = extraout_s0;
    param_3 = extraout_r1 + 1;
    puVar1 = extraout_r2;
    puVar2 = extraout_r3;
  }
  return;
}


