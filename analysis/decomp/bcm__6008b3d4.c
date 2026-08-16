// 6008b3d4  bcm__6008b3d4  size=100 bytes
// src: bcm.c
// --- callers ---
//   6008cf98 bcm__6008cf98
//   6008d7ac bcm__6008d7ac
//   6008c334 bcm__6008c334
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e72d2 FUN_600e72d2
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008b3d4(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  if (param_3[3] == 0) {
    uVar2 = 0;
    uVar3 = param_3[1];
    uVar4 = param_1;
    uVar5 = param_2;
    puVar6 = param_3;
    if ((param_2 < (uint)param_3[1]) &&
       (iVar1 = FUN_600e72d2(param_3), uVar2 = extraout_r3, uVar3 = param_2, iVar1 == 0)) {
      FUN_600e0552(3,0,0x66,DAT_6008b438,0x143);
      uVar2 = 0;
    }
    else {
      thunk_EXT_FUN_0000af90(param_1,0,param_2 << 2,uVar2,uVar4,uVar5,puVar6);
      thunk_EXT_FUN_0000af88(param_1,*param_3,uVar3 << 2);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
    FUN_600e0552(3,0,0x6d,DAT_6008b438,0x13c);
  }
  return uVar2;
}


