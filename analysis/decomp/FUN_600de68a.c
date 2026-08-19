// 600de68a  FUN_600de68a  size=16 bytes
// --- callers ---
//   600dd98e FUN_600dd98e
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600de68a(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


