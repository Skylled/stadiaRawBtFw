// 600e0acc  FUN_600e0acc  size=22 bytes
// --- callers ---
//   60090568 FUN_60090568
// --- callees ---


undefined4 FUN_600e0acc(uint *param_1,uint param_2,undefined4 param_3)

{
  if ((param_1 == (uint *)0x0) || (*param_1 <= param_2)) {
    param_3 = 0;
  }
  else {
    *(undefined4 *)(param_1[1] + param_2 * 4) = param_3;
  }
  return param_3;
}


