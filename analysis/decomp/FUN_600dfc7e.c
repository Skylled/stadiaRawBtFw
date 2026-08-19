// 600dfc7e  FUN_600dfc7e  size=34 bytes
// --- callers ---
//   6006c340 remote_device_db__6006c340
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60050c18 FUN_60050c18


int * FUN_600dfc7e(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


