// 600cc824  FUN_600cc824  size=22 bytes
// --- callers ---
//   600cc8f8 FUN_600cc8f8
//   600cc984 FUN_600cc984
// --- callees ---
//   6013d100 thunk_EXT_FUN_0000b294
//   6010209a FUN_6010209a


void FUN_600cc824(void)

{
  int iVar1;
  
  if ((DAT_600cc83c != 0) && (iVar1 = thunk_EXT_FUN_0000b294(*DAT_600cc840), iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


