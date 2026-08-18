// 600cc8a8  FUN_600cc8a8  size=38 bytes
// --- callers ---
//   600cc8f8 FUN_600cc8f8
//   600cc984 FUN_600cc984
// --- callees ---
//   6013d330 thunk_EXT_FUN_0000b18c
//   6013d1d8 thunk_EXT_FUN_0000b28c
//   6010209a FUN_6010209a


undefined1 * FUN_600cc8a8(undefined1 *param_1)

{
  int iVar1;
  
  *param_1 = 1;
  if (DAT_600cc8d0 != 0) {
    thunk_EXT_FUN_0000b18c(DAT_600cc8d8,DAT_600cc8d4);
    iVar1 = thunk_EXT_FUN_0000b28c(*DAT_600cc8dc);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_6010209a();
    }
  }
  return param_1;
}


