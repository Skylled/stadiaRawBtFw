// 600de1aa  FUN_600de1aa  size=20 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
// --- callees ---


void FUN_600de1aa(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x18) = 0x3f800000;
  *(int *)(param_1 + 0x1c) = param_2 / 100;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


