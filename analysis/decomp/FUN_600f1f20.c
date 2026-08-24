// 600f1f20  FUN_600f1f20  size=60 bytes
// --- callers ---
//   600a7b44 FUN_600a7b44
// --- callees ---


undefined4 FUN_600f1f20(int param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (1 < local_c) {
      return 1;
    }
    if (*(int *)(local_c * 4 + param_1) != -1) break;
    local_c = local_c + 1;
  }
  return 0;
}


