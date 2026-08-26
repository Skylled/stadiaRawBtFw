// 600fffbc  FUN_600fffbc  size=426 bytes
// --- callers ---
//   600c8798 FUN_600c8798
// --- callees ---
//   601005f6 FUN_601005f6
//   600ffe42 FUN_600ffe42
//   60100324 FUN_60100324
//   600ffe26 FUN_600ffe26
//   600c89e0 FUN_600c89e0
//   600c8acc FUN_600c8acc
//   601005ac FUN_601005ac
//   60100246 FUN_60100246


void FUN_600fffbc(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_6c [32];
  undefined1 auStack_4c [32];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = param_2 + 0x20;
  local_14 = param_2 + 0x40;
  local_1c = param_3 + 0x20;
  local_20 = param_3 + 0x40;
  local_28 = param_1 + 0x20;
  local_2c = param_1 + 0x40;
  local_24 = param_1;
  local_18 = param_3;
  local_c = param_2;
  iVar1 = FUN_60100324(local_20,param_4);
  if (iVar1 == 0) {
    iVar1 = FUN_60100324(local_14,param_4);
    if (iVar1 == 0) {
      FUN_601005f6(auStack_4c,local_14,param_4);
      FUN_601005ac(auStack_6c,local_14,auStack_4c,param_4);
      FUN_601005ac(auStack_4c,local_18,auStack_4c,param_4);
      FUN_601005ac(auStack_6c,local_1c,auStack_6c,param_4);
      FUN_600c8acc(auStack_4c,auStack_4c,local_c,param_4);
      FUN_600c8acc(auStack_6c,auStack_6c,local_10,param_4);
      iVar1 = FUN_60100324(auStack_4c,param_4);
      if (iVar1 == 0) {
        FUN_601005ac(local_2c,local_14,auStack_4c,param_4);
        FUN_601005f6(local_28,auStack_4c,param_4);
        FUN_601005ac(local_14,local_28,auStack_4c,param_4);
        FUN_601005ac(local_28,local_28,local_c,param_4);
        FUN_600c89e0(auStack_4c,local_28,param_4);
        FUN_601005f6(local_24,auStack_6c,param_4);
        FUN_600c8acc(local_24,local_24,auStack_4c,param_4);
        FUN_600c8acc(local_24,local_24,local_14,param_4);
        FUN_600c8acc(local_28,local_28,local_24,param_4);
        FUN_601005ac(local_28,local_28,auStack_6c,param_4);
        FUN_601005ac(local_14,local_14,local_10,param_4);
        FUN_600c8acc(local_28,local_28,local_14,param_4);
      }
      else {
        iVar1 = FUN_60100324(auStack_6c,param_4);
        if (iVar1 == 0) {
          FUN_60100246(local_2c,param_4);
        }
        else {
          FUN_600ffe42(param_1,param_3,param_4);
        }
      }
    }
    else {
      FUN_600ffe26(param_1,param_3);
    }
  }
  else {
    FUN_600ffe26(param_1,param_2);
  }
  return;
}


