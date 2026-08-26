// 600d7b22  FUN_600d7b22  size=46 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d7b22(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    if (*(float *)(param_1 + 0x14) < 1.0) {
      func_0x6005df5c();
    }
    else {
      led_calibration__600d4596();
    }
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


