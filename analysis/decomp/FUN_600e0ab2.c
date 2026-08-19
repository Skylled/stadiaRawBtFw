// 600e0ab2  FUN_600e0ab2  size=6 bytes
// --- callers ---
//   600edafe FUN_600edafe
//   600eca08 FUN_600eca08
//   60090568 FUN_60090568
//   600e0ce4 FUN_600e0ce4
//   6008ffc0 tasn_dec__6008ffc0
//   600e0cac FUN_600e0cac
//   600919d4 ex_data__600919d4
//   60086b98 FUN_60086b98
//   6008b570 bcm__6008b570
// --- callees ---


undefined4 FUN_600e0ab2(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = *param_1;
  }
  return uVar1;
}


