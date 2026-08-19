// 600db32c  FUN_600db32c  size=34 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


int * FUN_600db32c(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


