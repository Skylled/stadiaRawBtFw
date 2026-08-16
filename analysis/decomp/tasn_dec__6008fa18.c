// 6008fa18  tasn_dec__6008fa18  size=1410 bytes
// src: tasn_dec.c
// --- callers ---
//   6008ffc0 tasn_dec__6008ffc0
//   600ec756 FUN_600ec756
// --- callees ---
//   60090cbc tasn_utl__60090cbc
//   600e0552 FUN_600e0552
//   600ecbb6 FUN_600ecbb6
//   600e05bc FUN_600e05bc
//   600ecb4a tasn_new__600ecb4a
//   600eccd4 FUN_600eccd4
//   600ec740 FUN_600ec740
//   6008f370 tasn_dec__6008f370
//   600ecbbe FUN_600ecbbe
//   600eca02 FUN_600eca02
//   600901c8 tasn_dec__600901c8
//   600ecc40 FUN_600ecc40
//   600eca08 FUN_600eca08
//   6008f794 tasn_dec__6008f794


/* src: tasn_dec.c */

undefined4
tasn_dec__6008fa18(int *param_1,int *param_2,int param_3,undefined1 *param_4,uint param_5,
                  uint param_6,char param_7,undefined4 param_8,int param_9)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  code *pcVar12;
  undefined4 uVar13;
  int local_3c [2];
  char local_33;
  char local_32;
  char local_31;
  byte *local_30;
  uint local_2c [2];
  
  iVar9 = *(int *)(param_4 + 0x10);
  local_30 = (byte *)0x0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (iVar9 == 0) {
    pcVar12 = (code *)0x0;
  }
  else {
    pcVar12 = *(code **)(iVar9 + 0xc);
  }
  local_3c[0] = param_3;
  if (0x3fffffff < param_3) {
    local_3c[0] = 0x3fffffff;
  }
  iVar10 = local_3c[0];
  uVar5 = param_6 & 0x400;
  param_9 = param_9 + 1;
  uVar3 = DAT_6008fcf0;
  if (param_9 < 0x1f) {
    param_6 = param_6 & 0xfffffbff;
    switch(*param_4) {
    case 0:
      local_2c[0] = param_5;
      if (*(int *)(param_4 + 8) == 0) {
LAB_6008face:
        uVar3 = tasn_dec__6008f794(param_1,param_2,local_3c[0],param_4,local_2c[0],param_6,param_7,
                                   param_8);
        return uVar3;
      }
      if ((param_5 == 0xffffffff) && (param_7 == '\0')) {
        uVar3 = tasn_dec__600901c8(param_1,param_2,local_3c[0],*(int *)(param_4 + 8),0,param_8,
                                   param_9);
        return uVar3;
      }
      uVar4 = 0x88;
      uVar13 = 0xd7;
      break;
    case 1:
    case 6:
      local_30 = (byte *)*param_2;
      if (param_5 == 0xffffffff) {
        param_6 = 0;
        param_5 = 0x10;
      }
      iVar2 = tasn_dec__6008f370(local_3c,0,0,&local_32,&local_31,&local_30,local_3c[0],param_5,
                                 param_6,param_7,param_8);
      if (iVar2 == 0) {
        uVar13 = 0x183;
LAB_6008fb0e:
        uVar4 = 0x9e;
        uVar3 = DAT_6008fcf0;
      }
      else {
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        cVar11 = local_32;
        if ((iVar9 != 0) && (*(int *)(iVar9 + 4) << 0x1d < 0)) {
          local_3c[0] = iVar10 - ((int)local_30 - *param_2);
          cVar11 = '\x01';
        }
        if (local_31 == '\0') {
          uVar4 = 0xa9;
          uVar13 = 399;
          uVar3 = DAT_6008ffb4;
        }
        else {
          if ((*param_1 == 0) && (iVar9 = tasn_new__600ecb4a(param_1,param_4), iVar9 == 0)) {
            uVar13 = 0x194;
            goto LAB_6008fb0e;
          }
          if ((pcVar12 == (code *)0x0) || (iVar9 = (*pcVar12)(4,param_1,param_4,0), iVar9 != 0)) {
            puVar8 = *(uint **)(param_4 + 8);
            for (iVar9 = 0; iVar9 < *(int *)(param_4 + 0xc); iVar9 = iVar9 + 1) {
              if (((*puVar8 & 0x300) != 0) &&
                 (iVar10 = tasn_utl__60090cbc(param_1,puVar8,0), iVar10 != 0)) {
                uVar3 = FUN_600eccd4(param_1,iVar10);
                FUN_600eca08(uVar3,iVar10);
              }
              puVar8 = puVar8 + 5;
            }
            iVar10 = *(int *)(param_4 + 8);
            for (iVar9 = 0; iVar9 < *(int *)(param_4 + 0xc); iVar9 = iVar9 + 1) {
              puVar8 = (uint *)tasn_utl__60090cbc(param_1,iVar10,1);
              if (puVar8 == (uint *)0x0) goto LAB_6008fb1a;
              uVar3 = FUN_600eccd4(param_1,puVar8);
              pbVar7 = local_30;
              if (local_3c[0] == 0) break;
              if ((1 < local_3c[0]) && (iVar2 = FUN_600ec740(&local_30), iVar2 != 0)) {
                if (local_32 == '\0') {
                  uVar4 = 0xb4;
                  uVar13 = 0x1b6;
                  uVar3 = DAT_6008ffb4;
                  goto LAB_6008fb14;
                }
                local_3c[0] = local_3c[0] - ((int)local_30 - (int)pbVar7);
                local_32 = '\0';
                break;
              }
              if (*(int *)(param_4 + 0xc) + -1 == iVar9) {
                uVar6 = 0;
              }
              else {
                uVar6 = *puVar8 & 1;
              }
              iVar2 = tasn_dec__600901c8(uVar3,&local_30,local_3c[0],puVar8,uVar6,param_8,param_9);
              if (iVar2 == 0) goto LAB_6008ff80;
              if (iVar2 == -1) {
                FUN_600eca08(uVar3,puVar8);
              }
              else {
                local_3c[0] = local_3c[0] - ((int)local_30 - (int)pbVar7);
              }
              iVar10 = iVar10 + 0x14;
            }
            if ((local_32 == '\0') ||
               ((1 < local_3c[0] && (iVar2 = FUN_600ec740(&local_30), iVar2 != 0)))) {
              if ((cVar11 != '\0') || (local_3c[0] == 0)) {
LAB_6008ff54:
                if (iVar9 < *(int *)(param_4 + 0xc)) {
                  puVar8 = (uint *)tasn_utl__60090cbc(param_1,iVar10,1);
                  if (puVar8 != (uint *)0x0) {
                    if ((*puVar8 & 1) != 0) goto code_r0x6008ff3e;
                    FUN_600e0552(0xc,0,0x79,DAT_6008ffb4,0x1f7);
LAB_6008ff80:
                    if (uVar5 != 0) goto LAB_6008fd20;
                    goto LAB_6008fd12;
                  }
                  goto LAB_6008fb1a;
                }
                iVar9 = FUN_600ecc40(param_1,*param_2,(int)local_30 - *param_2,param_4);
                if (iVar9 != 0) goto LAB_6008fce0;
                goto LAB_6008fc44;
              }
              uVar4 = 0xa8;
              uVar13 = 0x1e3;
              uVar3 = DAT_6008ffb4;
            }
            else {
              uVar4 = 0x99;
              uVar13 = 0x1de;
              uVar3 = DAT_6008ffb4;
            }
          }
          else {
LAB_6008fc44:
            uVar4 = 0x65;
            uVar13 = 0x207;
            uVar3 = DAT_6008fcf0;
          }
        }
      }
      break;
    case 2:
      if ((pcVar12 != (code *)0x0) && (iVar9 = (*pcVar12)(4,param_1,param_4,0), iVar9 == 0))
      goto LAB_6008fc44;
      if (*param_1 == 0) {
        iVar9 = tasn_new__600ecb4a(param_1,param_4);
        if (iVar9 == 0) {
          uVar13 = 0x14c;
          goto LAB_6008fb0e;
        }
      }
      else {
        iVar9 = FUN_600ecbb6(param_1,param_4);
        if ((-1 < iVar9) && (iVar9 < *(int *)(param_4 + 0xc))) {
          iVar9 = iVar9 * 0x14 + *(int *)(param_4 + 8);
          uVar3 = FUN_600eccd4(param_1,iVar9);
          FUN_600eca08(uVar3,iVar9);
          FUN_600ecbbe(param_1,0xffffffff,param_4);
        }
      }
      local_30 = (byte *)*param_2;
      iVar9 = *(int *)(param_4 + 8);
      for (iVar10 = 0; puVar8 = (uint *)(iVar10 * 0x14 + iVar9), iVar10 < *(int *)(param_4 + 0xc);
          iVar10 = iVar10 + 1) {
        uVar3 = FUN_600eccd4(param_1,puVar8);
        iVar2 = tasn_dec__600901c8(uVar3,&local_30,local_3c[0],puVar8,1,param_8,param_9);
        if (iVar2 != -1) {
          if (iVar2 < 1) {
            FUN_600e0552(0xc,0,0x9e,DAT_6008ffb4,0x15f);
            if (uVar5 != 0) goto LAB_6008fd1a;
            goto LAB_6008fd12;
          }
          break;
        }
      }
      if (*(int *)(param_4 + 0xc) != iVar10) {
        FUN_600ecbbe(param_1,iVar10,param_4);
LAB_6008fce0:
        if ((pcVar12 == (code *)0x0) || (iVar9 = (*pcVar12)(5,param_1,param_4,0), iVar9 != 0)) {
          *param_2 = (int)local_30;
          return 1;
        }
        goto LAB_6008fc44;
      }
      if (param_7 != '\0') {
        FUN_600eca02(param_1,param_4);
        return 0xffffffff;
      }
      uVar4 = 0xa3;
      uVar13 = 0x16b;
      uVar3 = DAT_6008ffb4;
      break;
    case 3:
      if (param_7 == '\0') {
        if (param_5 == 0xffffffff) {
LAB_6008ffa6:
          iVar9 = (**(code **)(iVar9 + 8))(param_1,param_2,local_3c[0]);
          goto LAB_6008fc10;
        }
LAB_6008fbe8:
        uVar13 = 300;
      }
      else {
        local_30 = (byte *)*param_2;
        uVar6 = param_5;
        if (param_5 == 0xffffffff) {
          uVar6 = *(uint *)(param_4 + 4);
        }
        iVar10 = tasn_dec__6008f370(0,0,0,0,0,&local_30,local_3c[0],uVar6,param_6,1,param_8);
        if (iVar10 == 0) {
          uVar13 = 0x115;
          goto LAB_6008fb0e;
        }
        if (iVar10 == -1) {
          return 0xffffffff;
        }
        if (param_5 == 0xffffffff) goto LAB_6008ffa6;
        pbVar7 = (byte *)*param_2;
        bVar1 = *pbVar7;
        if (local_30 == (byte *)0x0) goto LAB_6008fbe8;
        *pbVar7 = *local_30 & 0x20 | (byte)*(undefined4 *)(param_4 + 4);
        iVar9 = (**(code **)(iVar9 + 8))(param_1,param_2,local_3c[0]);
        *pbVar7 = bVar1;
LAB_6008fc10:
        if (iVar9 != 0) {
          return 1;
        }
        uVar13 = 0x13b;
      }
      uVar4 = 0x9e;
      uVar3 = DAT_6008fcf0;
      break;
    case 4:
      uVar3 = (**(code **)(iVar9 + 0x10))
                        (param_1,param_2,local_3c[0],param_4,param_5,param_6,param_7,param_8);
      return uVar3;
    case 5:
      local_30 = (byte *)*param_2;
      iVar9 = tasn_dec__6008f370(0,local_2c,&local_33,0,0,&local_30,local_3c[0],0xffffffff,0,1,
                                 param_8);
      if (iVar9 == 0) {
        uVar13 = 0xe7;
        goto LAB_6008fb0e;
      }
      uVar3 = DAT_6008fcf0;
      if (local_33 == '\0') {
        uVar6 = 0;
        if (local_2c[0] < 0x1f) {
          uVar6 = *(uint *)(DAT_6008fcf8 + local_2c[0] * 4);
        }
        if ((uVar6 & *(uint *)(param_4 + 4)) != 0) {
          param_6 = 0;
          param_7 = '\0';
          goto LAB_6008face;
        }
        if (param_7 != '\0') {
          return 0xffffffff;
        }
        uVar4 = 0x9d;
        uVar13 = 0xf8;
      }
      else {
        if (param_7 != '\0') {
          return 0xffffffff;
        }
        uVar4 = 0x9c;
        uVar13 = 0xf0;
      }
      break;
    default:
      goto switchD_6008fa80_default;
    }
  }
  else {
    uVar4 = 0xc0;
    uVar13 = 200;
  }
LAB_6008fb14:
  FUN_600e0552(0xc,0,uVar4,uVar3,uVar13);
LAB_6008fb1a:
  if (uVar5 == 0) {
    puVar8 = (uint *)0x0;
LAB_6008fd12:
    FUN_600eca02(param_1,param_4);
LAB_6008fd1a:
    if (puVar8 != (uint *)0x0) {
LAB_6008fd20:
      FUN_600e05bc(4,DAT_6008ffb8,puVar8[3],DAT_6008ffbc,*(undefined4 *)(param_4 + 0x18));
      return 0;
    }
  }
  FUN_600e05bc(2,DAT_6008fcf4,*(undefined4 *)(param_4 + 0x18));
switchD_6008fa80_default:
  return 0;
code_r0x6008ff3e:
  iVar10 = iVar10 + 0x14;
  iVar9 = iVar9 + 1;
  uVar3 = FUN_600eccd4(param_1,puVar8);
  FUN_600eca08(uVar3,puVar8);
  goto LAB_6008ff54;
}


