// 600f83a0  FUN_600f83a0  size=82 bytes
// --- callers ---
//   600b6d30 FUN_600b6d30
// --- callees ---
//   600b7674 FUN_600b7674


void FUN_600f83a0(int param_1)

{
  if (((*(char *)(param_1 + 4) == '\x06') && (*(char *)(param_1 + 0xba) == '\0')) &&
     (*(char *)(param_1 + 0xb3) != *(char *)(param_1 + 0xb2))) {
    if (*(char *)(param_1 + 0xb7) == '\0') {
      FUN_600b7674(param_1,0,0);
    }
    else {
      FUN_600b7674(param_1,2,0);
    }
  }
  return;
}


