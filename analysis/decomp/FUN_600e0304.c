// 600e0304  FUN_600e0304  size=340 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   60084d1c FUN_60084d1c
//   60084cc4 FUN_60084cc4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d1b0 thunk_EXT_FUN_00006668


undefined4 FUN_600e0304(undefined4 param_1,byte *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 local_48;
  undefined1 local_44 [2];
  undefined1 auStack_42 [2];
  undefined2 local_40;
  undefined4 local_3c;
  byte abStack_38 [16];
  undefined2 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  thunk_EXT_FUN_0000b5ba(abStack_38,0,0x1c);
  pbVar5 = param_2;
  local_3c = param_1;
  local_1c = param_4;
  while (uVar4 = local_24, param_2 + param_3 != pbVar5) {
    if (local_24 == 0) {
      FUN_60084cc4(local_3c,local_1c,0xffffffff);
      FUN_60084d1c(&local_48,local_20._3_1_);
      FUN_60084d1c((int)&local_48 + 2,local_20._2_1_);
      FUN_60084d1c(local_44,local_20._1_1_);
      FUN_60084d1c(auStack_42,local_20 & 0xff);
      local_40 = 0x2020;
      iVar1 = thunk_EXT_FUN_00006668(local_3c,&local_48,10);
      if (iVar1 < 0) {
        return 0;
      }
    }
    FUN_60084d1c(&local_48,*pbVar5);
    local_48._0_3_ = CONCAT12(0x20,(undefined2)local_48);
    if (local_24 == 7) {
      uVar3 = 4;
      local_48 = CONCAT13(0x20,(undefined3)local_48);
    }
    else if (local_24 == 0xf) {
      local_48 = CONCAT13(0x20,(undefined3)local_48);
      uVar3 = 5;
      local_44[0] = 0x7c;
    }
    else {
      uVar3 = 3;
    }
    iVar1 = thunk_EXT_FUN_00006668(local_3c,&local_48,uVar3);
    if (iVar1 < 0) {
      return 0;
    }
    pbVar6 = pbVar5 + 1;
    bVar2 = *pbVar5;
    if (0x5e < bVar2 - 0x20) {
      bVar2 = 0x2e;
    }
    uVar4 = local_24 + 1;
    abStack_38[local_24] = bVar2;
    local_20 = local_20 + 1;
    pbVar5 = pbVar6;
    local_24 = uVar4;
    if (uVar4 == 0x10) {
      local_28 = 0xa7c;
      iVar1 = thunk_EXT_FUN_00006668(local_3c,abStack_38,0x12);
      if (iVar1 < 0) {
        return 0;
      }
      local_24 = 0;
    }
  }
  if (local_24 != 0) {
    local_48 = 0x20202020;
    local_44[0] = 0x7c;
    for (; local_24 < 0x10; local_24 = local_24 + 1) {
      iVar1 = thunk_EXT_FUN_00006668(local_3c,&local_48);
      if (iVar1 < 0) {
        return 0;
      }
    }
    abStack_38[uVar4] = 0x7c;
    abStack_38[uVar4 + 1] = 10;
    iVar1 = thunk_EXT_FUN_00006668(local_3c,abStack_38,uVar4 + 2);
    if (iVar1 < 0) {
      return 0;
    }
  }
  return 1;
}


