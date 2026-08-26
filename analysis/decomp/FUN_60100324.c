// 60100324  FUN_60100324  size=62 bytes
// --- callers ---
//   600fffbc FUN_600fffbc
//   600ffe42 FUN_600ffe42
//   600c9aac FUN_600c9aac
// --- callees ---


undefined4 FUN_60100324(int param_1,uint param_2)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (param_2 <= local_c) {
      return 1;
    }
    if (*(int *)(local_c * 4 + param_1) != 0) break;
    local_c = local_c + 1;
  }
  return 0;
}


