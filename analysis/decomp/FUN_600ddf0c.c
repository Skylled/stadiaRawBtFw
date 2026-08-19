// 600ddf0c  FUN_600ddf0c  size=210 bytes
// --- callers ---
// --- callees ---
//   6013cf20 thunk_EXT_FUN_00005614


void FUN_600ddf0c(float *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,int param_7,undefined1 param_8)

{
  undefined4 uVar1;
  int extraout_r2;
  uint uVar2;
  float fVar3;
  float fVar4;
  float extraout_s13;
  float extraout_s14;
  
  uVar1 = param_2;
  if (param_3 == 0) {
    uVar1 = 0;
  }
  thunk_EXT_FUN_00005614(uVar1,param_2,param_8);
  if (param_5 == 0) {
    param_4 = 0;
  }
  thunk_EXT_FUN_00005614(param_4);
  if (param_7 == 0) {
    param_6 = 0;
  }
  fVar4 = (float)thunk_EXT_FUN_00005614(param_6);
  if ((((extraout_r2 != 0) && (*(char *)(param_1 + 5) == '\0')) ||
      (extraout_s14 * *param_1 <= extraout_s13)) ||
     (-1 < (int)((uint)(fVar4 * param_1[2] < extraout_s14) << 0x1f))) {
    uVar2 = (int)param_1[6] - 1;
    param_1[6] = (float)(uVar2 & ~((int)uVar2 >> 0x1f));
  }
  else {
    fVar3 = (float)((int)param_1[6] + 1);
    param_1[6] = fVar3;
    if ((int)param_1[4] <= (int)fVar3) {
      param_1[6] = param_1[4];
      param_1[7] = param_1[3];
    }
  }
  if (((int)((uint)(extraout_s14 * param_1[1] < extraout_s13) << 0x1f) < 0) &&
     ((int)((uint)(fVar4 * param_1[2] < extraout_s13) << 0x1f) < 0)) {
    param_1[7] = 0.0;
  }
  fVar4 = param_1[7];
  uVar2 = (int)fVar4 - 1;
  param_1[7] = (float)(uVar2 & ~((int)uVar2 >> 0x1f));
  *(bool *)((int)param_1 + 0x15) = 1 < (int)fVar4;
  return;
}


