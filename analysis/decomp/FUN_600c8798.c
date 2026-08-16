// 600c8798  FUN_600c8798  size=574 bytes
// --- callers ---
//   600c1030 FUN_600c1030
//   600fc4d8 FUN_600fc4d8
// --- callees ---
//   6010027c FUN_6010027c
//   600ffe42 FUN_600ffe42
//   600c9aac FUN_600c9aac
//   60100246 FUN_60100246
//   600fffbc FUN_600fffbc
//   601004b2 FUN_601004b2
//   600ffe0c FUN_600ffe0c
//   60100166 FUN_60100166
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   601005f6 FUN_601005f6
//   600ffe26 FUN_600ffe26
//   601005ac FUN_601005ac


void FUN_600c8798(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_124 [96];
  undefined1 auStack_c4 [32];
  undefined1 auStack_a4 [32];
  undefined4 local_84 [8];
  uint local_64;
  byte abStack_60 [68];
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  
  if (param_4 == 8) {
    local_18 = DAT_600c89d8;
  }
  else {
    local_18 = DAT_600c89dc;
  }
  FUN_600ffe0c(auStack_124);
  FUN_60100246(param_2 + 0x40,param_4);
  *(undefined4 *)(param_2 + 0x40) = 1;
  FUN_600ffe0c(param_1);
  FUN_6010027c(auStack_c4,param_2,param_4);
  FUN_601004b2(auStack_a4,local_18,param_2 + 0x20,param_4);
  FUN_60100246(local_84,param_4);
  local_84[0] = 1;
  thunk_EXT_FUN_0000b5ba(abStack_60,0,0x41);
  FUN_60100166(abStack_60,&local_64,param_3,param_4);
  while (local_14 = local_64 - 1, -1 < (int)local_14) {
    FUN_600ffe26(auStack_124,param_1);
    FUN_600ffe42(param_1,auStack_124,param_4);
    uVar1 = local_14;
    if ((int)local_14 < 0) {
      uVar1 = local_14 + 3;
    }
    uVar2 = local_14 & 3;
    if (-1 < (int)-local_14) {
      uVar2 = -(-local_14 & 3);
    }
    local_1c = (int)(uint)abStack_60[(int)uVar1 >> 2] >> ((uVar2 & 0x7f) << 1) & 3;
    if (local_1c == 1) {
      FUN_600ffe26(auStack_124,param_1);
      FUN_600fffbc(param_1,auStack_124,param_2,param_4);
      local_64 = local_14;
    }
    else {
      local_64 = local_14;
      if (local_1c == 3) {
        FUN_600ffe26(auStack_124,param_1);
        FUN_600fffbc(param_1,auStack_124,auStack_c4,param_4);
        local_64 = local_14;
      }
    }
  }
  FUN_600c9aac(auStack_c4,param_1 + 0x40,param_4);
  FUN_601005f6(param_1 + 0x40,auStack_c4,param_4);
  FUN_601005ac(param_1,param_1,param_1 + 0x40,param_4);
  FUN_601005ac(param_1 + 0x40,param_1 + 0x40,auStack_c4,param_4);
  FUN_601005ac(param_1 + 0x20,param_1 + 0x20,param_1 + 0x40,param_4);
  return;
}


