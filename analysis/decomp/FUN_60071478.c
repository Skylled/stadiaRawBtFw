// 60071478  FUN_60071478  size=110 bytes
// --- callers ---
//   60071538 FUN_60071538
//   60071660 FUN_60071660
//   600714ec FUN_600714ec
//   600d9cc4 FUN_600d9cc4
//   600722b0 FUN_600722b0
//   60071f74 adc__60071f74
//   600723b4 FUN_600723b4
// --- callees ---
//   600d9ae2 FUN_600d9ae2


undefined4 *
FUN_60071478(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,undefined1 param_9,
            undefined1 param_10,undefined1 param_11,undefined1 param_12,undefined4 param_13)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[4] = param_6;
  param_1[5] = param_7;
  param_1[6] = param_8;
  *(undefined1 *)((int)param_1 + 0x1d) = param_10;
  *(undefined1 *)(param_1 + 7) = param_9;
  *(undefined1 *)((int)param_1 + 0x1e) = param_11;
  if (param_7 - 1U < 5) {
    uVar1 = *(undefined4 *)(DAT_600714e8 + (param_7 - 1U) * 4);
  }
  else {
    uVar1 = 0;
  }
  param_1[8] = uVar1;
  uVar1 = FUN_600d9ae2(param_9);
  *(char *)(param_1 + 9) = (char)uVar1;
  *(char *)((int)param_1 + 0x25) = (char)((uint)uVar1 >> 8);
  *(char *)((int)param_1 + 0x26) = (char)((uint)uVar1 >> 0x10);
  *(undefined1 *)((int)param_1 + 0x27) = param_12;
  param_1[10] = param_13;
  return param_1;
}


