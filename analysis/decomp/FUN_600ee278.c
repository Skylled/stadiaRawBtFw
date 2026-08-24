// 600ee278  FUN_600ee278  size=32 bytes
// --- callers ---
//   6006a21c adapter__6006a21c
//   600efd42 FUN_600efd42
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600d937c thunk_EXT_FUN_00007dac
//   600d9378 thunk_EXT_FUN_00007d64


undefined1 FUN_600ee278(void)

{
  undefined1 uVar1;
  
  thunk_EXT_FUN_00007d64();
  uVar1 = FUN_600a01a0();
  thunk_EXT_FUN_00007dac();
  return uVar1;
}


