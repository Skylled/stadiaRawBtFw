// 600b72cc  FUN_600b72cc  size=36 bytes
// --- callers ---
//   600f8264 FUN_600f8264
//   600f8290 FUN_600f8290
// --- callees ---


uint FUN_600b72cc(ushort param_1,byte *param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) break;
    param_1 = *(ushort *)(DAT_600b7318 + ((uint)*param_2 ^ param_1 & 0xff) * 2) ^ param_1 >> 8;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  }
  return (uint)param_1;
}


