// 600ebda8  FUN_600ebda8  size=84 bytes
// --- callers ---
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600ebd38 FUN_600ebd38


undefined4 FUN_600ebda8(int param_1,byte *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte local_40 [48];
  
  if (param_4 != 0) {
    if (0x30 < param_4) {
      return 0;
    }
    thunk_EXT_FUN_0000af88(local_40,param_2,0x30);
    uVar2 = 0;
    do {
      local_40[uVar2] = local_40[uVar2] ^ *(byte *)(param_3 + uVar2);
      uVar2 = uVar2 + 1;
      param_2 = local_40;
    } while (param_4 != uVar2);
  }
  iVar1 = FUN_600ebd38(param_1,param_2,0x30);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x110) = 1;
  *(undefined4 *)(param_1 + 0x114) = 0;
  return 1;
}


