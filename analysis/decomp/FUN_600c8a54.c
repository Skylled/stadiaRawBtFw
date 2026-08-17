// 600c8a54  FUN_600c8a54  size=110 bytes
// --- callers ---
//   600ffe42 FUN_600ffe42
// --- callees ---
//   601002bc FUN_601002bc
//   60100424 FUN_60100424
//   601004b2 FUN_601004b2


void FUN_600c8a54(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  if (param_4 == 6) {
    local_c = DAT_600c8ac4;
  }
  else if (param_4 == 8) {
    local_c = DAT_600c8ac8;
  }
  iVar1 = FUN_60100424(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar1 = FUN_601002bc(param_1,local_c,param_4);
    if (-1 < iVar1) {
      FUN_601004b2(param_1,param_1,local_c,param_4);
    }
  }
  else {
    FUN_601004b2(param_1,param_1,local_c,param_4);
  }
  return;
}


