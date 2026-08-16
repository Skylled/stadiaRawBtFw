// 600454ec  FUN_600454ec  size=126 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600454ec(float param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = param_1 * fRam60045500 * fRam60045504;
  fVar4 = fRam600454a8;
  if (fVar2 < fRam600454a8) {
    fVar4 = 1.0;
  }
  if (fVar2 < fRam600454b4) {
    fVar2 = fRam600454b4;
  }
  fVar3 = (float)VectorSignedToFloat((int)fVar2,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  fVar4 = (fVar2 - fVar3) + fVar4;
  uVar1 = VectorFloatToUnsigned
                    ((fRam600454b0 / (fRam600454ac - fVar4) + fVar2 + fRam600454b8 +
                     -fVar4 * fRam600454bc) * fRam600454c0,3);
  return uVar1;
}


