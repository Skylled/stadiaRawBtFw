// 600dc8f6  FUN_600dc8f6  size=162 bytes
// --- callers ---
//   6007bb4c FUN_6007bb4c
// --- callees ---
//   6007c7ac FUN_6007c7ac
//   600de184 FUN_600de184
//   600dcc56 FUN_600dcc56
//   600dc998 FUN_600dc998
//   600dca7a FUN_600dca7a
//   600dcb2e FUN_600dcb2e
//   600de178 FUN_600de178
//   600dcc10 FUN_600dcc10
//   600de164 FUN_600de164
//   600de1aa FUN_600de1aa
//   600dcb4a FUN_600dcb4a


undefined4 * FUN_600dc8f6(undefined4 *param_1,int param_2)

{
  *param_1 = *(undefined4 *)(param_2 + 0x40);
  FUN_600de184(param_1 + 1,param_2 + 0x1c);
  FUN_600de164(param_1 + 10,param_2 + 0x34);
  FUN_600dcc56(param_1 + 0xf,param_2);
  FUN_600dc998(param_1 + 100,param_2 + 0x58);
  FUN_600dca7a(param_1 + 0x6d,param_2 + 0x70);
  FUN_600dcb2e(*(undefined4 *)(param_2 + 0x20),param_1 + 0x76,param_2 + 0x88);
  param_1[0x7d] = 16000;
  *(undefined1 *)(param_1 + 0x80) = 1;
  FUN_600de1aa(param_1 + 1,16000);
  FUN_600de178(param_1 + 10);
  FUN_600dcc10(param_1 + 0xf,16000);
  FUN_6007c7ac(param_1 + 0x6d);
  FUN_600dcb4a(param_1 + 0x76);
  param_1[0x7f] = 0x3f800000;
  param_1[0x7e] = 0;
  return param_1;
}


