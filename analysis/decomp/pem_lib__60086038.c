// 60086038  pem_lib__60086038  size=376 bytes
// src: pem_lib.c
// --- callers ---
//   60086508 FUN_60086508
// --- callees ---
//   60085eb8 FUN_60085eb8
//   600e0552 FUN_600e0552
//   601024b4 FUN_601024b4
//   600e9ff4 FUN_600e9ff4
//   6013cf90 thunk_EXT_FUN_0000b5ba


/* src: pem_lib.c */

undefined4 pem_lib__60086038(char *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  byte *pbVar11;
  int *piVar12;
  uint uVar13;
  undefined4 uVar14;
  
  piVar12 = param_2 + 1;
  *param_2 = 0;
  thunk_EXT_FUN_0000b5ba(piVar12,0,0x10,param_4,param_1,param_2);
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) || (*param_1 == '\n')) {
    return 1;
  }
  iVar3 = FUN_601024b4(param_1,DAT_600861b0,0xb);
  if (iVar3 != 0) {
    uVar5 = 0x6d;
    uVar14 = 0x1aa;
LAB_60086080:
    FUN_600e0552(9,0,uVar5,DAT_600861b4,uVar14);
    return 0;
  }
  if (param_1[0xb] != '4') {
    return 0;
  }
  if (param_1[0xc] != ',') {
    return 0;
  }
  iVar3 = FUN_601024b4(param_1 + 0xd,DAT_600861b8,9);
  pcVar10 = param_1 + 0xd;
  if (iVar3 == 0) {
    do {
      cVar1 = *pcVar10;
      if (cVar1 == '\n') {
        iVar3 = FUN_601024b4(pcVar10 + 1,DAT_600861bc,10);
        if (iVar3 == 0) {
          pbVar7 = (byte *)(pcVar10 + 0xb);
          do {
            do {
              pbVar11 = pbVar7;
              pbVar7 = pbVar11 + 1;
              bVar2 = *pbVar11;
              uVar13 = (uint)bVar2;
            } while (uVar13 - 0x41 < 0x1a);
          } while ((uVar13 == 0x2d) || (uVar13 - 0x30 < 10));
          *pbVar11 = 0;
          iVar3 = FUN_60085eb8();
          *param_2 = iVar3;
          *pbVar11 = bVar2;
          if (iVar3 == 0) {
            uVar14 = 0x1d2;
          }
          else {
            uVar13 = FUN_600e9ff4();
            if (7 < uVar13) {
              iVar3 = FUN_600e9ff4(iVar3);
              for (piVar9 = piVar12; (int)piVar9 - (int)piVar12 < iVar3;
                  piVar9 = (int *)((int)piVar9 + 1)) {
                *(undefined1 *)piVar9 = 0;
              }
              pbVar7 = pbVar11;
              do {
                uVar13 = (int)pbVar7 - (int)pbVar11;
                if (iVar3 * 2 <= (int)uVar13) {
                  return 1;
                }
                pbVar7 = pbVar7 + 1;
                uVar6 = (uint)*pbVar7;
                uVar8 = uVar6 - 0x30;
                if (9 < (uVar8 & 0xff)) {
                  if (uVar6 - 0x41 < 6) {
                    uVar8 = uVar6 - 0x37;
                  }
                  else {
                    if (5 < uVar6 - 0x61) {
                      uVar5 = 0x67;
                      uVar14 = 499;
                      goto LAB_600860b0;
                    }
                    uVar8 = uVar6 - 0x57;
                  }
                }
                if ((uVar13 & 1) == 0) {
                  iVar4 = 4;
                }
                else {
                  iVar4 = 0;
                }
                *(byte *)((int)piVar12 + ((int)uVar13 >> 1)) =
                     (byte)(uVar8 << iVar4) | *(byte *)((int)piVar12 + ((int)uVar13 >> 1));
              } while( true );
            }
            uVar14 = 0x1d9;
          }
          uVar5 = 0x72;
          goto LAB_600860b0;
        }
        uVar5 = 0x6b;
        uVar14 = 0x1bf;
        goto LAB_60086080;
      }
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0x70;
    uVar14 = 0x1ba;
  }
  else {
    uVar5 = 0x6c;
    uVar14 = 0x1b5;
  }
LAB_600860b0:
  FUN_600e0552(9,0,uVar5,DAT_600861b4,uVar14);
  return 0;
}


