// 600ffe42  FUN_600ffe42  size=378 bytes
// --- callers ---
//   600fffbc FUN_600fffbc
//   600c8798 FUN_600c8798
// --- callees ---
//   601005f6 FUN_601005f6
//   60100324 FUN_60100324
//   600c89e0 FUN_600c89e0
//   600c8a54 FUN_600c8a54
//   600c8acc FUN_600c8acc
//   601005ac FUN_601005ac
//   60100246 FUN_60100246


void FUN_600ffe42(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [32];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = FUN_60100324(param_2 + 0x40,param_3);
  if (iVar1 == 0) {
    local_10 = param_2 + 0x20;
    local_14 = param_2 + 0x40;
    local_1c = param_1 + 0x20;
    local_20 = param_1 + 0x40;
    local_18 = param_1;
    local_c = param_2;
    FUN_601005f6(auStack_40,local_14,param_3);
    FUN_600c8acc(auStack_60,local_c,auStack_40,param_3);
    FUN_600c8a54(auStack_40,local_c,auStack_40,param_3);
    FUN_601005ac(auStack_60,auStack_40,auStack_60,param_3);
    FUN_600c89e0(auStack_80,auStack_60,param_3);
    FUN_600c8a54(auStack_60,auStack_80,auStack_60,param_3);
    FUN_601005ac(local_20,local_10,local_14,param_3);
    FUN_600c89e0(local_20,local_20,param_3);
    FUN_601005f6(local_1c,local_10,param_3);
    FUN_600c89e0(local_1c,local_1c,param_3);
    FUN_601005ac(auStack_80,local_1c,local_c,param_3);
    FUN_600c89e0(auStack_80,auStack_80,param_3);
    FUN_601005f6(local_1c,local_1c,param_3);
    FUN_600c89e0(local_1c,local_1c,param_3);
    FUN_601005f6(local_18,auStack_60,param_3);
    FUN_600c89e0(auStack_40,auStack_80,param_3);
    FUN_600c8acc(local_18,local_18,auStack_40,param_3);
    FUN_600c8acc(auStack_40,auStack_80,local_18,param_3);
    FUN_601005ac(auStack_40,auStack_40,auStack_60,param_3);
    FUN_600c8acc(local_1c,auStack_40,local_1c,param_3);
  }
  else {
    FUN_60100246(param_1 + 0x40,param_3);
  }
  return;
}


