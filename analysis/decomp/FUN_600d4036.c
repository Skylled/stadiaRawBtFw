// 600d4036  FUN_600d4036  size=32 bytes
// --- callers ---
//   6005b850 application_state__6005b850
//   6005b794 application_state__6005b794
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60079adc FUN_60079adc


int * FUN_600d4036(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60079adc(param_2,*param_1 + param_1[2],param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


