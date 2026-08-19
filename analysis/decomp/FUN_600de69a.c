// 600de69a  FUN_600de69a  size=16 bytes
// --- callers ---
//   600de46e FUN_600de46e
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600de69a(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


