// 600e0c6c  FUN_600e0c6c  size=14 bytes
// --- callers ---
//   600e0c7a thunk_FUN_600e0c6c
// --- callees ---
//   6013d100 thunk_EXT_FUN_0000b294
//   6010209a FUN_6010209a


void FUN_600e0c6c(void)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b294();
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


