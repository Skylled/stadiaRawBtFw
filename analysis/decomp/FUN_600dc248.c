// 600dc248  FUN_600dc248  size=22 bytes
// --- callers ---
//   6007bb4c FUN_6007bb4c
//   600dc292 FUN_600dc292
//   600dc25e FUN_600dc25e
// --- callees ---
//   600dbfec FUN_600dbfec


void FUN_600dc248(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    FUN_600dbfec(*param_1);
  }
  return;
}


