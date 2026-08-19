// 600dde3e  FUN_600dde3e  size=22 bytes
// --- callers ---
//   600dd8f2 FUN_600dd8f2
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dd65e FUN_600dd65e


int FUN_600dde3e(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_600dd65e(param_1 + 4);
  return param_1;
}


