// 60097600  FUN_60097600  size=90 bytes
// --- callers ---
//   600976f8 FUN_600976f8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554


undefined1 * FUN_60097600(undefined4 param_1)

{
  int iVar1;
  undefined1 *local_10;
  byte local_9;
  
  local_10 = DAT_6009765c;
  local_9 = 1;
  while( true ) {
    if (8 < local_9) {
      return (undefined1 *)0x0;
    }
    iVar1 = thunk_EXT_FUN_0000b554(DAT_60097660,local_10 + 1,6);
    if (iVar1 == 0) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x14;
  }
  thunk_EXT_FUN_0000b572(local_10 + 1,param_1,6);
  *local_10 = 1;
  return local_10;
}


