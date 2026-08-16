// 6008e700  bcm__6008e700  size=524 bytes
// src: bcm.c
// --- callers ---
//   6008e910 bcm__6008e910
// --- callees ---
//   6008b50c bcm__6008b50c
//   600e7e8a FUN_600e7e8a
//   6013cff8 thunk_EXT_FUN_0000ac1e
//   600e053a FUN_600e053a
//   6008b570 bcm__6008b570
//   600eaf44 FUN_600eaf44
//   600e7efe FUN_600e7efe
//   600e0552 FUN_600e0552
//   600e7ccc FUN_600e7ccc
//   600eb428 FUN_600eb428
//   600e7554 FUN_600e7554
//   600e7718 FUN_600e7718
//   600e7706 FUN_600e7706
//   600e75c2 FUN_600e75c2
//   600e98a4 FUN_600e98a4
//   6008d730 bcm__6008d730
//   6008b544 FUN_6008b544
//   600e77c0 FUN_600e77c0
//   600e984a FUN_600e984a
//   6008e264 bcm__6008e264
//   600e7e0e FUN_600e7e0e


/* src: bcm.c */

bool bcm__6008e700(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int local_3c;
  
  iVar1 = FUN_600eb428(param_1,*param_2);
  if (iVar1 != 0) {
    FUN_600e0552(0xf,0,0x6a,DAT_6008e90c,0xec);
    return false;
  }
  bVar9 = false;
  if (*(int *)(param_3 + 0xc) != 0) {
LAB_6008e74a:
    FUN_600e0552(0xf,0,0x6b,DAT_6008e90c,0xf1);
    return false;
  }
  iVar8 = param_1 + 0x24;
  iVar1 = FUN_600e7554(param_3,iVar8);
  if (-1 < iVar1) goto LAB_6008e74a;
  thunk_EXT_FUN_0000ac1e();
  if (param_5 == 0) {
    param_5 = bcm__6008b50c();
    local_3c = param_5;
    if (param_5 == 0) {
      return false;
    }
  }
  else {
    local_3c = 0;
  }
  FUN_600e7718(param_5);
  uVar2 = bcm__6008b570(param_5);
  uVar3 = bcm__6008b570(param_5);
  uVar4 = bcm__6008b570(param_5);
  uVar5 = bcm__6008b570(param_5);
  iVar1 = bcm__6008b570(param_5);
  if ((((iVar1 == 0) || (iVar6 = FUN_600eaf44(param_1,0,uVar4,uVar5), iVar6 == 0)) ||
      (iVar6 = FUN_600e98a4(uVar3,param_3,iVar8,param_5), iVar6 == 0)) ||
     (iVar6 = FUN_600e984a(uVar2,uVar3,param_3,iVar8,param_5), iVar6 == 0)) goto LAB_6008e8f2;
  if (*(int *)(param_1 + 0xc0) == 0) {
    iVar6 = FUN_600e984a(uVar3,uVar4,param_3,iVar8,param_5);
    if (iVar6 == 0) goto LAB_6008e8f2;
    iVar6 = FUN_600e7e0e(uVar2,uVar2,uVar3,iVar8,param_5);
  }
  else {
    iVar6 = FUN_600e7e8a(uVar3,param_3,iVar8,param_5);
    if ((iVar6 == 0) || (iVar6 = FUN_600e7e0e(uVar3,uVar3,param_3,iVar8,param_5), iVar6 == 0))
    goto LAB_6008e8f2;
    iVar6 = FUN_600e7efe(uVar2,uVar2,uVar3,iVar8,param_5);
  }
  if ((iVar6 == 0) || (iVar6 = FUN_600e7e0e(uVar2,uVar2,uVar5,iVar8,param_5), iVar6 == 0))
  goto LAB_6008e8f2;
  iVar6 = bcm__6008e264(iVar1,uVar2,iVar8,param_5);
  if (iVar6 == 0) {
    uVar7 = FUN_600e053a();
    if ((uVar7 >> 0x18 == 3) && ((uVar7 & 0xfff) == 0x6e)) {
      thunk_EXT_FUN_0000ac1e();
      uVar2 = 0x6b;
      uVar3 = 0x131;
    }
    else {
      uVar2 = 3;
      uVar3 = 0x133;
    }
  }
  else {
    uVar7 = FUN_600e7706(iVar1);
    if (uVar7 != (param_4 != 0)) {
      iVar6 = FUN_600e75c2(iVar1);
      if (iVar6 != 0) {
        uVar2 = 0x6c;
        uVar3 = 0x13a;
        goto LAB_6008e858;
      }
      iVar8 = FUN_600e7ccc(iVar1,iVar8,iVar1);
      if (iVar8 == 0) goto LAB_6008e8f2;
    }
    uVar7 = FUN_600e7706(iVar1);
    if (uVar7 == (param_4 != 0)) {
      iVar1 = bcm__6008d730(param_1,param_2,param_3,iVar1,param_5);
      bVar9 = iVar1 != 0;
      goto LAB_6008e8f2;
    }
    uVar2 = 0x44;
    uVar3 = 0x142;
  }
LAB_6008e858:
  FUN_600e0552(0xf,0,uVar2,DAT_6008e90c,uVar3);
LAB_6008e8f2:
  FUN_600e77c0(param_5);
  FUN_6008b544(local_3c);
  return bVar9;
}


