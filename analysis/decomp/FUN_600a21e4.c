// 600a21e4  FUN_600a21e4  size=82 bytes
// --- callers ---
//   600f1e24 FUN_600f1e24
//   6009a9c4 FUN_6009a9c4
//   6009fcf4 FUN_6009fcf4
//   600bc5c4 FUN_600bc5c4
//   600f0836 FUN_600f0836
//   600c3150 FUN_600c3150
//   600fd110 FUN_600fd110
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600a21e4(undefined4 param_1)

{
  int iVar1;
  int local_10;
  ushort local_a;
  
  local_10 = DAT_600a2238;
  local_a = 0;
  while( true ) {
    if (0x1d < local_a) {
      return 0;
    }
    if ((*(char *)(local_10 + 0x2e) != '\0') &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_10 + 10,param_1,6), iVar1 == 0)) break;
    local_a = local_a + 1;
    local_10 = local_10 + 0x30;
  }
  return local_10 + 8;
}


