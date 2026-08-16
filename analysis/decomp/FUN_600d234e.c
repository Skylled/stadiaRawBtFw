// 600d234e  FUN_600d234e  size=672 bytes
// --- callers ---
// --- callees ---
//   60055704 FUN_60055704
//   600d15c4 private_heap__600835ac
//   600d22c8 FUN_600d22c8


bool FUN_600d234e(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  byte *pbVar10;
  code *pcVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined1 *puVar16;
  
  puVar6 = *(undefined4 **)(param_1 + 4);
  switch(*(undefined1 *)(param_1 + 0x438)) {
  case 2:
    *(ushort *)(*(int *)(param_1 + 0x418) + 0xc) = (ushort)*(byte *)(*(int *)(param_1 + 0x414) + 7);
    pcVar11 = *(code **)(puVar6[0xb4] + 0x18);
    uVar2 = 5;
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x43d) = *(undefined1 *)(param_1 + 0x43c);
    pcVar11 = *(code **)(puVar6[0xb4] + 0x18);
    uVar2 = 4;
    break;
  default:
    goto LAB_600d23d8;
  case 5:
    *(undefined2 *)(param_1 + 0x420) = *(undefined2 *)(*(int *)(param_1 + 0x434) + 2);
    if (*(int *)(param_1 + 0x41c) != 0) {
      private_heap__600835ac();
      *(undefined4 *)(param_1 + 0x41c) = 0;
    }
    uVar13 = (uint)*(ushort *)(param_1 + 0x420);
    if ((*(ushort *)(param_1 + 0x420) & 3) != 0) {
      uVar13 = (uVar13 & 0xfffffffc) + 4;
    }
    uVar2 = FUN_60055704(uVar13);
    *(undefined4 *)(param_1 + 0x41c) = uVar2;
    return *(int *)(param_1 + 0x41c) == 0;
  case 6:
    if (0xfa < *(byte *)(*(int *)(param_1 + 0x41c) + 8)) {
      return true;
    }
    *(short *)(param_1 + 0x422) = *(short *)(param_1 + 0x422) + 1;
    puVar7 = (undefined1 *)(param_1 + 7);
    do {
      puVar7 = puVar7 + 1;
      *puVar7 = 0;
    } while ((undefined1 *)(param_1 + 0x413) != puVar7);
    puVar16 = (undefined1 *)(param_1 + 0x424);
    puVar7 = puVar16;
    do {
      puVar8 = puVar7 + 1;
      *puVar7 = 0;
      puVar7 = puVar8;
    } while ((undefined1 *)(param_1 + 0x434) != puVar8);
    pcVar9 = *(char **)(param_1 + 0x41c);
    if ((*pcVar9 == '\t') && (pcVar9[1] == '\x02')) {
      *(char **)(param_1 + 0x408) = pcVar9;
      pbVar12 = (byte *)(pcVar9 + *(ushort *)(param_1 + 0x420));
      *(undefined2 *)(param_1 + 0x410) = 0;
      *(undefined4 *)(param_1 + 0x40c) = 0;
      *(undefined1 *)(param_1 + 0x412) = 0;
      for (pbVar10 = (byte *)(pcVar9 + 9); pbVar10 < pbVar12; pbVar10 = pbVar10 + bVar1) {
        bVar1 = pbVar10[1];
        if (bVar1 == 4) {
          iVar4 = 0;
          while (pbVar10 < pbVar12) {
            if (pbVar10[1] != 4) {
              return true;
            }
            if (pbVar10[3] == 0) {
              uVar13 = (uint)*(byte *)(param_1 + 0x412);
              if (0xf < uVar13) {
                return true;
              }
              iVar3 = uVar13 * 0x40 + param_1;
              *(byte *)(param_1 + 0x412) = *(byte *)(param_1 + 0x412) + 1;
              *(undefined1 *)(iVar3 + 0x43) = 0;
              iVar4 = uVar13 * 0x40 + 8 + param_1;
              *(undefined1 *)(iVar3 + 0x44) = 0;
              *(undefined2 *)(iVar3 + 0x40) = 0;
              *(undefined4 *)(iVar3 + 0x3c) = 0;
              bVar1 = pbVar10[2];
              *(byte **)(iVar3 + 0x38) = pbVar10;
              *(byte *)(iVar3 + 0x42) = bVar1;
              if (*pbVar10 == 0) {
                return true;
              }
              pbVar10 = pbVar10 + *pbVar10;
              while ((pbVar10 < pbVar12 && (bVar1 = pbVar10[1], 1 < bVar1 - 4))) {
                if (*(int *)(iVar3 + 0x3c) == 0) {
                  *(byte **)(iVar3 + 0x3c) = pbVar10;
                }
                if (bVar1 == 0) {
                  return true;
                }
                bVar1 = *pbVar10;
                if (bVar1 == 0) {
                  return true;
                }
                pbVar10 = pbVar10 + bVar1;
                *(ushort *)(iVar3 + 0x40) = *(short *)(iVar3 + 0x40) + (ushort)bVar1;
              }
              iVar15 = param_1 + uVar13 * 0x40;
              bVar1 = *(byte *)(*(int *)(iVar15 + 0x38) + 4);
              if (bVar1 != 0) {
                if (pbVar10[1] != 5) {
                  return true;
                }
                if (4 < bVar1) {
                  return true;
                }
                while ((uint)*(byte *)(iVar3 + 0x44) < (uint)*(byte *)(*(int *)(iVar15 + 0x38) + 4))
                {
                  if (pbVar12 <= pbVar10) {
                    return true;
                  }
                  if (pbVar10[1] != 5) {
                    return true;
                  }
                  uVar14 = (uint)*pbVar10;
                  iVar5 = (uint)*(byte *)(iVar3 + 0x44) * 0xc + uVar13 * 0x40 + param_1;
                  *(byte **)(iVar5 + 8) = pbVar10;
                  *(undefined2 *)(iVar5 + 0x10) = 0;
                  *(undefined4 *)(iVar5 + 0xc) = 0;
                  if (uVar14 == 0) {
                    return true;
                  }
                  while ((pbVar10 = pbVar10 + uVar14, pbVar10 < pbVar12 &&
                         (bVar1 = pbVar10[1], 1 < bVar1 - 4))) {
                    if (*(int *)(iVar5 + 0xc) == 0) {
                      *(byte **)(iVar5 + 0xc) = pbVar10;
                    }
                    if (bVar1 == 0) {
                      return true;
                    }
                    uVar14 = (uint)*pbVar10;
                    if (uVar14 == 0) {
                      return true;
                    }
                    *(ushort *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + (ushort)*pbVar10;
                  }
                  *(char *)(iVar3 + 0x44) = *(char *)(iVar3 + 0x44) + '\x01';
                }
              }
            }
            else {
              if (iVar4 == 0) {
                return true;
              }
              *(char *)(iVar4 + 0x3b) = *(char *)(iVar4 + 0x3b) + '\x01';
              if (*(int *)(iVar4 + 0x34) == 0) {
                *(byte **)(iVar4 + 0x34) = pbVar10;
              }
              while( true ) {
                bVar1 = *pbVar10;
                if (bVar1 == 0) {
                  return true;
                }
                pbVar10 = pbVar10 + bVar1;
                *(ushort *)(iVar4 + 0x38) = *(short *)(iVar4 + 0x38) + (ushort)bVar1;
                if ((pbVar12 <= pbVar10) || (pbVar10[1] == 4)) break;
                if (pbVar10[1] == 0) {
                  return true;
                }
              }
            }
          }
          break;
        }
        if (*(int *)(param_1 + 0x40c) == 0) {
          *(byte **)(param_1 + 0x40c) = pbVar10;
        }
        if (bVar1 == 0) {
          return true;
        }
        bVar1 = *pbVar10;
        if (bVar1 == 0) {
          return true;
        }
        *(ushort *)(param_1 + 0x410) = *(short *)(param_1 + 0x410) + (ushort)bVar1;
      }
    }
    puVar7 = puVar16 + *(byte *)(param_1 + 0x412);
    for (; puVar16 != puVar7; puVar16 = puVar16 + 1) {
      *puVar16 = 1;
    }
    iVar4 = FUN_600d22c8(param_1,1);
    if (iVar4 != 0) {
      if (*(ushort *)(param_1 + 0x422) < (ushort)*(byte *)(*(int *)(param_1 + 0x414) + 0x11)) {
        return (bool)9;
      }
      FUN_600d22c8(param_1,4);
      return (bool)8;
    }
    return false;
  }
  (*pcVar11)(*puVar6,uVar2);
LAB_600d23d8:
  return false;
}


