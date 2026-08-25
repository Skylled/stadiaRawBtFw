// 600fdf94  FUN_600fdf94  size=58 bytes
// --- callers ---
// --- callees ---
//   600c6318 FUN_600c6318
//   60094d24 FUN_60094d24


void FUN_600fdf94(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x1a) == '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 2;
  }
  else {
    FUN_600c6318(*(undefined4 *)(param_1 + 0x10),0x85);
  }
  FUN_60094d24(param_1,0x1d08,param_2);
  return;
}


