// 601005ac  FUN_601005ac  size=74 bytes
// --- callers ---
//   600fffbc FUN_600fffbc
//   600ffe42 FUN_600ffe42
//   600c8798 FUN_600c8798
//   601005f6 FUN_601005f6
// --- callees ---
//   60100680 FUN_60100680
//   600c8fd8 FUN_600c8fd8
//   600c8b24 FUN_600c8b24


void FUN_601005ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 auStack_48 [64];
  
  FUN_60100680(auStack_48,param_2,param_3,param_4);
  if (param_4 == 6) {
    FUN_600c8b24(param_1,auStack_48);
  }
  else if (param_4 == 8) {
    FUN_600c8fd8(param_1,auStack_48);
  }
  return;
}


