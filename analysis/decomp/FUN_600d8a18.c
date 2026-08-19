// 600d8a18  FUN_600d8a18  size=14 bytes
// --- callers ---
//   6006a21c adapter__6006a21c
//   60069c10 adapter__60069c10
// --- callees ---
//   6010209a FUN_6010209a


void FUN_600d8a18(int param_1)

{
  if (*(char *)(param_1 + 0xc) != '\x02') {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


