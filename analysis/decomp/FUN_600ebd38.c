// 600ebd38  FUN_600ebd38  size=112 bytes
// --- callers ---
//   600ebdfc FUN_600ebdfc
//   600ebda8 FUN_600ebda8
// --- callees ---
//   6008df70 FUN_6008df70
//   6013cf28 thunk_EXT_FUN_0000af88


undefined4 FUN_600ebd38(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  byte local_50 [32];
  undefined1 auStack_30 [20];
  
  iVar4 = 0;
  do {
    uVar3 = *(uint *)(param_1 + 0x108);
    pbVar2 = local_50 + iVar4;
    iVar4 = iVar4 + 0x10;
    uVar3 = (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18) + 1;
    *(uint *)(param_1 + 0x108) =
         uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
         uVar3 >> 0x18;
    (**(code **)(param_1 + 0xf4))(param_1 + 0xfc,pbVar2,param_1);
  } while (iVar4 != 0x30);
  for (iVar4 = 0; iVar4 != param_3; iVar4 = iVar4 + 1) {
    local_50[iVar4] = local_50[iVar4] ^ *(byte *)(param_2 + iVar4);
  }
  uVar1 = FUN_6008df70(param_1,0,param_1 + 0xf4,local_50,0x20);
  *(undefined4 *)(param_1 + 0xf8) = uVar1;
  thunk_EXT_FUN_0000af88(param_1 + 0xfc,auStack_30,0x10);
  return 1;
}


