// 600e219a  FUN_600e219a  size=16 bytes
// --- callers ---
//   600e6f7a FUN_600e6f7a
//   600e21aa FUN_600e21aa
// --- callees ---


uint FUN_600e219a(uint param_1)

{
  return (param_1 & 0xf0f0f0f) << 4 | param_1 >> 4 & 0xf0f0f0f;
}


