// 600454c4  FUN_600454c4  size=26 bytes
// --- callers ---
//   60043af0 FUN_60043af0
//   6004a35c FUN_6004a35c
// --- callees ---


float FUN_600454c4(undefined4 param_1)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorUnsignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  return (DAT_600454e4 + fVar1 * DAT_600454e0) * DAT_600454e8;
}


