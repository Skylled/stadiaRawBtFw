// 600c7fc8  FUN_600c7fc8  size=304 bytes
// --- callers ---
//   600ffd7a FUN_600ffd7a
// --- callees ---


void FUN_600c7fc8(byte *param_1)

{
  byte bVar1;
  
  *param_1 = *(byte *)(DAT_600c80f8 + (uint)*param_1);
  param_1[4] = *(byte *)(DAT_600c80f8 + (uint)param_1[4]);
  param_1[8] = *(byte *)(DAT_600c80f8 + (uint)param_1[8]);
  param_1[0xc] = *(byte *)(DAT_600c80f8 + (uint)param_1[0xc]);
  bVar1 = param_1[1];
  param_1[1] = *(byte *)(DAT_600c80f8 + (uint)param_1[5]);
  param_1[5] = *(byte *)(DAT_600c80f8 + (uint)param_1[9]);
  param_1[9] = *(byte *)(DAT_600c80f8 + (uint)param_1[0xd]);
  param_1[0xd] = *(byte *)(DAT_600c80f8 + (uint)bVar1);
  bVar1 = param_1[2];
  param_1[2] = *(byte *)(DAT_600c80f8 + (uint)param_1[10]);
  param_1[10] = *(byte *)(DAT_600c80f8 + (uint)bVar1);
  bVar1 = param_1[6];
  param_1[6] = *(byte *)(DAT_600c80f8 + (uint)param_1[0xe]);
  param_1[0xe] = *(byte *)(DAT_600c80f8 + (uint)bVar1);
  bVar1 = param_1[0xf];
  param_1[0xf] = *(byte *)(DAT_600c80f8 + (uint)param_1[0xb]);
  param_1[0xb] = *(byte *)(DAT_600c80f8 + (uint)param_1[7]);
  param_1[7] = *(byte *)(DAT_600c80f8 + (uint)param_1[3]);
  param_1[3] = *(byte *)(DAT_600c80f8 + (uint)bVar1);
  return;
}


