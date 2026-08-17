// 600a4010  FUN_600a4010  size=76 bytes
// --- callers ---
//   600c4320 FUN_600c4320
//   600c3558 FUN_600c3558
// --- callees ---


undefined4 FUN_600a4010(int param_1)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (1 < local_c) {
      return 0;
    }
    if (param_1 == *(int *)(DAT_600a405c + (local_c + 0x450) * 4)) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(DAT_600a405c + (local_c + 0x450) * 4) = 0;
  return 1;
}


