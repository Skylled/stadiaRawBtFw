// 600f6d9c  FUN_600f6d9c  size=42 bytes
// --- callers ---
//   600b02e0 FUN_600b02e0
//   600b00b4 FUN_600b00b4
//   600ab620 FUN_600ab620
//   600ab9b8 FUN_600ab9b8
//   600ab778 FUN_600ab778
//   600f39fc FUN_600f39fc
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f6d9c(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x5c) != '\0')) {
    thunk_EXT_FUN_0000b5ba(param_1,0,0x60);
  }
  return;
}


