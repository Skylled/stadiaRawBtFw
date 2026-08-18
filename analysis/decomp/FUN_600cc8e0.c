// 600cc8e0  FUN_600cc8e0  size=18 bytes
// --- callers ---
//   600cc984 FUN_600cc984
// --- callees ---
//   6013d2f8 thunk_EXT_FUN_0000b15c
//   6010209a FUN_6010209a


void FUN_600cc8e0(void)

{
  int iVar1;
  
  if ((DAT_600cc8f4 != 0) && (iVar1 = thunk_EXT_FUN_0000b15c(), iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


