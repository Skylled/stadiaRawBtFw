// 600a26ec  FUN_600a26ec  size=80 bytes
// --- callers ---
//   600f1800 FUN_600f1800
//   6009e4d0 FUN_6009e4d0
//   600a2ab0 FUN_600a2ab0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600a26ec(undefined4 param_1)

{
  int iVar1;
  int local_10;
  ushort local_a;
  
  local_10 = DAT_600a273c;
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
  return local_10;
}


