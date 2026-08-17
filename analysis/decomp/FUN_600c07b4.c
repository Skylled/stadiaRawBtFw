// 600c07b4  FUN_600c07b4  size=40 bytes
// --- callers ---
//   600c09f0 FUN_600c09f0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8


void FUN_600c07b4(void)

{
  if (*DAT_600c07dc != 0) {
    FUN_6006ddd8(*DAT_600c07dc,DAT_600c07e0,0x6d);
  }
  thunk_EXT_FUN_0000b5ba(DAT_600c07dc,0,8);
  return;
}


