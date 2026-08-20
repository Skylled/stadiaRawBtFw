// 600eca08  FUN_600eca08  size=78 bytes
// --- callers ---
//   60090940 FUN_60090940
//   6008fa18 tasn_dec__6008fa18
//   6008ffc0 tasn_dec__6008ffc0
//   600901c8 tasn_dec__600901c8
// --- callees ---
//   60090940 FUN_60090940
//   600e0ab2 FUN_600e0ab2
//   600e0ae2 FUN_600e0ae2
//   600e0ab8 FUN_600e0ab8


void FUN_600eca08(undefined4 *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *local_1c;
  undefined4 uStack_18;
  
  local_1c = param_2;
  uStack_18 = param_3;
  if ((*param_2 & 6) == 0) {
    FUN_60090940(param_1,param_2[4],*param_2 & 0x400,param_4,param_1);
  }
  else {
    uVar3 = *param_1;
    for (uVar2 = 0; uVar1 = FUN_600e0ab2(uVar3), uVar2 < uVar1; uVar2 = uVar2 + 1) {
      local_1c = (uint *)FUN_600e0ab8(uVar3,uVar2);
      FUN_60090940(&local_1c,param_2[4],0);
    }
    FUN_600e0ae2(uVar3);
    *param_1 = 0;
  }
  return;
}


