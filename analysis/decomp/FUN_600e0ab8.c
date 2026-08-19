// 600e0ab8  FUN_600e0ab8  size=20 bytes
// --- callers ---
//   600edafe FUN_600edafe
//   600eca08 FUN_600eca08
//   60090568 FUN_60090568
//   600e0ce4 FUN_600e0ce4
//   600e0cac FUN_600e0cac
//   600919d4 ex_data__600919d4
//   60086b98 FUN_60086b98
//   6008b570 bcm__6008b570
// --- callees ---


undefined4 FUN_600e0ab8(uint *param_1,uint param_2)

{
  if ((param_1 != (uint *)0x0) && (param_2 < *param_1)) {
    return *(undefined4 *)(param_1[1] + param_2 * 4);
  }
  return 0;
}


