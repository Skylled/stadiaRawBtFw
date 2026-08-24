// 600edcd6  FUN_600edcd6  size=758 bytes
// --- callers ---
//   600834a4 parser__600834a4
// --- callees ---


uint FUN_600edcd6(uint *param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *in_r12;
  byte *pbVar12;
  bool bVar13;
  
  uVar3 = param_1[1];
LAB_600edce6:
  uVar6 = *param_1;
  if ((param_3 <= uVar6) || (uVar5 = (uint)*(byte *)(param_2 + uVar6), uVar5 == 0)) {
    if (param_4 != 0) {
      uVar6 = param_1[1];
      param_4 = param_4 + uVar6 * 0x10;
      while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
        if ((*(int *)(param_4 + -0xc) != -1) && (*(int *)(param_4 + -8) == -1)) {
          return 0xfffffffd;
        }
        param_4 = param_4 + -0x10;
      }
    }
    return uVar3;
  }
  if (uVar5 != 0x2c) {
    if (0x2c < uVar5) {
      if (uVar5 == 0x5d) {
LAB_600eddce:
        if (param_4 != 0) {
          uVar8 = param_1[1];
          if (uVar5 == 0x7d) {
            pbVar11 = (byte *)0x1;
          }
          else {
            pbVar11 = (byte *)0x2;
          }
          pbVar10 = (byte *)(param_4 + uVar8 * 0x10);
          do {
            pbVar12 = pbVar10;
            uVar8 = uVar8 - 1;
            if ((int)uVar8 < 0) {
              in_r12 = pbVar12;
              if (uVar8 == 0xffffffff) {
                return 0xfffffffe;
              }
              goto LAB_600eddbe;
            }
            pbVar10 = pbVar12 + -0x10;
          } while ((*(int *)(pbVar12 + -0xc) == -1) || (*(int *)(pbVar12 + -8) != -1));
          in_r12 = (byte *)(uint)*pbVar10;
          if (in_r12 != pbVar11) {
            return 0xfffffffe;
          }
          param_1[2] = 0xffffffff;
          *(uint *)(pbVar12 + -8) = uVar6 + 1;
          iVar7 = param_4 + uVar8 * 0x10;
          do {
            if ((*(int *)(iVar7 + 4) != -1) && (*(int *)(iVar7 + 8) == -1)) goto LAB_600ede28;
            uVar8 = uVar8 - 1;
            iVar7 = iVar7 + -0x10;
          } while (uVar8 != 0xffffffff);
        }
      }
      else {
        if (uVar5 < 0x5e) {
          if (uVar5 == 0x3a) {
            param_1[2] = param_1[1] - 1;
            goto LAB_600eddbe;
          }
          if (uVar5 != 0x5b) goto LAB_600edd1e;
        }
        else if (uVar5 != 0x7b) {
          if (uVar5 != 0x7d) goto LAB_600edd1e;
          goto LAB_600eddce;
        }
        uVar3 = uVar3 + 1;
        if (param_4 != 0) {
          uVar8 = param_1[1];
          if (param_5 <= uVar8) {
            return 0xffffffff;
          }
          param_1[1] = uVar8 + 1;
          iVar7 = param_4 + uVar8 * 0x10;
          uVar9 = param_1[2];
          *(undefined4 *)(iVar7 + 0xc) = 0;
          bVar13 = uVar9 != 0xffffffff;
          if (bVar13) {
            in_r12 = (byte *)(param_4 + uVar9 * 0x10);
            uVar9 = *(int *)(in_r12 + 0xc) + 1;
          }
          *(undefined4 *)(iVar7 + 4) = 0xffffffff;
          *(undefined4 *)(iVar7 + 8) = 0xffffffff;
          if (bVar13) {
            *(uint *)(in_r12 + 0xc) = uVar9;
          }
          if (uVar5 == 0x7b) {
            uVar4 = 1;
          }
          else {
            uVar4 = 2;
          }
          *(undefined1 *)(param_4 + uVar8 * 0x10) = uVar4;
          *(uint *)(iVar7 + 4) = uVar6;
          param_1[2] = uVar8;
        }
      }
      goto LAB_600eddbe;
    }
    if (uVar5 == 0xd) goto LAB_600eddbe;
    if (uVar5 < 0xe) {
      if (1 < uVar5 - 9) {
LAB_600edd1e:
        do {
          uVar5 = *param_1;
          if (((param_3 <= uVar5) || (uVar8 = (uint)*(byte *)(param_2 + uVar5), uVar8 == 0)) ||
             (uVar8 == 0x20)) goto LAB_600edd2e;
          if (uVar8 < 0x21) {
            if (8 < uVar8) {
              if (10 < uVar8) {
                bVar13 = uVar8 == 0xd;
                goto LAB_600edf66;
              }
              goto LAB_600edd2e;
            }
          }
          else {
            if (uVar8 == 0x3a) goto LAB_600edd2e;
            if (uVar8 < 0x3b) {
              bVar13 = uVar8 == 0x2c;
            }
            else {
              if (uVar8 == 0x5d) goto LAB_600edd2e;
              bVar13 = uVar8 == 0x7d;
            }
LAB_600edf66:
            if (bVar13) goto LAB_600edd2e;
          }
          if (0x5e < uVar8 - 0x20) goto LAB_600edeea;
          *param_1 = uVar5 + 1;
        } while( true );
      }
      goto LAB_600eddbe;
    }
    if (uVar5 == 0x20) goto LAB_600eddbe;
    if (uVar5 != 0x22) goto LAB_600edd1e;
    in_r12 = (byte *)(uVar6 + 1);
    *param_1 = (uint)in_r12;
    while( true ) {
      uVar5 = *param_1;
      if ((param_3 <= uVar5) || (cVar1 = *(char *)(param_2 + uVar5), cVar1 == '\0')) {
        *param_1 = uVar6;
        return 0xfffffffd;
      }
      if (cVar1 == '\"') break;
      if ((cVar1 == '\\') && (uVar8 = uVar5 + 1, uVar8 < param_3)) {
        *param_1 = uVar8;
        bVar2 = *(byte *)(param_2 + uVar8);
        if (bVar2 != 0x66) {
          if (bVar2 < 0x67) {
            if (bVar2 != 0x2f) {
              if (bVar2 < 0x30) {
                bVar13 = bVar2 == 0x22;
              }
              else {
                if (bVar2 == 0x5c) goto LAB_600edea0;
                bVar13 = bVar2 == 0x62;
              }
LAB_600ede9e:
              if (!bVar13) goto LAB_600edeea;
            }
          }
          else if (bVar2 != 0x72) {
            if (bVar2 < 0x73) {
              bVar13 = bVar2 == 0x6e;
              goto LAB_600ede9e;
            }
            if (bVar2 != 0x74) {
              if (bVar2 != 0x75) {
LAB_600edeea:
                *param_1 = uVar6;
                return 0xfffffffe;
              }
              iVar7 = 4;
              *param_1 = uVar5 + 2;
              do {
                uVar5 = *param_1;
                if ((param_3 <= uVar5) || (uVar8 = (uint)*(byte *)(param_2 + uVar5), uVar8 == 0))
                break;
                if ((9 < uVar8 - 0x30) && (5 < (uVar8 & 0xffffffdf) - 0x41)) goto LAB_600edeea;
                iVar7 = iVar7 + -1;
                *param_1 = uVar5 + 1;
              } while (iVar7 != 0);
              *param_1 = *param_1 - 1;
            }
          }
        }
      }
LAB_600edea0:
      *param_1 = *param_1 + 1;
    }
    if (param_4 != 0) {
      uVar8 = param_1[1];
      if (param_5 <= uVar8) goto LAB_600ede4a;
      param_1[1] = uVar8 + 1;
      iVar7 = param_4 + uVar8 * 0x10;
      *(undefined1 *)(param_4 + uVar8 * 0x10) = 3;
      *(undefined4 *)(iVar7 + 0xc) = 0;
      *(byte **)(iVar7 + 4) = in_r12;
      *(uint *)(iVar7 + 8) = uVar5;
    }
    goto LAB_600ede68;
  }
  if (((param_4 != 0) && (param_1[2] != 0xffffffff)) &&
     (1 < *(byte *)(param_4 + param_1[2] * 0x10) - 1)) {
    uVar8 = param_1[1];
    iVar7 = param_4 + uVar8 * 0x10;
    while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {
      if (((*(byte *)(iVar7 + -0x10) - 1 < 2) && (*(int *)(iVar7 + -0xc) != -1)) &&
         (*(int *)(iVar7 + -8) == -1)) goto LAB_600ede28;
      iVar7 = iVar7 + -0x10;
    }
  }
  goto LAB_600eddbe;
LAB_600edd2e:
  if (param_4 != 0) {
    uVar8 = param_1[1];
    if (param_5 <= uVar8) {
LAB_600ede4a:
      *param_1 = uVar6;
      return 0xffffffff;
    }
    param_1[1] = uVar8 + 1;
    in_r12 = (byte *)(param_4 + uVar8 * 0x10);
    *(undefined1 *)(param_4 + uVar8 * 0x10) = 4;
    in_r12[0xc] = 0;
    in_r12[0xd] = 0;
    in_r12[0xe] = 0;
    in_r12[0xf] = 0;
    *(uint *)(in_r12 + 4) = uVar6;
    *(uint *)(in_r12 + 8) = uVar5;
  }
  *param_1 = uVar5 - 1;
LAB_600ede68:
  uVar3 = uVar3 + 1;
  if ((param_1[2] != 0xffffffff) && (param_4 != 0)) {
    iVar7 = param_4 + param_1[2] * 0x10;
    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
  }
LAB_600eddbe:
  *param_1 = *param_1 + 1;
  goto LAB_600edce6;
LAB_600ede28:
  param_1[2] = uVar8;
  goto LAB_600eddbe;
}


