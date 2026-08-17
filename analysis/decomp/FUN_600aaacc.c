// 600aaacc  FUN_600aaacc  size=70 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600aaacc(undefined4 param_1,short *param_2)

{
  byte local_d;
  short *local_c;
  
  local_c = DAT_600aab14;
  local_d = 0;
  while( true ) {
    if (3 < local_d) {
      return 10;
    }
    if (*param_2 == *local_c) break;
    local_d = local_d + 1;
    local_c = local_c + 6;
  }
  return 3;
}


