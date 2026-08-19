// 600de8b8  FUN_600de8b8  size=16 bytes
// --- callers ---
//   600ddee8 FUN_600ddee8
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600de8b8(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


