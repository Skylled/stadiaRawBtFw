// 600edafe  FUN_600edafe  size=38 bytes
// --- callers ---
//   600919d4 ex_data__600919d4
// --- callees ---
//   600e0ab2 FUN_600e0ab2
//   600e0ab8 FUN_600e0ab8


undefined4 FUN_600edafe(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  
  if (((*param_1 != 0) && (-1 < (int)param_2)) && (uVar1 = FUN_600e0ab2(), param_2 < uVar1)) {
    uVar2 = FUN_600e0ab8(*param_1,param_2,extraout_r2,param_4);
    return uVar2;
  }
  return 0;
}


