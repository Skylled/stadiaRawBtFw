// 6008f1bc  asn1_lib__6008f1bc  size=256 bytes
// src: asn1_lib.c
// --- callers ---
//   6008f370 tasn_dec__6008f370
// --- callees ---
//   600e0552 FUN_600e0552


/* src: asn1_lib.c */

uint asn1_lib__6008f1bc(undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  if (param_5 != 0) {
    pbVar9 = (byte *)*param_1;
    iVar4 = param_5 + -1;
    pbVar7 = pbVar9 + 1;
    bVar1 = *pbVar9;
    uVar6 = (uint)bVar1;
    uVar3 = uVar6 & 0x1f;
    if (uVar3 == 0x1f) {
      if (iVar4 != 0) {
        uVar3 = 0;
        pbVar8 = pbVar7;
        while( true ) {
          pbVar7 = pbVar8 + 1;
          bVar2 = *pbVar8;
          iVar4 = iVar4 + -1;
          if ((bVar2 & 0x80) == 0) break;
          uVar3 = bVar2 & 0x7f | uVar3 << 7;
          if ((iVar4 == 0) || (pbVar8 = pbVar7, 0xffffff < (int)uVar3)) goto LAB_6008f216;
        }
        if ((iVar4 != 0) &&
           ((uVar3 = (uint)bVar2 | uVar3 << 7, (bVar1 & 0xc0) != 0 || ((int)uVar3 < 0x100))))
        goto LAB_6008f22e;
      }
    }
    else if (iVar4 != 0) {
LAB_6008f22e:
      *param_3 = uVar3;
      *param_4 = uVar6 & 0xc0;
      if (0 < iVar4) {
        pbVar8 = pbVar7 + 1;
        bVar2 = *pbVar7;
        if (bVar2 == 0x80) {
          uVar5 = 1;
          uVar3 = 0;
        }
        else {
          uVar3 = bVar2 & 0x7f;
          if ((bVar2 & 0x80) != 0) {
            if ((4 < uVar3) || (iVar4 <= (int)uVar3)) goto LAB_6008f216;
            uVar5 = 0;
            for (pbVar10 = pbVar8; pbVar7 + uVar3 + 1 != pbVar10; pbVar10 = pbVar10 + 1) {
              uVar5 = (uint)*pbVar10 | uVar5 << 8;
            }
            pbVar8 = pbVar8 + uVar3;
            uVar3 = uVar5;
            if (0x3fffffff < uVar5) goto LAB_6008f216;
          }
          uVar5 = 0;
        }
        uVar6 = uVar6 & 0x20;
        *param_2 = uVar3;
        if ((uVar5 == 0) || ((bVar1 & 0x20) != 0)) {
          if (param_5 - ((int)pbVar8 - (int)pbVar9) < (int)uVar3) {
            uVar6 = uVar6 | 0x80;
            FUN_600e0552(0xc,0,0xb1,DAT_6008f2bc,0xa8,param_2,param_3);
          }
          *param_1 = pbVar8;
          return uVar6 | uVar5;
        }
      }
    }
  }
LAB_6008f216:
  FUN_600e0552(0xc,0,0x7b,DAT_6008f2bc,0xb2,param_2,param_3);
  return 0x80;
}


