// 600b0548  FUN_600b0548  size=78 bytes
// --- callers ---
//   600f717c FUN_600f717c
//   600f7300 FUN_600f7300
//   600ad8fc FUN_600ad8fc
//   600f735a FUN_600f735a
//   600f72b6 FUN_600f72b6
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600b0548(undefined4 param_1)

{
  int iVar1;
  byte local_d;
  int local_c;
  
  local_c = DAT_600b0598;
  local_d = 0;
  while( true ) {
    if (2 < local_d) {
      return 0;
    }
    if ((*(char *)(local_c + 0x1a) != '\0') &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_c + 0x14,param_1,6), iVar1 == 0)) break;
    local_d = local_d + 1;
    local_c = local_c + 0x1b;
  }
  return local_c;
}


