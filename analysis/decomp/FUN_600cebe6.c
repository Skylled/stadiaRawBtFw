// 600cebe6  FUN_600cebe6  size=40 bytes
// --- callers ---
//   60052fd0 FUN_60052fd0
//   60053078 FUN_60053078
//   60053120 FUN_60053120
//   600530b0 FUN_600530b0
//   60052eb8 FUN_60052eb8
//   60052f98 FUN_60052f98
//   60052e10 FUN_60052e10
//   600530e8 FUN_600530e8
//   60052f60 FUN_60052f60
//   60053040 FUN_60053040
//   60052e48 FUN_60052e48
//   60052e80 FUN_60052e80
//   60052dd8 FUN_60052dd8
//   60053008 FUN_60053008
//   60052ef0 FUN_60052ef0
//   60052f28 FUN_60052f28
// --- callees ---


uint FUN_600cebe6(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x24) >> (param_2 & 0xff) & 1) << 2 |
         (*(uint *)(param_1 + 0x2c) >> (param_2 & 0xff) & 1) << 1 |
         (*(ushort *)(param_1 + param_2 * 0x20 + 0x101c) & 0xff) >> 7;
}


