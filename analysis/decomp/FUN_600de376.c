// 600de376  FUN_600de376  size=30 bytes
// --- callers ---
//   600ddca0 FUN_600ddca0
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dd65e FUN_600dd65e


int FUN_600de376(int param_1)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_600dd65e(param_1);
  return param_1;
}


