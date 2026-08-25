// 600fd276  FUN_600fd276  size=62 bytes
// --- callers ---
// --- callees ---
//   600f068e FUN_600f068e


void FUN_600fd276(int param_1)

{
  if (*(char *)(param_1 + 0xe) == '\0') {
    FUN_600f068e(param_1 + 8,0xb,*(undefined4 *)(param_1 + 0x10));
  }
  else {
    FUN_600f068e(param_1 + 8,0,*(undefined4 *)(param_1 + 0x10));
  }
  return;
}


