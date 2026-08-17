// 600986e0  FUN_600986e0  size=48 bytes
// --- callers ---
//   60098c3c FUN_60098c3c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6009746c FUN_6009746c
//   600effba FUN_600effba
//   6009f3c0 FUN_6009f3c0


void FUN_600986e0(void)

{
  thunk_EXT_FUN_0000b5ba(DAT_60098710,0,0xd0);
  if ((*(byte *)(DAT_60098714 + 0x81b) & 2) != 0) {
    FUN_600effba(0xff);
    FUN_6009746c();
    FUN_6009f3c0();
  }
  return;
}


