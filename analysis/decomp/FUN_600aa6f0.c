// 600aa6f0  FUN_600aa6f0  size=80 bytes
// --- callers ---
//   600aaeec FUN_600aaeec
//   600aae30 FUN_600aae30
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600aa6f0(undefined4 param_1)

{
  int iVar1;
  int local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_600aa740;
  while( true ) {
    if (5 < local_9) {
      return 0;
    }
    if ((*(char *)(local_10 + 0x10) != '\0') &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_10,param_1,6), iVar1 == 0)) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x20;
  }
  return local_10;
}


