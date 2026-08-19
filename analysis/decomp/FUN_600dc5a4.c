// 600dc5a4  FUN_600dc5a4  size=22 bytes
// --- callers ---
//   600dc5ee FUN_600dc5ee
// --- callees ---
//   600dd812 FUN_600dd812
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600dc5a4(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_600dd812(param_1);
  return param_1;
}


