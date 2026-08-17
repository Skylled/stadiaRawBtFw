// 6009625c  FUN_6009625c  size=46 bytes
// --- callers ---
//   6009451c FUN_6009451c
//   600955dc FUN_600955dc
//   60092de8 FUN_60092de8
// --- callees ---


void FUN_6009625c(byte param_1,undefined4 param_2)

{
  *(undefined4 *)(DAT_6009628c + (uint)param_1 * 4) = param_2;
  *(undefined1 *)((uint)param_1 + DAT_6009628c + 200) = 1;
  return;
}


