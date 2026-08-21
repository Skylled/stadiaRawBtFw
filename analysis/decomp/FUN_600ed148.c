// 600ed148  FUN_600ed148  size=108 bytes
// --- callers ---
//   600ed1b4 FUN_600ed1b4
// --- callees ---
//   600ed12a FUN_600ed12a


undefined4 FUN_600ed148(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 0;
  uVar3 = param_3;
  uVar2 = param_4;
  while (uVar3 != 0 || uVar2 != 0) {
    uVar6 = uVar6 + 1;
    uVar3 = uVar3 >> 7 | uVar2 << 0x19;
    uVar2 = uVar2 >> 7;
  }
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  uVar8 = uVar6 - 1;
  uVar3 = uVar6 * 7;
  uVar2 = param_4;
  while( true ) {
    uVar7 = uVar3 - 7;
    uVar4 = param_4 << (0x20 - uVar7 & 0xff);
    uVar5 = param_4 >> (uVar3 - 0x27 & 0xff);
    uVar3 = (param_3 >> (uVar7 & 0xff) | uVar4 | uVar5) & 0x7f;
    if (uVar8 != 0) {
      uVar3 = uVar3 | 0x80;
    }
    iVar1 = FUN_600ed12a(param_1,uVar3,uVar4,uVar5,uVar2);
    if (iVar1 == 0) break;
    uVar8 = uVar8 - 1;
    uVar3 = uVar7;
    if (uVar6 <= uVar8) {
      return 1;
    }
  }
  return 0;
}


