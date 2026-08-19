// 600ded7e  FUN_600ded7e  size=46 bytes
// --- callers ---
//   6007ec28 FUN_6007ec28
// --- callees ---
//   6007f510 FUN_6007f510
//   6013d3c8 thunk_EXT_FUN_00001680
//   600debb4 FUN_600debb4


void FUN_600ded7e(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uStack_14;
  int local_10;
  undefined4 uStack_c;
  
  uStack_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  FUN_6007f510(&local_10);
  if (local_10 != 0) {
    if (param_1 == 0) {
      uStack_14 = uStack_14 & 0xffffff;
    }
    else {
      uStack_14 = CONCAT13(1,(undefined3)uStack_14);
    }
    FUN_600debb4(local_10,(int)&uStack_14 + 3);
  }
  thunk_EXT_FUN_00001680(&uStack_c);
  return;
}


