// 600d88d6  FUN_600d88d6  size=30 bytes
// --- callers ---
//   60081234 advertiser__60081234
// --- callees ---
//   60092edc FUN_60092edc


undefined4 FUN_600d88d6(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  FUN_60092edc(0xff,uVar1,0xff,0xff,param_4);
  return 0;
}


