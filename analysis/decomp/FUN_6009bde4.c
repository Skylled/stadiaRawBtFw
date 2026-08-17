// 6009bde4  FUN_6009bde4  size=86 bytes
// --- callers ---
//   6009be40 FUN_6009be40
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_6009bde4(undefined4 param_1)

{
  int iVar1;
  int local_10;
  byte local_9;
  
  local_10 = DAT_6009be3c;
  local_9 = 0;
  while( true ) {
    if (7 < local_9) {
      return 0;
    }
    if (((*(ushort *)(local_10 + 0x2a) & 0x80) != 0) &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_10 + 0x6c,param_1,6), iVar1 == 0)) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0xfc;
  }
  return local_10;
}


