// 600ea6e4  FUN_600ea6e4  size=20 bytes
// --- callers ---
//   600ea6f8 thunk_FUN_600ea6e4
// --- callees ---
//   6013d0d8 thunk_EXT_FUN_0000b068
//   600e092c FUN_600e092c


int FUN_600ea6e4(void)

{
  int iVar1;
  
  iVar1 = FUN_600e092c(0x10);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b068();
  }
  return iVar1;
}


