// 6008bbdc  bcm__6008bbdc  size=800 bytes
// src: bcm.c
// --- callers ---
//   6008bf00 FUN_6008bf00
//   600e9a8e FUN_600e9a8e
//   600e98a4 FUN_600e98a4
// --- callees ---
//   600e77c0 FUN_600e77c0
//   6008b43c bcm__6008b43c
//   600e7a32 FUN_600e7a32
//   6008b570 bcm__6008b570
//   6004c814 FUN_6004c814
//   600e0552 FUN_600e0552
//   6008bae0 bcm__6008bae0
//   600e7480 FUN_600e7480
//   6008bb90 bcm__6008bb90
//   600e7c2c FUN_600e7c2c
//   600e7718 FUN_600e7718
//   600e7434 FUN_600e7434
//   600e75c2 FUN_600e75c2
//   600e7450 FUN_600e7450
//   600e78a2 FUN_600e78a2


/* src: bcm.c */

undefined4 bcm__6008bbdc(int *param_1,int param_2,int *param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  undefined4 uVar20;
  undefined8 local_70;
  uint *local_58;
  int local_4c;
  
  iVar1 = FUN_600e7434(param_3);
  iVar2 = FUN_600e7434(param_4);
  if (((iVar1 < 1) || (*(int *)(*param_3 + (iVar1 + 0x3fffffff) * 4) != 0)) &&
     ((iVar2 < 1 || (*(int *)(*param_4 + (iVar2 + 0x3fffffff) * 4) != 0)))) {
    iVar1 = FUN_600e75c2(param_4);
    if (iVar1 == 0) {
      FUN_600e7718(param_5);
      piVar3 = (int *)bcm__6008b570(param_5);
      piVar4 = (int *)bcm__6008b570(param_5);
      piVar5 = (int *)bcm__6008b570(param_5);
      piVar9 = piVar5;
      if (((param_1 != (int *)0x0) ||
          (param_1 = (int *)bcm__6008b570(param_5), piVar9 = param_1, piVar5 != (int *)0x0)) &&
         (piVar9 != (int *)0x0)) {
        uVar6 = FUN_600e7450(param_4);
        iVar1 = bcm__6008bae0(piVar5,param_4,-(uVar6 & 0x1f) + 0x20);
        if (iVar1 != 0) {
          FUN_600e7480(piVar5);
          iVar2 = -(uVar6 & 0x1f) + 0x40;
          piVar5[3] = 0;
          iVar1 = bcm__6008bae0(piVar4,param_3,iVar2);
          if (iVar1 != 0) {
            FUN_600e7480(piVar4);
            iVar1 = piVar5[1];
            piVar4[3] = 0;
            if (iVar1 + 1 < piVar4[1]) {
              iVar1 = bcm__6008b43c(piVar4,piVar4[1] + 1);
              if (iVar1 == 0) goto LAB_6008bef4;
              iVar1 = piVar4[1];
              *(undefined4 *)(*piVar4 + iVar1 * 4) = 0;
              iVar1 = iVar1 + 1;
            }
            else {
              iVar1 = bcm__6008b43c(piVar4,iVar1 + 2);
              if (iVar1 == 0) goto LAB_6008bef4;
              iVar12 = piVar4[1];
              iVar1 = piVar5[1];
              iVar10 = iVar12 << 2;
              iVar18 = *piVar4;
              for (; iVar12 <= iVar1 + 1; iVar12 = iVar12 + 1) {
                *(undefined4 *)(iVar18 + iVar10) = 0;
                iVar10 = iVar10 + 4;
              }
              iVar1 = iVar1 + 2;
            }
            piVar4[1] = iVar1;
            iVar1 = piVar5[1];
            iVar18 = piVar4[1];
            iVar12 = iVar18 - iVar1;
            iVar10 = *piVar4;
            uVar6 = *(uint *)(*piVar5 + (iVar1 + 0x3fffffff) * 4);
            iVar17 = (iVar1 + 0x3fffffff) * 4;
            if (iVar1 == 1) {
              uVar13 = 0;
            }
            else {
              uVar13 = *(uint *)(*piVar5 + iVar17 + -4);
            }
            param_1[3] = param_3[3] ^ param_4[3];
            iVar7 = bcm__6008b43c(param_1,iVar12 + 1);
            if (iVar7 != 0) {
              iVar14 = *param_1;
              param_1[1] = iVar12 + -1;
              iVar7 = bcm__6008b43c(piVar3,iVar1 + 1);
              if (iVar7 != 0) {
                iVar7 = (iVar12 + 0x3fffffff) * 4;
                local_58 = (uint *)(iVar14 + iVar7);
                if (param_1[1] == 0) {
                  param_1[3] = 0;
                }
                else {
                  local_58 = local_58 + -1;
                }
                iVar7 = iVar10 + iVar7 + 4;
                puVar15 = (uint *)(iVar10 + (iVar18 + 0x3fffffff) * 4);
                for (local_4c = 0; local_4c < iVar12 + -1; local_4c = local_4c + 1) {
                  if (uVar6 == *puVar15) {
                    uVar8 = 0xffffffff;
                  }
                  else {
                    uVar16 = puVar15[-1];
                    uVar8 = FUN_6004c814(uVar16,*puVar15,uVar6);
                    uVar16 = uVar16 - uVar6 * uVar8;
                    local_70 = (ulonglong)uVar8 * (ulonglong)uVar13;
                    while( true ) {
                      bVar19 = local_70._4_4_ <= uVar16;
                      if (uVar16 == local_70._4_4_) {
                        bVar19 = (uint)local_70 <= puVar15[-2];
                      }
                      if (bVar19) break;
                      uVar8 = uVar8 - 1;
                      bVar19 = CARRY4(uVar6,uVar16);
                      uVar16 = uVar6 + uVar16;
                      if (bVar19) break;
                      local_70 = CONCAT44(local_70._4_4_ - ((uint)local_70 < uVar13),
                                          (uint)local_70 - uVar13);
                    }
                  }
                  iVar7 = iVar7 + -4;
                  uVar11 = FUN_600e78a2(*piVar3,*piVar5,iVar1,uVar8);
                  iVar10 = *piVar3;
                  *(undefined4 *)(iVar10 + iVar17 + 4) = uVar11;
                  iVar10 = FUN_600e7c2c(iVar7,iVar7,iVar10,iVar1 + 1);
                  if (iVar10 != 0) {
                    uVar8 = uVar8 - 1;
                    iVar10 = FUN_600e7a32(iVar7,iVar7,*piVar5,iVar1);
                    if (iVar10 != 0) {
                      *puVar15 = *puVar15 + 1;
                    }
                  }
                  puVar15 = puVar15 + -1;
                  *local_58 = uVar8;
                  local_58 = local_58 + -1;
                }
                FUN_600e7480(piVar4);
                if (param_2 != 0) {
                  iVar10 = param_3[3];
                  iVar1 = bcm__6008bb90(param_2,piVar4,iVar2);
                  if (iVar1 == 0) goto LAB_6008bef4;
                  iVar1 = FUN_600e75c2(param_2);
                  if (iVar1 == 0) {
                    *(int *)(param_2 + 0xc) = iVar10;
                  }
                }
                FUN_600e7480(param_1);
                FUN_600e77c0(param_5);
                return 1;
              }
            }
          }
        }
      }
LAB_6008bef4:
      FUN_600e77c0(param_5);
      return 0;
    }
    uVar11 = 0x69;
    uVar20 = 0xda;
  }
  else {
    uVar11 = 0x6f;
    uVar20 = 0xd5;
  }
  FUN_600e0552(3,0,uVar11,DAT_6008befc,uVar20);
  return 0;
}


