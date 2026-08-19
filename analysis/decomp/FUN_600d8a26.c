// 600d8a26  FUN_600d8a26  size=14 bytes
// --- callers ---
//   6006a21c adapter__6006a21c
//   6006a390 FUN_6006a390
//   60069c10 adapter__60069c10
// --- callees ---
//   6010209a FUN_6010209a


void FUN_600d8a26(int param_1)

{
  if (*(char *)(param_1 + 0xc) != '\x01') {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


