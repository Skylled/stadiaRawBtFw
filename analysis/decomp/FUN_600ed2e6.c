// 600ed2e6  FUN_600ed2e6  size=76 bytes
// --- callers ---
//   600ed42c FUN_600ed42c
//   600ed462 FUN_600ed462
// --- callees ---


undefined4 FUN_600ed2e6(undefined4 *param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  if ((uint)param_1[1] < param_3) {
    uVar1 = 0;
  }
  else {
    pbVar2 = (byte *)*param_1;
    uVar4 = 0;
    uVar5 = 0;
    pbVar3 = pbVar2 + param_3;
    param_1[1] = param_1[1] - param_3;
    *param_1 = pbVar3;
    for (; pbVar2 != pbVar3; pbVar2 = pbVar2 + 1) {
      uVar5 = uVar5 << 8 | uVar4 >> 0x18;
      uVar4 = (uint)*pbVar2 | uVar4 << 8;
    }
    uVar1 = 1;
    *param_2 = uVar4;
    param_2[1] = uVar5;
  }
  return uVar1;
}


