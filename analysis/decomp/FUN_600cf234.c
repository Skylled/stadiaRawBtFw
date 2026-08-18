// 600cf234  FUN_600cf234  size=18 bytes
// --- callers ---
//   6006e854 FUN_6006e854
// --- callees ---
//   60053864 FUN_60053864


void FUN_600cf234(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_2 + 0x18) = param_3;
  *(undefined4 *)(param_2 + 0x1c) = param_4;
  *(undefined2 *)(param_2 + 0x20) = 0;
  *(undefined2 *)(param_2 + 0x22) = 0;
  FUN_60053864(param_1,0x8200000);
  return;
}


