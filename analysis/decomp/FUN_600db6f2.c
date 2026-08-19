// 600db6f2  FUN_600db6f2  size=34 bytes
// --- callers ---
//   60079668 http_flash_writer__60079668
//   60079778 http_flash_writer__60079778
//   6007952c http_flash_writer__6007952c
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


int * FUN_600db6f2(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


