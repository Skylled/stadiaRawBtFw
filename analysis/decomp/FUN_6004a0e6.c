// 6004a0e6  FUN_6004a0e6  size=248 bytes
// --- callers ---
//   60049c98 FUN_60049c98
// --- callees ---
//   6004c434 thunk_FUN_6007d578
//   6004c0a4 thunk_FUN_600dd364
//   6004be3c thunk_FUN_600dcd46
//   6004a04c FUN_6004a04c
//   6004c184 thunk_FUN_6007d5fc
//   6004c3dc thunk_FUN_600dd5a0


void FUN_6004a0e6(uint param_1,int param_2,float *param_3,uint *param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  
  uVar1 = *param_4;
  if (uVar1 * 4 < param_1) {
    uVar1 = param_1 >> 2;
    thunk_FUN_6007d5fc(uVar1,param_4,param_5);
  }
  uVar2 = param_4[1];
  if (uVar2 * 4 < param_1) {
    uVar2 = param_1 >> 2;
    thunk_FUN_6007d578(uVar2,param_4,param_5 + uVar1 * 4);
  }
  if (param_2 < 0) {
    fVar3 = (*param_3 - param_3[1]) * 0.5;
    param_3[1] = fVar3;
    *param_3 = *param_3 - fVar3;
    if (4 < param_1) {
      thunk_FUN_600dd5a0(param_1,param_3,uVar2,param_5 + uVar1 * 4);
      thunk_FUN_600dcd46(param_1,param_4 + 2,param_3);
                    /* WARNING: Could not recover jumptable at 0x6004bf8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_6004bf90)(param_1,param_3,param_5);
      return;
    }
    if (param_1 == 4) {
      thunk_FUN_600dd364(4,param_3,param_5);
      return;
    }
  }
  else {
    if (param_1 < 5) {
      if (param_1 == 4) {
        thunk_FUN_600dd364(4,param_3,param_5);
      }
    }
    else {
      thunk_FUN_600dcd46(param_1,param_4 + 2,param_3);
      thunk_FUN_600dd364(param_1,param_3,param_5);
      FUN_6004a04c(param_1,param_3,uVar2,param_5 + uVar1 * 4);
    }
    fVar3 = *param_3;
    *param_3 = fVar3 + param_3[1];
    param_3[1] = fVar3 - param_3[1];
  }
  return;
}


