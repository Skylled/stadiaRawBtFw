// 600cc6fc  FUN_600cc6fc  size=24 bytes
// --- callers ---
//   60078fec FUN_60078fec
// --- callees ---
//   6013d0e0 thunk_EXT_FUN_0000728c
//   6013d2d0 thunk_EXT_FUN_0000713c


undefined4 FUN_600cc6fc(void)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000713c();
  uVar1 = *DAT_600cc714;
  *DAT_600cc714 = *DAT_600cc718;
  thunk_EXT_FUN_0000728c();
  return uVar1;
}


