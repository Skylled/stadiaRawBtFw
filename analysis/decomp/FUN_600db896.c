// 600db896  FUN_600db896  size=34 bytes
// --- callers ---
//   6007a2c0 frames__6007a2c0
//   6007a118 usb_audio_receive__6007a118
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60050c18 FUN_60050c18


int * FUN_600db896(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


