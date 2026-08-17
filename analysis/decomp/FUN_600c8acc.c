// 600c8acc  FUN_600c8acc  size=80 bytes
// --- callers ---
//   600c9aac FUN_600c9aac
//   600fffbc FUN_600fffbc
//   600ffe42 FUN_600ffe42
// --- callees ---
//   60100424 FUN_60100424
//   601004b2 FUN_601004b2


void FUN_600c8acc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  if (param_4 == 6) {
    local_c = DAT_600c8b1c;
  }
  else if (param_4 == 8) {
    local_c = DAT_600c8b20;
  }
  iVar1 = FUN_601004b2(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    FUN_60100424(param_1,param_1,local_c,param_4);
  }
  return;
}


