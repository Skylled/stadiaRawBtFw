// 600cddc8  FUN_600cddc8  size=473 bytes
// --- callers ---
//   600cdd2c FUN_600cdd2c
//   600cdd88 FUN_600cdd88
//   60102536 FUN_60102536
//   600cdcc4 FUN_600cdcc4
// --- callees ---
//   600d3594 FUN_600d3594
//   6004c620 FUN_6004c620
//   601025a8 FUN_601025a8
//   600cdfb4 FUN_600cdfb4


int FUN_600cddc8(undefined4 *param_1,int *param_2,byte *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  bool bVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *unaff_r9;
  int *local_8c;
  uint local_88;
  int local_84;
  undefined4 uStack_80;
  int local_7c;
  int local_74;
  byte local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_45;
  undefined4 local_30;
  
  local_8c = param_4;
  if (((int)((uint)*(ushort *)(param_2 + 3) << 0x18) < 0) && (param_2[4] == 0)) {
    iVar1 = FUN_600d3594(param_1,0x40);
    *param_2 = iVar1;
    param_2[4] = iVar1;
    if (iVar1 == 0) {
      *param_1 = 0xc;
      return -1;
    }
    param_2[5] = 0x40;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar6 = param_3;
LAB_600cde12:
  pbVar7 = pbVar6;
  if (*pbVar7 != 0) goto code_r0x600cde1a;
  goto LAB_600cde1e;
code_r0x600cde1a:
  pbVar6 = pbVar7 + 1;
  if (*pbVar7 != 0x25) goto LAB_600cde12;
LAB_600cde1e:
  iVar1 = (int)pbVar7 - (int)param_3;
  if (iVar1 != 0) {
    iVar2 = FUN_601025a8(param_1,param_2,param_3,iVar1);
    if (iVar2 == -1) {
LAB_600cdf7e:
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
        return -1;
      }
      return local_74;
    }
    local_74 = local_74 + iVar1;
  }
  if (*pbVar7 == 0) goto LAB_600cdf7e;
  local_84 = -1;
  uStack_80 = 0;
  local_88 = 0;
  local_7c = 0;
  local_45 = 0;
  local_30 = 0;
  pbVar6 = pbVar7 + 1;
  while( true ) {
    param_3 = pbVar6 + 1;
    iVar2 = FUN_6004c620(s___0__6013cd5a,*pbVar6,5);
    iVar1 = DAT_600cdfa4;
    if (iVar2 == 0) break;
    local_88 = 1 << (iVar2 + 0x9fec32a6U & 0xff) | local_88;
    pbVar6 = param_3;
  }
  if ((int)(local_88 << 0x1b) < 0) {
    local_45 = 0x20;
  }
  if ((int)(local_88 << 0x1c) < 0) {
    local_45 = 0x2b;
  }
  if (*pbVar6 == 0x2a) {
    piVar4 = local_8c + 1;
    iVar2 = *local_8c;
    local_8c = piVar4;
    if (-1 < iVar2) goto LAB_600cdebc;
    local_7c = -iVar2;
    local_88 = local_88 | 2;
  }
  else {
    bVar5 = false;
    iVar2 = local_7c;
    param_3 = pbVar6;
    while( true ) {
      if (9 < *param_3 - 0x30) break;
      iVar2 = iVar2 * 10 + (*param_3 - 0x30);
      bVar5 = true;
      param_3 = param_3 + 1;
    }
    if (bVar5) {
LAB_600cdebc:
      local_7c = iVar2;
    }
  }
  if (*param_3 == 0x2e) {
    if (param_3[1] == 0x2a) {
      local_84 = *local_8c;
      if (local_84 < 0) {
        local_84 = -1;
      }
      param_3 = param_3 + 2;
      local_8c = local_8c + 1;
    }
    else {
      bVar5 = false;
      local_84 = 0;
      iVar2 = 0;
      while( true ) {
        param_3 = param_3 + 1;
        if (9 < *param_3 - 0x30) break;
        iVar2 = iVar2 * 10 + (*param_3 - 0x30);
        bVar5 = true;
      }
      if (bVar5) {
        local_84 = iVar2;
      }
    }
  }
  iVar2 = FUN_6004c620(DAT_600cdfa4,*param_3,3);
  if (iVar2 != 0) {
    local_88 = local_88 | 0x40 << (iVar2 - iVar1 & 0xffU);
    param_3 = param_3 + 1;
  }
  local_70 = *param_3;
  param_3 = param_3 + 1;
  iVar1 = FUN_6004c620(DAT_600cdfa8,local_70,6);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)FUN_600cdfb4(param_1,&local_88,param_2,DAT_600cdfb0,&local_8c);
  }
  else {
    puVar3 = param_1;
    if (DAT_600cdfac == 0) {
      local_8c = (int *)(((int)local_8c + 7U & 0xfffffff8) + 8);
      puVar3 = unaff_r9;
      goto LAB_600cdf2c;
    }
  }
  if (puVar3 == (undefined4 *)0xffffffff) goto LAB_600cdf7e;
LAB_600cdf2c:
  local_74 = local_74 + (int)puVar3;
  pbVar6 = param_3;
  unaff_r9 = puVar3;
  goto LAB_600cde12;
}


