// 6008e264  bcm__6008e264  size=1160 bytes
// src: bcm.c
// --- callers ---
//   6008e700 bcm__6008e700
// --- callees ---
//   600e6a22 FUN_600e6a22
//   600e76ee FUN_600e76ee
//   6008c0d8 bcm__6008c0d8
//   6008b570 bcm__6008b570
//   600e0552 FUN_600e0552
//   600e7554 FUN_600e7554
//   600e98a4 FUN_600e98a4
//   600e9ba8 FUN_600e9ba8
//   6008bb90 bcm__6008bb90
//   6008c5fc bcm__6008c5fc
//   6008e164 bcm__6008e164
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   600e9a16 FUN_600e9a16
//   600e7ce0 FUN_600e7ce0
//   6008bf00 FUN_6008bf00
//   600e7668 FUN_600e7668
//   600e7e8a FUN_600e7e8a
//   6008b384 bcm__6008b384
//   600e7718 FUN_600e7718
//   600e7450 FUN_600e7450
//   600e7d36 FUN_600e7d36
//   600e7706 FUN_600e7706
//   600e7372 FUN_600e7372
//   600e75c2 FUN_600e75c2
//   600e7382 FUN_600e7382
//   600e723a FUN_600e723a
//   600e75de FUN_600e75de
//   600e9dea FUN_600e9dea
//   600e984a FUN_600e984a
//   600e7548 FUN_600e7548
//   600e7598 FUN_600e7598


/* src: bcm.c */

int bcm__6008e264(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 extraout_r2;
  code *pcVar10;
  undefined *puVar11;
  int iVar12;
  undefined8 uVar13;
  int local_2c;
  
  iVar1 = FUN_600e7706(param_3);
  iVar2 = param_1;
  if ((iVar1 == 0) || (iVar1 = FUN_600e7598(extraout_r2,1), iVar1 != 0)) {
    iVar1 = FUN_600e7598(param_3,2);
    if (iVar1 == 0) {
      FUN_600e0552(3,0,0x72,PTR_s_bcm_c_6008e588,0x5a);
      return 0;
    }
    if ((param_1 != 0) || (iVar2 = bcm__6008b384(), iVar2 != 0)) {
      uVar3 = FUN_600e9ba8(*param_2,param_2[1],0);
LAB_6008e2a8:
      iVar1 = FUN_600e7372(iVar2,uVar3);
      if (iVar1 != 0) {
        return iVar2;
      }
      if (param_1 != iVar2) {
        FUN_600e6a22(iVar2);
      }
      return 0;
    }
  }
  else {
    iVar1 = FUN_600e75c2(param_2);
    if ((iVar1 == 0) && (iVar1 = FUN_600e76ee(param_2), iVar1 == 0)) {
      FUN_600e7718(param_4);
      uVar3 = bcm__6008b570(param_4);
      uVar4 = bcm__6008b570(param_4);
      iVar2 = bcm__6008b570(param_4);
      uVar5 = bcm__6008b570(param_4);
      uVar6 = bcm__6008b570(param_4);
      iVar1 = bcm__6008b570(param_4);
      if ((iVar1 != 0) &&
         ((iVar12 = param_1, param_1 != 0 || (iVar12 = bcm__6008b384(), iVar12 != 0)))) {
        iVar7 = FUN_6008bf00(uVar3,param_2,param_3,param_4);
        if (iVar7 != 0) {
          iVar7 = 1;
          while (iVar8 = FUN_600e9dea(param_3,iVar7), iVar8 == 0) {
            iVar7 = iVar7 + 1;
          }
          if (iVar7 == 1) {
            iVar1 = bcm__6008bb90(iVar2,param_3,2);
            if (iVar1 != 0) {
              *(undefined4 *)(iVar2 + 0xc) = 0;
              iVar1 = FUN_600e7668(iVar2,1);
              if (iVar1 != 0) {
                iVar2 = bcm__6008c0d8(iVar12,uVar3,iVar2,param_3,param_4,0);
LAB_6008e3b8:
                if ((iVar2 != 0) && (iVar2 = FUN_600e98a4(uVar6,iVar12,param_3,param_4), iVar2 != 0)
                   ) {
                  iVar2 = FUN_600e7554(uVar6,uVar3);
                  if (iVar2 == 0) goto LAB_6008e5cc;
                  uVar3 = 0x6e;
                  uVar4 = 0x19b;
                  puVar11 = PTR_s_bcm_c_6008e588;
                  goto LAB_6008e4d4;
                }
              }
            }
          }
          else if (iVar7 == 2) {
            iVar7 = FUN_600e7e8a(uVar5,uVar3,param_3,param_4);
            if ((iVar7 != 0) && (iVar7 = bcm__6008bb90(iVar2,param_3,3), iVar7 != 0)) {
              *(undefined4 *)(iVar2 + 0xc) = 0;
              iVar2 = bcm__6008c0d8(uVar4,uVar5,iVar2,param_3,param_4,0);
              if ((iVar2 != 0) &&
                 ((((iVar2 = FUN_600e98a4(iVar1,uVar4,param_3,param_4), iVar2 != 0 &&
                    (iVar2 = FUN_600e984a(uVar5,uVar5,iVar1,param_3,param_4), iVar2 != 0)) &&
                   (iVar2 = FUN_600e75de(uVar5,1), iVar2 != 0)) &&
                  ((iVar2 = FUN_600e984a(uVar6,uVar3,uVar4,param_3,param_4), iVar2 != 0 &&
                   (iVar2 = FUN_600e984a(uVar6,uVar6,uVar5,param_3,param_4), iVar2 != 0)))))) {
LAB_6008e480:
                iVar2 = FUN_600e72fc(iVar12,uVar6);
                goto LAB_6008e3b8;
              }
            }
          }
          else {
            uVar13 = FUN_600e72fc(iVar2,param_3);
            uVar9 = (undefined4)((ulonglong)uVar13 >> 0x20);
            if ((int)uVar13 != 0) {
              *(undefined4 *)(iVar2 + 0xc) = 0;
              local_2c = 2;
              do {
                if (local_2c < 0x16) {
LAB_6008e4aa:
                  iVar8 = FUN_600e7372(iVar1,local_2c);
                  if (iVar8 == 0) goto LAB_6008e35e;
                }
                else {
                  uVar9 = FUN_600e7450(param_3,uVar9);
                  iVar8 = bcm__6008e164(iVar1,uVar9,0);
                  if (iVar8 == 0) goto LAB_6008e35e;
                  iVar8 = FUN_600e7548(iVar1,param_3);
                  if (-1 < iVar8) {
                    pcVar10 = (code *)PTR_FUN_600e7ce0_1_6008e590;
                    if (*(int *)(param_3 + 0xc) == 0) {
                      pcVar10 = (code *)PTR_FUN_600e7d36_1_6008e58c;
                    }
                    iVar8 = (*pcVar10)(iVar1,iVar1,param_3);
                    if (iVar8 == 0) goto LAB_6008e35e;
                  }
                  iVar8 = FUN_600e75c2(iVar1);
                  if (iVar8 != 0) goto LAB_6008e4aa;
                }
                iVar8 = bcm__6008c5fc(iVar1,iVar2,param_4);
                if (iVar8 < -1) goto LAB_6008e35e;
                puVar11 = PTR_s_bcm_c_6008e588;
                if (iVar8 == 0) {
                  uVar3 = 0x72;
                  uVar4 = 0x105;
                  goto LAB_6008e4d4;
                }
                if (iVar8 != 1) {
                  if (iVar8 == -1) {
                    iVar8 = bcm__6008bb90(iVar2,iVar2,iVar7);
                    if ((iVar8 == 0) ||
                       (iVar8 = bcm__6008c0d8(iVar1,iVar1,iVar2,param_3,param_4,0), iVar8 == 0))
                    goto LAB_6008e35e;
                    iVar8 = FUN_600e76ee(iVar1);
                    if (iVar8 != 0) {
                      uVar3 = 0x72;
                      uVar4 = 0x11e;
                      puVar11 = PTR_s_bcm_c_6008e588;
                      goto LAB_6008e4d4;
                    }
                    iVar2 = FUN_600e9a16(uVar5,iVar2);
                    if (iVar2 == 0) goto LAB_6008e35e;
                    iVar2 = FUN_600e75c2(uVar5);
                    if (iVar2 == 0) {
                      iVar2 = bcm__6008c0d8(uVar6,uVar3,uVar5,param_3,param_4,0);
                      if (iVar2 == 0) goto LAB_6008e35e;
                      iVar2 = FUN_600e75c2(uVar6);
                      if (iVar2 == 0) goto LAB_6008e5e0;
                    }
                    else {
                      iVar2 = FUN_6008bf00(uVar5,uVar3,param_3,param_4);
                      if (iVar2 == 0) goto LAB_6008e35e;
                      iVar2 = FUN_600e75c2(uVar5);
                      if (iVar2 == 0) {
                        iVar2 = FUN_600e7382(uVar6);
                        if (iVar2 == 0) goto LAB_6008e35e;
LAB_6008e5e0:
                        iVar2 = FUN_600e98a4(uVar4,uVar6,param_3,param_4);
                        if ((iVar2 == 0) ||
                           (iVar2 = FUN_600e984a(uVar4,uVar4,uVar3,param_3,param_4), iVar2 == 0))
                        goto LAB_6008e35e;
                        iVar2 = FUN_600e984a(uVar6,uVar6,uVar3,param_3,param_4);
                        goto LAB_6008e614;
                      }
                    }
                    *(undefined4 *)(iVar12 + 0xc) = 0;
                    *(undefined4 *)(iVar12 + 4) = 0;
                    goto LAB_6008e5cc;
                  }
                  break;
                }
                local_2c = local_2c + 1;
                uVar9 = 1;
              } while (local_2c != 0x52);
              uVar3 = 0x73;
              uVar4 = 0x10f;
LAB_6008e4d4:
              FUN_600e0552(3,0,uVar3,puVar11,uVar4);
            }
          }
        }
LAB_6008e35e:
        if (param_1 != iVar12) {
          FUN_600e723a(iVar12);
        }
      }
    }
    else if ((param_1 != 0) || (iVar2 = bcm__6008b384(), iVar2 != 0)) {
      uVar3 = FUN_600e76ee(param_2);
      goto LAB_6008e2a8;
    }
  }
  iVar12 = 0;
LAB_6008e5cc:
  FUN_600e77c0(param_4);
  return iVar12;
LAB_6008e614:
  if (iVar2 == 0) goto LAB_6008e35e;
  iVar2 = FUN_600e76ee(uVar4);
  if (iVar2 != 0) goto LAB_6008e480;
  iVar2 = FUN_600e98a4(uVar5,uVar4,param_3,param_4);
  if (iVar2 == 0) goto LAB_6008e35e;
  iVar8 = 1;
  while (iVar2 = FUN_600e76ee(uVar5), iVar2 == 0) {
    iVar8 = iVar8 + 1;
    if (iVar7 == iVar8) {
      uVar3 = 0x6e;
      uVar4 = 0x177;
      puVar11 = DAT_6008e6fc;
      goto LAB_6008e4d4;
    }
    iVar2 = FUN_600e984a(uVar5,uVar5,uVar5,param_3,param_4);
    if (iVar2 == 0) goto LAB_6008e35e;
  }
  iVar2 = FUN_600e72fc(uVar5,iVar1);
  if (iVar2 == 0) goto LAB_6008e35e;
  iVar7 = iVar7 - iVar8;
  while (iVar7 = iVar7 + -1, 0 < iVar7) {
    iVar2 = FUN_600e98a4(uVar5,uVar5,param_3,param_4);
    if (iVar2 == 0) goto LAB_6008e35e;
  }
  iVar2 = FUN_600e984a(iVar1,uVar5,uVar5,param_3,param_4);
  if ((iVar2 == 0) || (iVar2 = FUN_600e984a(uVar6,uVar6,uVar5,param_3,param_4), iVar2 == 0))
  goto LAB_6008e35e;
  iVar2 = FUN_600e984a(uVar4,uVar4,iVar1,param_3,param_4);
  iVar7 = iVar8;
  goto LAB_6008e614;
}


