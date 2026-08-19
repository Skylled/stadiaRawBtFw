// 600ddba4  FUN_600ddba4  size=32 bytes
// --- callers ---
//   6007dac0 FUN_6007dac0
// --- callees ---


void FUN_600ddba4(float param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  
  pfVar1 = param_3 + 0x41;
  for (; pfVar1 != param_3; param_3 = param_3 + 1) {
    *param_4 = param_1 * *param_3 * param_1;
    param_4 = param_4 + 1;
  }
  return;
}


