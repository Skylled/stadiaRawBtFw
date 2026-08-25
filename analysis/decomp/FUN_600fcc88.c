// 600fcc88  FUN_600fcc88  size=72 bytes
// --- callers ---
//   600c1158 FUN_600c1158
//   600c10a4 FUN_600c10a4
// --- callees ---


byte FUN_600fcc88(int param_1,byte param_2)

{
  return (byte)((int)(uint)*(byte *)((uint)(param_2 >> 3) + param_1) >> (param_2 & 7)) & 1 | 0x80;
}


