// 60045e4c  FUN_60045e4c  size=438 bytes
// --- callers ---
//   6004abfe FUN_6004abfe
// --- callees ---
//   6004a34c FUN_6004a34c
//   6004ab84 FUN_6004ab84
//   6004a9da FUN_6004a9da
//   6004bda4 FUN_6004bda4
//   6004aa8a FUN_6004aa8a
//   60045ddc FUN_60045ddc
//   6004bd8e FUN_6004bd8e


void FUN_60045e4c(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined1 ***param_7)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 ***extraout_r1;
  undefined1 ***pppuVar3;
  undefined1 ***pppuVar4;
  int iVar5;
  float fVar6;
  undefined1 **ppuVar7;
  float extraout_s10;
  float extraout_s10_00;
  undefined4 *local_340;
  undefined1 **local_33c;
  undefined4 local_338;
  undefined4 auStack_334 [65];
  undefined1 auStack_230 [260];
  undefined1 *local_12c;
  undefined4 local_128;
  
  iVar5 = *param_1;
  uVar1 = *(undefined1 *)(param_3 + 0x68);
  fVar6 = *(float *)(iVar5 + 0x80) * *(float *)(iVar5 + 0x84);
  FUN_60045ddc(fVar6,1.0 / (fVar6 - *(float *)(iVar5 + 0x80)),0,3,param_5,auStack_334);
  fVar6 = *(float *)(iVar5 + 0x80) * *(float *)(iVar5 + 0x88);
  FUN_60045ddc(fVar6,extraout_s10 / (fVar6 - *(float *)(iVar5 + 0x80)),3,7,param_5,auStack_334);
  fVar6 = *(float *)(iVar5 + 0x80) * *(float *)(iVar5 + 0x8c);
  FUN_60045ddc(fVar6,extraout_s10_00 / (fVar6 - *(float *)(iVar5 + 0x80)),7,0x41,param_5,auStack_334
              );
  local_128 = 0x41;
  local_338 = 0x41;
  local_33c = (undefined1 **)auStack_334;
  local_12c = auStack_230;
  uVar2 = FUN_6004aa8a(param_1,auStack_334,0x41,param_2,uVar1,auStack_230,0x41);
  local_338 = 0x41;
  local_33c = &local_12c;
  FUN_6004ab84(uVar2,&local_12c,0x41);
  FUN_6004a9da(param_1,param_4,auStack_334,param_6,auStack_230,&local_12c,param_7);
  pppuVar4 = param_7 + 0x10;
  ppuVar7 = param_7[1];
  if ((int)((uint)((float)param_7[2] < (float)param_7[1]) << 0x1f) < 0) {
    ppuVar7 = param_7[2];
  }
  param_7[1] = ppuVar7;
  *param_7 = ppuVar7;
  local_340 = *pppuVar4;
  pppuVar3 = extraout_r1;
  for (; fVar6 = DAT_60046004, param_7 + 0x40 != pppuVar4; pppuVar4 = pppuVar4 + 1) {
    iVar5 = (uint)((float)local_340 < (float)*pppuVar4) << 0x1f;
    if (-1 < iVar5) {
      pppuVar3 = pppuVar4;
    }
    if (iVar5 < 0) {
      pppuVar3 = (undefined1 ***)&local_340;
    }
    pppuVar3 = (undefined1 ***)*pppuVar3;
    *pppuVar4 = (undefined1 **)pppuVar3;
  }
  pppuVar3 = param_7 + 0x14;
  param_7[0x40] = param_7[0x3f];
  pppuVar4 = param_7 + 0x1d;
  for (; pppuVar4 != pppuVar3; pppuVar3 = pppuVar3 + 1) {
    fVar6 = fVar6 + (float)*pppuVar3;
  }
  local_33c = (undefined1 **)(fVar6 * DAT_60046008);
  for (; param_7 + 0x41 != pppuVar3; pppuVar3 = pppuVar3 + 1) {
    iVar5 = (uint)((float)local_33c < (float)*pppuVar3) << 0x1f;
    if (-1 < iVar5) {
      pppuVar4 = pppuVar3;
    }
    if (iVar5 < 0) {
      pppuVar4 = &local_33c;
    }
    pppuVar4 = (undefined1 ***)*pppuVar4;
    *pppuVar3 = (undefined1 **)pppuVar4;
  }
  FUN_6004bda4(param_1 + 0x44,param_4,0x104);
  FUN_6004bd8e(param_1 + 0x85,auStack_334,0x104);
  if (pppuVar3 != param_7) {
    FUN_6004bda4(param_1 + 3,param_7,(int)pppuVar3 - (int)param_7);
  }
  for (; pppuVar3 != param_7; param_7 = param_7 + 1) {
    ppuVar7 = (undefined1 **)FUN_6004a34c(*param_7);
    *param_7 = ppuVar7;
  }
  return;
}


