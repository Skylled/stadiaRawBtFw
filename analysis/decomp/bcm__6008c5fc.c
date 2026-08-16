// 6008c5fc  bcm__6008c5fc  size=290 bytes
// src: bcm.c
// --- callers ---
//   6008e264 bcm__6008e264
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e9dea FUN_600e9dea
//   6008bb90 bcm__6008bb90
//   6008bf00 FUN_6008bf00
//   600e7718 FUN_600e7718
//   600e75c2 FUN_600e75c2
//   6008b570 bcm__6008b570
//   600e72fc FUN_600e72fc
//   600e7706 FUN_600e7706
//   600e0552 FUN_600e0552
//   600e76ee FUN_600e76ee


/* src: bcm.c */

int bcm__6008c5fc(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  
  iVar4 = param_2;
  iVar1 = FUN_600e7706(param_2);
  if (iVar1 == 0) {
    uVar6 = 0x68;
    uVar10 = 0x49;
  }
  else {
    if (*(int *)(param_2 + 0xc) == 0) {
      FUN_600e7718(extraout_r2,iVar1);
      puVar2 = (undefined4 *)bcm__6008b570(param_3);
      puVar3 = (undefined4 *)bcm__6008b570(param_3);
      if (((puVar3 == (undefined4 *)0x0) || (iVar4 = FUN_600e72fc(puVar2,param_1), iVar4 == 0)) ||
         (iVar1 = FUN_600e72fc(puVar3,param_2), iVar4 = DAT_6008c724, iVar1 == 0)) {
LAB_6008c718:
        iVar1 = -2;
      }
      else {
        iVar1 = 1;
        while( true ) {
          puVar9 = puVar2;
          iVar5 = FUN_600e75c2(puVar9);
          uVar8 = 0;
          if (iVar5 != 0) break;
          while (iVar5 = FUN_600e9dea(puVar9,uVar8), iVar5 == 0) {
            uVar8 = uVar8 + 1;
          }
          iVar5 = bcm__6008bb90(puVar9,puVar9,uVar8);
          if (iVar5 == 0) goto LAB_6008c718;
          if ((uVar8 & 1) != 0) {
            if (puVar3[1] == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = *(uint *)*puVar3 & 7;
            }
            iVar1 = *(int *)(iVar4 + uVar8 * 4) * iVar1;
          }
          if (puVar9[3] == 0) {
            uVar8 = 0;
            if (puVar9[1] != 0) {
              uVar8 = *(uint *)*puVar9;
            }
          }
          else if (puVar9[1] == 0) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = ~*(uint *)*puVar9;
          }
          uVar7 = 0;
          if (puVar3[1] != 0) {
            uVar7 = *(uint *)*puVar3;
          }
          if ((uVar8 & 2 & uVar7) != 0) {
            iVar1 = -iVar1;
          }
          iVar5 = FUN_6008bf00(puVar3,puVar3,puVar9,param_3);
          if (iVar5 == 0) goto LAB_6008c718;
          puVar9[3] = 0;
          puVar2 = puVar3;
          puVar3 = puVar9;
        }
        iVar4 = FUN_600e76ee(puVar3);
        if (iVar4 == 0) {
          iVar1 = 0;
        }
      }
      FUN_600e77c0(param_3);
      return iVar1;
    }
    uVar6 = 0x6d;
    uVar10 = 0x4f;
  }
  FUN_600e0552(3,0,uVar6,DAT_6008c720,uVar10,iVar4);
  return -2;
}


