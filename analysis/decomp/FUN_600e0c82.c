// 600e0c82  FUN_600e0c82  size=14 bytes
// --- callers ---
//   60091c10 obj__60091c10
//   60091b94 FUN_60091b94
//   60091d30 FUN_60091d30
//   6008d7ac bcm__6008d7ac
//   600919d4 ex_data__600919d4
//   600e0c90 thunk_FUN_600e0c82
// --- callees ---
//   6013d1d8 thunk_EXT_FUN_0000b28c
//   6010209a FUN_6010209a


void FUN_600e0c82(void)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b28c();
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


