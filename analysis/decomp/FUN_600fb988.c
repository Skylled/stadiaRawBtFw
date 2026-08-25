// 600fb988  FUN_600fb988  size=44 bytes
// --- callers ---
// --- callees ---
//   600fcab6 FUN_600fcab6


void FUN_600fb988(int param_1)

{
  if ((*(ushort *)(param_1 + 0x28) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x25) = 0x18;
    FUN_600fcab6(param_1);
  }
  return;
}


