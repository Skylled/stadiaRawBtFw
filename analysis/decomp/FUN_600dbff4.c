// 600dbff4  FUN_600dbff4  size=28 bytes
// --- callers ---
//   600dc292 FUN_600dc292
//   6007bb4c FUN_6007bb4c
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   6013d068 thunk_EXT_FUN_0000b52e


void FUN_600dbff4(int param_1)

{
  if (*(int *)(param_1 + 0x484) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  thunk_EXT_FUN_0000b52e(param_1,0x5a1c);
  return;
}


