// 600a36e4  FUN_600a36e4  size=58 bytes
// --- callers ---
//   60098f88 FUN_60098f88
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600a36e4(byte param_1)

{
  int iVar1;
  
  iVar1 = (uint)param_1 * 0x24 + DAT_600a3720;
  thunk_EXT_FUN_0000b5ba(iVar1 + 0x64c,0,0x24);
  *(undefined1 *)(iVar1 + 0x66c) = 0;
  return;
}


