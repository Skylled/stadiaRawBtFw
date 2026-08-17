// 600a3fc0  FUN_600a3fc0  size=74 bytes
// --- callers ---
//   600c33f0 FUN_600c33f0
// --- callees ---


undefined4 FUN_600a3fc0(undefined4 param_1)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (1 < local_c) {
      return 0;
    }
    if (*(int *)(DAT_600a400c + (local_c + 0x450) * 4) == 0) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(DAT_600a400c + (local_c + 0x450) * 4) = param_1;
  return 1;
}


