// 60100b0a  FUN_60100b0a  size=26 bytes
// --- callers ---
//   6005f728 FUN_6005f728
// --- callees ---


bool FUN_60100b0a(uint param_1,uint param_2)

{
  if (param_2 < param_1) {
    return false;
  }
  return param_2 < (param_1 + 0x1f & 0xffffffe0) + 0x20;
}


