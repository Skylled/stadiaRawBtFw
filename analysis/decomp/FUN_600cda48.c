// 600cda48  FUN_600cda48  size=186 bytes
// --- callers ---
//   600ccfb4 FUN_600ccfb4
// --- callees ---
//   600cdb18 FUN_600cdb18


float FUN_600cda48(float param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = DAT_600cdb10;
  fVar5 = DAT_600cdb0c;
  fVar1 = ABS(param_1);
  if (fVar1 == 0.0) {
    return param_1;
  }
  if (0x7f7fffff < (uint)fVar1) {
    return param_1 + param_1;
  }
  if ((uint)fVar1 < 0x800000) {
    param_1 = param_1 * DAT_600cdb08;
    if (param_2 < DAT_600cdb04) {
      return param_1 * DAT_600cdb10;
    }
    uVar2 = ((uint)ABS(param_1) >> 0x17) - 0x19;
  }
  else {
    uVar2 = (uint)fVar1 >> 0x17;
  }
  iVar3 = uVar2 + param_2;
  if (iVar3 < 0xff) {
    if (0 < iVar3) {
      return (float)((uint)param_1 & 0x807fffff | iVar3 * 0x800000);
    }
    if (-0x17 < iVar3) {
      return (float)((uint)param_1 & 0x807fffff | (iVar3 + 0x19) * 0x800000) * DAT_600cdb14;
    }
    if (param_2 < 0xc351) {
      fVar5 = (float)FUN_600cdb18(DAT_600cdb10,param_1);
      return fVar5 * fVar4;
    }
  }
  fVar4 = (float)FUN_600cdb18(DAT_600cdb0c,param_1);
  return fVar4 * fVar5;
}


