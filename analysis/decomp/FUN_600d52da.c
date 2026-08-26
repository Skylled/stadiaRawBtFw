// 600d52da  FUN_600d52da  size=22 bytes
// --- callers ---
//   6005c8a0 FUN_6005c8a0
// --- callees ---
//   600d51f6 FUN_600d51f6


void FUN_600d52da(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0xa4) = *param_2;
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  FUN_600d51f6((undefined4 *)(param_1 + 0xa4),*(undefined1 *)(param_1 + 0xad));
  return;
}


