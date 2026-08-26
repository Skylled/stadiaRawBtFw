// 60100362  FUN_60100362  size=56 bytes
// --- callers ---
//   601003da FUN_601003da
// --- callees ---


int FUN_60100362(uint param_1)

{
  uint local_14;
  int local_c;
  
  local_c = 0;
  for (local_14 = param_1; (local_c < 0x20 && (local_14 != 0)); local_14 = local_14 >> 1) {
    local_c = local_c + 1;
  }
  return local_c;
}


