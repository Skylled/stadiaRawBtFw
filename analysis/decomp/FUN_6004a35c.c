// 6004a35c  FUN_6004a35c  size=50 bytes
// --- callers ---
//   60044440 FUN_60044440
// --- callees ---
//   600454c4 FUN_600454c4


void FUN_6004a35c(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

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
    param_1 = (undefined4 *)FUN_600454c4(*puVar2,param_1,param_3,puVar1,puVar2 + 1,puVar3,param_4);
    *extraout_r1 = extraout_s0;
    param_3 = extraout_r1 + 1;
    puVar1 = extraout_r2;
    puVar2 = extraout_r3;
  }
  return;
}


