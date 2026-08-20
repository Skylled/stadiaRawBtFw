// 600e218a  FUN_600e218a  size=16 bytes
// --- callers ---
//   6008af3c FUN_6008af3c
//   600e21aa FUN_600e21aa
// --- callees ---


uint FUN_600e218a(uint param_1)

{
  return (param_1 & 0x3030303) << 6 | param_1 >> 2 & 0x3f3f3f3f;
}


