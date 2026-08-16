// 600d2bb0  FUN_600d2bb0  size=480 bytes
// --- callers ---
// --- callees ---
//   600d2a8e FUN_600d2a8e
//   600d2762 FUN_600d2762
//   600d33b2 FUN_600d33b2
//   600d2b0e FUN_600d2b0e


void FUN_600d2bb0(int param_1)

{
  uint uVar1;
  short *psVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  code *pcVar10;
  undefined4 *puVar11;
  int iVar12;
  int *piVar13;
  bool bVar14;
  int local_2c [2];
  
  piVar13 = *(int **)(param_1 + 0x38);
  do {
    if (piVar13 == (int *)0x0) {
      return;
    }
    switch(*(undefined1 *)(piVar13 + 5)) {
    case 0:
    case 2:
    case 3:
      iVar12 = piVar13[6];
      puVar11 = *(undefined4 **)(iVar12 + 0x34);
      while (puVar11 != (undefined4 *)0x0) {
        puVar7 = (undefined4 *)*puVar11;
        iVar4 = puVar11[10];
        if ((*(int *)(iVar4 + 8) << 0x10 < 0) && ((*(uint *)(iVar4 + 8) & 0x80) == 0)) {
          uVar8 = *(uint *)(iVar4 + 8);
          uVar1 = FUN_600d2762(param_1,puVar11[9]);
          iVar4 = 0;
          if (uVar1 <= (uint)puVar11[2]) {
            iVar4 = puVar11[2] - uVar1;
          }
          puVar11[3] = iVar4;
          *(undefined4 *)(iVar12 + 0x34) = *puVar11;
          *(undefined2 *)(iVar12 + 0x3e) = 0;
          *(undefined2 *)(iVar12 + 0x3c) = 0x14;
          if ((uVar8 & 0x7e) == 0) {
            if (((*(char *)(piVar13 + 5) == '\0') &&
                (psVar2 = (short *)puVar11[7], *psVar2 == 0x102)) && ((char)psVar2[1] == '\0')) {
              for (piVar9 = *(int **)(param_1 + 0x38); piVar9 != (int *)0x0; piVar9 = (int *)*piVar9
                  ) {
                if ((((uint)*(byte *)((int)piVar9 + 0x12) | (uint)*(byte *)((int)piVar9 + 0x13) << 7
                     ) == (uint)*(byte *)(psVar2 + 2)) && (piVar9[1] == piVar13[1])) {
                  if (*(byte *)(piVar9 + 5) - 2 < 2) {
                    *(uint *)(piVar9[6] + 0x18) = *(uint *)(piVar9[6] + 0x18) & 0x7fffffff;
                  }
                  break;
                }
              }
            }
            pcVar10 = (code *)puVar11[4];
            uVar6 = 0;
            uVar5 = puVar11[5];
LAB_600d2c6e:
            (*pcVar10)(uVar5,puVar11,uVar6);
            puVar11 = puVar7;
          }
          else {
            if (-1 < *(int *)(iVar12 + 0x18) << 0x18) {
              *(uint *)(iVar12 + 0x18) = *(uint *)(iVar12 + 0x18) & 0xffffff00;
            }
            if ((uVar8 & 0x3e) == 0) {
              uVar5 = 10;
            }
            else {
              uVar5 = 0xb;
            }
            (*(code *)puVar11[4])(puVar11[5],puVar11,uVar5);
            puVar11 = puVar7;
          }
        }
        else {
          if ((*(int *)(iVar12 + 0x18) << 0x18 < 0) || ((*(uint *)(iVar12 + 0x18) & 0x7e) == 0))
          break;
          uVar1 = *(uint *)(iVar12 + 0x18);
          puVar3 = *(uint **)(iVar12 + 0xc);
          if ((((uint)puVar3 & 1) == 0) && (puVar3 != (uint *)0x0)) {
            do {
              if ((int)(puVar3[2] << 0x10) < 0) break;
              puVar3 = (uint *)*puVar3;
            } while (puVar3 != (uint *)0x0);
            *(undefined4 *)(iVar12 + 0x10) = 1;
            *(undefined4 *)(iVar12 + 0xc) = 1;
            *(uint *)(iVar12 + 0x18) = *(uint *)(iVar12 + 0x18) & 0xffffff00;
            if (puVar3 != (uint *)0x0) {
              *(uint *)(iVar12 + 0x10) = *puVar3;
            }
            uVar8 = FUN_600d2762(param_1,puVar11[9]);
            uVar6 = puVar11[2];
            iVar4 = 0;
            if (uVar8 <= uVar6) {
              iVar4 = uVar6 - uVar8;
            }
            bVar14 = (uVar1 & 0x3e) != 0;
            puVar11[3] = iVar4;
            if (bVar14) {
              uVar6 = 0xb;
            }
            if (!bVar14) {
              uVar6 = 10;
            }
            *(undefined4 *)(iVar12 + 0x34) = *puVar11;
            *(undefined2 *)(iVar12 + 0x3e) = 0;
            *(undefined2 *)(iVar12 + 0x3c) = 0x14;
            pcVar10 = (code *)puVar11[4];
            uVar5 = puVar11[5];
            goto LAB_600d2c6e;
          }
          *(uint *)(iVar12 + 0x18) = *(uint *)(iVar12 + 0x18) & 0xffffff00;
          puVar11 = puVar7;
        }
      }
      break;
    case 1:
      iVar12 = piVar13[6];
      puVar11 = *(undefined4 **)(iVar12 + 8);
      while (puVar11 != (undefined4 *)0x0) {
        puVar7 = (undefined4 *)*puVar11;
        FUN_600d33b2(piVar13[1],4,local_2c);
        if (local_2c[0] == 2) {
          iVar4 = 0;
          do {
            if (*(int *)(puVar11[10] + iVar4 * 4 + 4) < 0) goto switchD_600d2bc8_default;
            iVar4 = iVar4 + 1;
          } while (iVar4 != 8);
          uVar5 = FUN_600d2b0e(param_1,puVar11[9]);
          puVar11[3] = uVar5;
          *(undefined4 *)(iVar12 + 8) = *puVar11;
          pcVar10 = (code *)puVar11[4];
        }
        else {
          if ((*(uint *)(puVar11[10] + 0xc) & 0x80) != 0) break;
          uVar5 = FUN_600d2a8e(param_1,puVar11[9]);
          puVar11[3] = uVar5;
          *(undefined4 *)(iVar12 + 8) = *puVar11;
          pcVar10 = (code *)puVar11[4];
        }
        (*pcVar10)(puVar11[5],puVar11,0);
        puVar11 = puVar7;
      }
    }
switchD_600d2bc8_default:
    piVar13 = (int *)*piVar13;
  } while( true );
}


