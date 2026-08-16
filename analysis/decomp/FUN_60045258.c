// 60045258  FUN_60045258  size=146 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60045258(float *param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  pfVar1 = _DAT_600452ec;
  pfVar6 = _DAT_600452ec + -0x1f;
  param_1[1] = -param_1[1];
  pfVar2 = param_1;
  pfVar4 = param_1;
  do {
    pfVar5 = pfVar4 + -2;
    pfVar3 = pfVar2 + 2;
    fVar7 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    fVar8 = pfVar2[3] + pfVar4[0x7f];
    pfVar1 = pfVar1 + -1;
    fVar10 = *pfVar3 - pfVar4[0x7e];
    fVar9 = fVar7 * fVar8 + (0.5 - *pfVar1) * fVar10;
    fVar7 = -(fVar10 * fVar7) + (0.5 - *pfVar1) * fVar8;
    *pfVar3 = *pfVar3 - fVar9;
    pfVar2[3] = fVar7 - pfVar2[3];
    pfVar4[0x7e] = pfVar4[0x7e] + fVar9;
    pfVar4[0x7f] = fVar7 - pfVar4[0x7f];
    pfVar2 = pfVar3;
    pfVar4 = pfVar5;
  } while (param_1 + -0x3e != pfVar5);
  param_1[0x41] = -param_1[0x41];
  return;
}


