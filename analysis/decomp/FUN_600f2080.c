// 600f2080  FUN_600f2080  size=44 bytes
// --- callers ---
//   600faec4 FUN_600faec4
//   600fab28 FUN_600fab28
//   600f172a FUN_600f172a
// --- callees ---
//   6009f8c8 FUN_6009f8c8
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f2080(int param_1)

{
  *(undefined1 *)(param_1 + 0x7b) = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x7c,0,0x68);
  FUN_6009f8c8(param_1);
  return;
}


