// 600af75c  FUN_600af75c  size=102 bytes
// --- callers ---
//   600af8ac FUN_600af8ac
//   600af814 FUN_600af814
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


byte FUN_600af75c(undefined4 param_1,char param_2)

{
  int iVar1;
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0xff;
    }
    iVar1 = thunk_EXT_FUN_0000b554((uint)local_9 * 0x10c + DAT_600af7c4 + 0xd,param_1,6);
    if ((iVar1 == 0) && (param_2 == *(char *)((uint)local_9 * 0x10c + DAT_600af7c4 + 0x13))) break;
    local_9 = local_9 + 1;
  }
  return local_9;
}


