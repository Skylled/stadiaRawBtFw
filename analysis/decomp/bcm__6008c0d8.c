// 6008c0d8  bcm__6008c0d8  size=628 bytes
// src: bcm.c
// --- callers ---
//   6008e264 bcm__6008e264
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e9b62 FUN_600e9b62
//   600e9dea FUN_600e9dea
//   600e7598 FUN_600e7598
//   6008ba20 bcm__6008ba20
//   6008b43c bcm__6008b43c
//   6008b570 bcm__6008b570
//   600e932c FUN_600e932c
//   600e965c FUN_600e965c
//   600e7706 FUN_600e7706
//   600e0552 FUN_600e0552
//   600e92f0 FUN_600e92f0
//   600e6a6c FUN_600e6a6c
//   600e7382 FUN_600e7382
//   600e7718 FUN_600e7718
//   600e72fc FUN_600e72fc
//   600e7548 FUN_600e7548
//   600e7450 FUN_600e7450


/* src: bcm.c */

uint bcm__6008c0d8(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                  int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  int local_bc;
  int local_ac [34];
  
  uVar13 = FUN_600e7706(param_4);
  if ((int)uVar13 == 0) {
    FUN_600e0552(3,0,0x68,DAT_6008c330,0x24e);
    return 0;
  }
  if (*(int *)(param_4 + 0xc) != 0) {
    uVar8 = 0x6d;
    uVar14 = 0x252;
LAB_6008c11c:
    FUN_600e0552(3,0,uVar8,DAT_6008c330,uVar14);
    return 0;
  }
  if ((*(int *)((int)((ulonglong)uVar13 >> 0x20) + 0xc) != 0) ||
     (iVar1 = FUN_600e7548(param_2,param_4), -1 < iVar1)) {
    uVar8 = 0x6b;
    uVar14 = 0x256;
    goto LAB_6008c11c;
  }
  iVar1 = FUN_600e7450(param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_600e7598(param_4,1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      return 1;
    }
    uVar2 = FUN_600e7382(param_1);
    return uVar2;
  }
  FUN_600e7718(param_5);
  iVar3 = bcm__6008b570(param_5);
  iVar4 = bcm__6008b570(param_5);
  local_ac[1] = iVar4;
  if ((iVar3 == 0) || (iVar4 == 0)) {
LAB_6008c18c:
    uVar2 = 0;
    local_bc = 0;
  }
  else {
    if (param_6 == 0) {
      param_6 = FUN_600e9b62(param_4,param_5);
      local_bc = param_6;
      if (param_6 == 0) goto LAB_6008c18c;
    }
    else {
      local_bc = 0;
    }
    iVar5 = FUN_600e6a6c(iVar1);
    iVar6 = FUN_600e965c(iVar4,param_2,param_6,param_5);
    uVar2 = 0;
    if (iVar6 != 0) {
      if (1 < iVar5) {
        iVar6 = bcm__6008b570(param_5);
        if (iVar6 == 0) {
          uVar2 = 0;
          goto LAB_6008c192;
        }
        iVar4 = bcm__6008ba20(iVar6,iVar4,iVar4,param_6,param_5);
        uVar2 = 0;
        if (iVar4 == 0) goto LAB_6008c192;
        local_ac[0] = 1 << (iVar5 - 1U & 0xff);
        for (iVar4 = 1; iVar4 < local_ac[0]; iVar4 = iVar4 + 1) {
          iVar7 = bcm__6008b570(param_5);
          local_ac[iVar4 + 1] = iVar7;
          uVar2 = 0;
          if (iVar7 == 0) goto LAB_6008c192;
          iVar7 = bcm__6008ba20(iVar7,local_ac[iVar4],iVar6,param_6,param_5);
          uVar2 = 0;
          if (iVar7 == 0) goto LAB_6008c192;
        }
      }
      uVar9 = iVar1 - 1;
      bVar12 = true;
      while( true ) {
        while (iVar1 = FUN_600e9dea(param_3,uVar9), iVar1 != 0) {
          uVar11 = 0;
          uVar2 = 1;
          uVar10 = uVar2;
          for (; ((int)uVar2 < iVar5 && ((int)uVar2 <= (int)uVar9)); uVar2 = uVar2 + 1) {
            iVar1 = FUN_600e9dea(param_3,uVar9 - uVar2);
            if (iVar1 != 0) {
              uVar10 = uVar10 << (uVar2 - uVar11 & 0xff) | 1;
              uVar11 = uVar2;
            }
          }
          iVar1 = 0;
          if (bVar12) {
            iVar1 = FUN_600e72fc(iVar3,local_ac[((int)uVar10 >> 1) + 1]);
            if (iVar1 == 0) {
              uVar2 = 0;
              goto LAB_6008c192;
            }
          }
          else {
            for (; iVar1 <= (int)uVar11; iVar1 = iVar1 + 1) {
              iVar4 = bcm__6008ba20(iVar3,iVar3,iVar3,param_6,param_5);
              uVar2 = 0;
              if (iVar4 == 0) goto LAB_6008c192;
            }
            iVar1 = bcm__6008ba20(iVar3,iVar3,local_ac[((int)uVar10 >> 1) + 1],param_6,param_5);
            uVar2 = 0;
            if (iVar1 == 0) goto LAB_6008c192;
          }
          if (uVar9 == uVar11) goto LAB_6008c2fe;
          bVar12 = false;
          uVar9 = uVar9 - (uVar11 + 1);
        }
        if ((!bVar12) && (iVar1 = bcm__6008ba20(iVar3,iVar3,iVar3,param_6,param_5), iVar1 == 0)) {
          uVar2 = 0;
          goto LAB_6008c192;
        }
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
      }
LAB_6008c2fe:
      iVar1 = FUN_600e932c(param_1,iVar3,param_6,param_5);
      uVar2 = (uint)(iVar1 != 0);
    }
  }
LAB_6008c192:
  FUN_600e92f0(local_bc);
  FUN_600e77c0(param_5);
  return uVar2;
}


