// 600d1156  FUN_600d1156  size=34 bytes
// --- callers ---
//   600d0332 FUN_600d0332
//   600d0c6a FUN_600d0c6a
//   60054a54 usb_device_cdc_acm__60054a54
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d1156(undefined4 param_1,uint3 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_2 & 0xf) < 8) {
    uVar1 = FUN_600d0ede(param_1,5,&stack0xfffffff7,param_4,param_1,CONCAT13((char)param_2,param_2))
    ;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


