// 6008e164  bcm__6008e164  size=248 bytes
// src: bcm.c
// --- callers ---
//   6008e264 bcm__6008e264
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e0552 FUN_600e0552
//   6008e154 FUN_6008e154


/* src: bcm.c */

undefined4 bcm__6008e164(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  if ((param_3 + 1U < 2) || (param_3 == 1)) {
    if (param_4 < 2) {
      if (param_2 == 0) {
        param_1[3] = 0;
        param_1[1] = 0;
        return 1;
      }
      if (param_2 <= DAT_6008e260) {
        iVar8 = (param_2 + 0x1f) / 0x20;
        uVar7 = -(param_2 - 1U);
        uVar6 = param_2 - 1U & 0x1f;
        uVar4 = uVar7 & 0x1f;
        if (-1 < (int)uVar7) {
          uVar6 = -uVar4;
        }
        if (uVar6 == 0x1f) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = (1 << (uVar6 + 1 & 0xff)) - 1;
        }
        iVar1 = bcm__6008b43c(param_1,iVar8,param_3,uVar4,param_1,param_2,param_3);
        if (iVar1 == 0) {
          return 0;
        }
        FUN_6008e154(*param_1,iVar8 * 4);
        puVar5 = (uint *)*param_1;
        uVar7 = uVar7 & puVar5[iVar8 + -1];
        if (param_3 != -1) {
          if ((param_3 == 1) && (1 < param_2)) {
            if (uVar6 == 0) {
              puVar5[iVar8 + -1] = uVar7 | 1;
              puVar5[iVar8 + -2] = puVar5[iVar8 + -2] | 0x80000000;
              goto LAB_6008e234;
            }
            uVar6 = uVar6 - 1;
            iVar1 = 3;
          }
          else {
            iVar1 = 1;
          }
          uVar7 = uVar7 | iVar1 << (uVar6 & 0xff);
        }
        puVar5[iVar8 + -1] = uVar7;
LAB_6008e234:
        if (param_4 == 1) {
          *puVar5 = *puVar5 | 1;
        }
        param_1[1] = iVar8;
        param_1[3] = 0;
        return 1;
      }
      uVar2 = 0x66;
      uVar3 = 0x91;
      goto LAB_6008e18c;
    }
    uVar3 = 0x87;
  }
  else {
    uVar3 = 0x82;
  }
  uVar2 = 0x42;
LAB_6008e18c:
  FUN_600e0552(3,0,uVar2,DAT_6008e25c,uVar3);
  return 0;
}


