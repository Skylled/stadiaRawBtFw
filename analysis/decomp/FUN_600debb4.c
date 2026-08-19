// 600debb4  FUN_600debb4  size=20 bytes
// --- callers ---
//   600ded7e FUN_600ded7e
//   6007ec48 receiver__6007ec48
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74


undefined4 FUN_600debb4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_EXT_FUN_00006a74(*(undefined4 *)(param_1 + 0xb0),param_2,0xffffffff,0,param_4);
  return 1;
}


