// 600e0c5a  FUN_600e0c5a  size=14 bytes
// --- callers ---
//   600e0c68 thunk_FUN_600e0c5a
// --- callees ---
//   6013d1d8 thunk_EXT_FUN_0000b28c
//   6010209a FUN_6010209a


void FUN_600e0c5a(void)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b28c();
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


