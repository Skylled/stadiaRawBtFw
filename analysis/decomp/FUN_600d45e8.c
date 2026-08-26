// 600d45e8  FUN_600d45e8  size=36 bytes
// --- callers ---
//   6005e810 FUN_6005e810
//   6005eaf8 FUN_6005eaf8
//   6005edb8 FUN_6005edb8
//   6005ea2c FUN_6005ea2c
// --- callees ---
//   6005e39c FUN_6005e39c
//   601017e8 FUN_601017e8


int FUN_600d45e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_601017e8();
  *(undefined4 *)(param_1 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 0x58) = param_3;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  FUN_6005e39c(param_1 + 100);
  return param_1;
}


