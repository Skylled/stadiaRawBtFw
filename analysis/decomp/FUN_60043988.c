// 60043988  FUN_60043988  size=60 bytes
// --- callers ---
//   60043ecc FUN_60043ecc
// --- callees ---


void FUN_60043988(float *param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  
  pfVar1 = DAT_600439c4;
  pfVar2 = param_1;
  do {
    fVar3 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    *pfVar2 = fVar3 * *pfVar2;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != param_1 + 0x60);
  pfVar2 = param_1 + 0xa1;
  pfVar1 = DAT_600439c8;
  do {
    fVar3 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    *pfVar2 = fVar3 * *pfVar2;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != param_1 + 0x100);
  return;
}


