// 6008f794  tasn_dec__6008f794  size=640 bytes
// src: tasn_dec.c
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
// --- callees ---
//   600e0552 FUN_600e0552
//   600ecea2 thunk_FUN_600ece78
//   6008f4ac tasn_dec__6008f4ac
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6008f5e8 tasn_dec__6008f5e8
//   600ec740 FUN_600ec740
//   6008f370 tasn_dec__6008f370


/* src: tasn_dec.c */

undefined4
tasn_dec__6008f794(int param_1,int *param_2,undefined4 param_3,char *param_4,uint param_5,
                  undefined4 param_6,char param_7,undefined1 *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char local_4c;
  char local_4b;
  char local_4a;
  char local_49;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  
  local_4a = '\0';
  local_2c = 0;
  local_34 = 0;
  local_30 = 0;
  if (param_1 == 0) {
    uVar4 = 0x84;
    uVar8 = 0x2e7;
    goto LAB_6008f7c4;
  }
  if (*param_4 == '\x05') {
    local_48 = param_5;
    param_5 = 0xffffffff;
  }
  else {
    local_48 = *(uint *)(param_4 + 4);
  }
  if (local_48 == 0xfffffffc) {
    if (-1 < (int)param_5) {
      uVar4 = 0x89;
      uVar8 = 0x2f5;
      goto LAB_6008f7c4;
    }
    if (param_7 != '\0') {
      uVar4 = 0x87;
      uVar8 = 0x2f9;
      goto LAB_6008f7c4;
    }
    local_40 = *param_2;
    iVar1 = tasn_dec__6008f370(0,&local_48,&local_38,0,0,&local_40,param_3,0xffffffff,0,0,param_8);
    if (iVar1 == 0) {
      uVar4 = 0x9e;
      uVar8 = 0x300;
      goto LAB_6008f7c4;
    }
    if ((char)local_38 != '\0') {
      local_48 = 0xfffffffd;
    }
  }
  local_40 = *param_2;
  if (param_5 == 0xffffffff) {
    param_6 = 0;
    param_5 = local_48;
  }
  iVar1 = tasn_dec__6008f370(&local_44,0,0,&local_4b,&local_4c,&local_40,param_3,param_5,param_6,
                             param_7,param_8);
  if (iVar1 == 0) {
    uVar4 = 0x9e;
    uVar8 = 0x30f;
LAB_6008f886:
    FUN_600e0552(0xc,0,uVar4,DAT_6008fa14,uVar8);
    return 0;
  }
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if (local_48 - 0x10 < 2) {
    if (local_4c == '\0') {
      uVar4 = 0xb2;
      uVar8 = 800;
      goto LAB_6008f886;
    }
LAB_6008f8ae:
    iVar1 = *param_2;
    if (local_4b == '\0') {
      iVar6 = local_44 + local_40;
      local_44 = (local_40 - iVar1) + local_44;
      local_40 = iVar6;
LAB_6008f980:
      iVar1 = tasn_dec__6008f5e8(param_1,iVar1,local_44,local_48,&local_4a,param_4);
      if (iVar1 != 0) {
        uVar5 = 1;
        *param_2 = local_40;
        goto LAB_6008f948;
      }
    }
    else {
      iVar7 = 1;
      local_49 = local_4b;
      local_38 = local_40;
      iVar6 = local_44;
      while (0 < iVar6) {
        if ((iVar6 == 1) || (iVar2 = FUN_600ec740(&local_38), iVar2 == 0)) {
          iVar2 = local_38;
          iVar3 = tasn_dec__6008f370(&local_3c,0,0,&local_49,0,&local_38,iVar6,0xffffffff,0,0,0);
          if (iVar3 == 0) {
            uVar4 = 0x9e;
            uVar8 = 0x40b;
            goto LAB_6008f940;
          }
          if (local_49 == '\0') {
            local_38 = local_38 + local_3c;
          }
          else {
            iVar7 = iVar7 + 1;
          }
          iVar6 = iVar6 - (local_38 - iVar2);
        }
        else {
          iVar7 = iVar7 + -1;
          if (iVar7 == 0) {
            local_44 = local_38 - iVar1;
            local_40 = local_38;
            goto LAB_6008f980;
          }
          iVar6 = iVar6 + -2;
        }
      }
      FUN_600e0552(0xc,0,0x99,DAT_6008fa14,0x415);
    }
  }
  else {
    if (local_48 == 0xfffffffd) {
      if (param_8 != (undefined1 *)0x0) {
        *param_8 = 0;
      }
      goto LAB_6008f8ae;
    }
    if (local_4c == '\0') {
      iVar1 = local_40;
      local_40 = local_40 + local_44;
      goto LAB_6008f980;
    }
    if (((local_48 & 0xfffffffb) - 1 < 2) || (local_48 == 10)) {
      uVar4 = 0xb3;
      uVar8 = 0x333;
LAB_6008f7c4:
      FUN_600e0552(0xc,0,uVar4,DAT_6008fa14,uVar8);
      return 0;
    }
    local_4a = '\x01';
    iVar1 = tasn_dec__6008f4ac(&local_34,&local_40,local_44,local_4b,0);
    local_44 = local_34;
    if (iVar1 != 0) {
      iVar1 = thunk_FUN_600ece78(&local_34,local_34 + 1);
      if (iVar1 == 0) {
        uVar4 = 0x41;
        uVar8 = 0x345;
LAB_6008f940:
        uVar5 = 0;
        FUN_600e0552(0xc,0,uVar4,DAT_6008fa14,uVar8);
        goto LAB_6008f948;
      }
      *(undefined1 *)(local_30 + local_44) = 0;
      iVar1 = local_30;
      goto LAB_6008f980;
    }
  }
  uVar5 = 0;
LAB_6008f948:
  if (local_4a == '\0') {
    return uVar5;
  }
  if (local_30 == 0) {
    return uVar5;
  }
  thunk_EXT_FUN_0000ac5e();
  return uVar5;
}


