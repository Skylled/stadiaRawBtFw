// 6008ffc0  tasn_dec__6008ffc0  size=514 bytes
// src: tasn_dec.c
// --- callers ---
//   600901c8 tasn_dec__600901c8
// --- callees ---
//   6008f370 tasn_dec__6008f370
//   600e0ab2 FUN_600e0ab2
//   600e0552 FUN_600e0552
//   600eca08 FUN_600eca08
//   6008fa18 tasn_dec__6008fa18
//   600e0aac FUN_600e0aac
//   600eca02 FUN_600eca02
//   600ec740 FUN_600ec740
//   600e0bee FUN_600e0bee
//   600e0be8 FUN_600e0be8


/* src: tasn_dec.c */

undefined4
tasn_dec__6008ffc0(int *param_1,int *param_2,int param_3,uint *param_4,undefined1 param_5,
                  undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_3c [2];
  char local_31;
  int local_30;
  undefined4 local_2c [2];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  uVar3 = *param_4;
  local_30 = *param_2;
  uVar5 = uVar3 & 0xc0;
  local_3c[0] = param_3;
  if ((uVar3 & 6) == 0) {
    if ((uVar3 & 8) == 0) {
      iVar1 = tasn_dec__6008fa18(param_1,&local_30,param_3,param_4[4],0xffffffff,uVar3 & 0x400,
                                 param_5,param_6,param_7);
      if (iVar1 != 0) goto LAB_6009017e;
      uVar6 = 0x2cc;
    }
    else {
      iVar1 = tasn_dec__6008fa18(param_1,&local_30,param_3,param_4[4],param_4[1],uVar5,param_5,
                                 param_6,param_7);
      if (iVar1 != 0) {
LAB_6009017e:
        if (iVar1 == -1) {
          return 0xffffffff;
        }
LAB_600901b2:
        *param_2 = local_30;
        return 1;
      }
      uVar6 = 0x2c2;
    }
LAB_6009011c:
    uVar4 = 0x9e;
  }
  else {
    if ((uVar3 & 8) == 0) {
      if ((uVar3 & 2) == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = 0x11;
      }
      uVar5 = 0;
    }
    else {
      uVar3 = param_4[1];
    }
    iVar1 = tasn_dec__6008f370(local_3c,0,0,&local_31,0,&local_30,param_3,uVar3,uVar5,param_5,
                               param_6);
    if (iVar1 == 0) {
      FUN_600e0552(0xc,0,0x9e,DAT_600901c4,0x287);
      return 0;
    }
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    iVar1 = *param_1;
    if (iVar1 == 0) {
      iVar1 = FUN_600e0aac();
      *param_1 = iVar1;
    }
    else {
      while (iVar2 = FUN_600e0ab2(iVar1), iVar2 != 0) {
        local_2c[0] = FUN_600e0bee(iVar1);
        FUN_600eca02(local_2c,param_4[4]);
      }
    }
    if (*param_1 == 0) {
      uVar4 = 0x41;
      uVar6 = 0x29a;
    }
    else {
      do {
        iVar1 = local_30;
        if (local_3c[0] < 1) {
LAB_600900e2:
          if (local_31 == '\0') goto LAB_600901b2;
          uVar4 = 0x99;
          uVar6 = 0x2ba;
          goto LAB_600900ba;
        }
        if ((local_3c[0] != 1) && (iVar2 = FUN_600ec740(&local_30), iVar2 != 0)) {
          if (local_31 != '\0') {
            local_3c[0] = local_3c[0] - (local_30 - iVar1);
            local_31 = '\0';
            goto LAB_600900e2;
          }
          uVar4 = 0xb4;
          uVar6 = 0x2a5;
          goto LAB_600900ba;
        }
        local_2c[0] = 0;
        iVar2 = tasn_dec__6008fa18(local_2c,&local_30,local_3c[0],param_4[4],0xffffffff,0,0,param_6,
                                   param_7);
        if (iVar2 == 0) {
          uVar6 = 0x2af;
          goto LAB_6009011c;
        }
        local_3c[0] = local_3c[0] - (local_30 - iVar1);
        iVar1 = FUN_600e0be8(*param_1,local_2c[0]);
      } while (iVar1 != 0);
      FUN_600eca02(local_2c,param_4[4]);
      uVar4 = 0x41;
      uVar6 = 0x2b5;
    }
  }
LAB_600900ba:
  FUN_600e0552(0xc,0,uVar4,DAT_600901c4,uVar6);
  FUN_600eca08(param_1,param_4);
  return 0;
}


