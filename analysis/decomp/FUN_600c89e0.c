// 600c89e0  FUN_600c89e0  size=106 bytes
// --- callers ---
//   600fffbc FUN_600fffbc
//   600ffe42 FUN_600ffe42
// --- callees ---
//   601002bc FUN_601002bc
//   60100616 FUN_60100616
//   601004b2 FUN_601004b2


void FUN_600c89e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  if (param_3 == 6) {
    local_c = DAT_600c8a4c;
  }
  else if (param_3 == 8) {
    local_c = DAT_600c8a50;
  }
  iVar1 = FUN_60100616(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_601002bc(param_1,local_c,param_3);
    if (-1 < iVar1) {
      FUN_601004b2(param_1,param_1,local_c,param_3);
    }
  }
  else {
    FUN_601004b2(param_1,param_1,local_c,param_3);
  }
  return;
}


