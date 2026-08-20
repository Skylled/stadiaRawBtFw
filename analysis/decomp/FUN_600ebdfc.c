// 600ebdfc  FUN_600ebdfc  size=296 bytes
// --- callers ---
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   6013cee8 thunk_EXT_FUN_0000af90
//   600ebd38 FUN_600ebd38


undefined4 FUN_600ebdfc(int param_1,int param_2,uint param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  undefined1 auStack_38 [20];
  
  if (param_3 < 0x10001) {
    puVar5 = (uint *)(param_1 + 0x110);
    bVar6 = 0xffff < *(uint *)(param_1 + 0x114);
    if (*(uint *)(param_1 + 0x114) == 0x10000) {
      bVar6 = *puVar5 != 0;
    }
    if ((!bVar6) &&
       ((param_5 == 0 ||
        ((param_5 < 0x31 && (iVar1 = FUN_600ebd38(param_1,param_4,param_5), iVar1 != 0)))))) {
      for (; 0xf < param_3; param_3 = param_3 - uVar4) {
        uVar2 = param_3;
        if (0x1fff < param_3) {
          uVar2 = 0x2000;
        }
        uVar4 = uVar2 & 0xfffffff0;
        uVar3 = 0;
        if (*(int *)(param_1 + 0xf8) == 0) {
          for (; uVar3 < uVar4; uVar3 = uVar3 + 0x10) {
            uVar2 = *(uint *)(param_1 + 0x108);
            uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                    uVar2 >> 0x18) + 1;
            *(uint *)(param_1 + 0x108) =
                 uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                 uVar2 >> 0x18;
            (**(code **)(param_1 + 0xf4))(param_1 + 0xfc,param_2 + uVar3,param_1);
          }
        }
        else {
          thunk_EXT_FUN_0000af90(param_2,0,uVar4);
          uVar3 = *(uint *)(param_1 + 0x108);
          uVar3 = (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18) + 1;
          *(uint *)(param_1 + 0x108) =
               uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
               uVar3 >> 0x18;
          (**(code **)(param_1 + 0xf8))(param_2,param_2,uVar2 >> 4,param_1,param_1 + 0xfc);
          uVar3 = *(uint *)(param_1 + 0x108);
          uVar2 = ((uVar2 >> 4) - 1) +
                  (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18);
          *(uint *)(param_1 + 0x108) =
               uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
        }
        param_2 = param_2 + uVar4;
      }
      if (param_3 != 0) {
        uVar2 = *(uint *)(param_1 + 0x108);
        uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                uVar2 >> 0x18) + 1;
        *(uint *)(param_1 + 0x108) =
             uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
        (**(code **)(param_1 + 0xf4))(param_1 + 0xfc,auStack_38,param_1);
        thunk_EXT_FUN_0000af88(param_2,auStack_38,param_3);
      }
      if ((param_5 < 0x31) && (iVar1 = FUN_600ebd38(param_1,param_4,param_5), iVar1 != 0)) {
        uVar2 = *puVar5;
        *puVar5 = uVar2 + 1;
        *(uint *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + (uint)(0xfffffffe < uVar2);
        return 1;
      }
    }
  }
  return 0;
}


