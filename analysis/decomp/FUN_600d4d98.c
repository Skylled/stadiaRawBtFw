// 600d4d98  FUN_600d4d98  size=42 bytes
// --- callers ---
//   6006b5dc FUN_6006b5dc
// --- callees ---
//   600d4d56 FUN_600d4d56


void FUN_600d4d98(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_600d4d56();
  *(undefined4 *)(param_1 + 0xf0) = uVar1;
  *(undefined1 *)(param_1 + 0xf6) = 0;
  *(undefined1 *)(param_1 + 0xec) = 0;
  *(undefined1 *)(param_1 + 0xf7) = 0;
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  *(undefined4 *)(param_1 + 0xe8) = param_3;
  *(undefined2 *)(param_1 + 0xf4) = 0x10;
  return;
}


