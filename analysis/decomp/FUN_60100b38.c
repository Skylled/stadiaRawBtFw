// 60100b38  FUN_60100b38  size=16 bytes
// --- callers ---
//   60100e08 FUN_60100e08
//   60100f90 FUN_60100f90
//   60101294 FUN_60101294
//   600cb39c key_value_store__600cb39c
//   600cb6fc key_value_store__600cb6fc
//   60100bb0 FUN_60100bb0
//   60101198 FUN_60101198
// --- callees ---


uint FUN_60100b38(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x14))();
  if (0x13 < uVar1) {
    uVar1 = 0x14;
  }
  return uVar1;
}


