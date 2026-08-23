// 600ed682  FUN_600ed682  size=160 bytes
// --- callers ---
// --- callees ---
//   600ed3ba FUN_600ed3ba
//   600ed656 FUN_600ed656


undefined4 FUN_600ed682(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uStack_24 = param_2;
  uStack_20 = param_3;
  iVar1 = FUN_600ed3ba(param_1,(int)&uStack_24 + 3,param_3,param_4,param_1);
  if (iVar1 == 0) {
LAB_600ed694:
    uVar2 = 0;
  }
  else {
    uVar4 = (uint)uStack_24 >> 0x18;
    if ((int)(uVar4 << 0x18) < 0) {
      if ((uVar4 & 0xe0) == 0xc0) {
        uVar4 = uVar4 & 0x1f;
        iVar1 = 1;
        uVar5 = 0x80;
      }
      else if ((uVar4 & 0xf0) == 0xe0) {
        uVar4 = uVar4 & 0xf;
        iVar1 = 2;
        uVar5 = 0x800;
      }
      else {
        if ((uVar4 & 0xf8) != 0xf0) goto LAB_600ed694;
        uVar4 = uVar4 & 7;
        iVar1 = 3;
        uVar5 = 0x10000;
      }
      iVar6 = 0;
      do {
        iVar3 = FUN_600ed3ba(param_1,(int)&uStack_24 + 3);
        if ((iVar3 == 0) || (((uint)uStack_24 >> 0x18 & 0xc0) != 0x80)) goto LAB_600ed694;
        iVar6 = iVar6 + 1;
        uVar4 = (uint)uStack_24 >> 0x18 & 0x3f | uVar4 << 6;
      } while (iVar1 != iVar6);
      iVar1 = FUN_600ed656(uVar4);
      if ((iVar1 == 0) || (uVar4 < uVar5)) goto LAB_600ed694;
    }
    *param_2 = uVar4;
    uVar2 = 1;
  }
  return uVar2;
}


