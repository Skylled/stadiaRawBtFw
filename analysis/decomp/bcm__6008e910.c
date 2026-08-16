// 6008e910  bcm__6008e910  size=326 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
//   60085528 FUN_60085528
// --- callees ---
//   6008b50c bcm__6008b50c
//   600e7474 FUN_600e7474
//   6008e700 bcm__6008e700
//   600e7490 FUN_600e7490
//   6008b544 FUN_6008b544
//   6008b570 bcm__6008b570
//   600e77c0 FUN_600e77c0
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600e7718 FUN_600e7718
//   600e7548 FUN_600e7548
//   6008d730 bcm__6008d730


/* src: bcm.c */

bool bcm__6008e910(int param_1,undefined4 *param_2,byte *param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  bool bVar10;
  undefined4 uVar11;
  int local_2c;
  
  iVar2 = FUN_600eb428(param_1,*param_2);
  if (iVar2 != 0) {
    FUN_600e0552(0xf,0,0x6a,DAT_6008ea58,0xd8);
    return false;
  }
  bVar10 = false;
  if (param_4 == 0) {
    uVar6 = 100;
    uVar11 = 0x88;
  }
  else {
    bVar1 = *param_3;
    bVar9 = bVar1 & 0xfe;
    if ((bVar9 == 2) || ((bVar9 == 4 && ((bVar1 & 1) == 0)))) {
      iVar7 = param_1 + 0x24;
      iVar3 = FUN_600e7474(iVar7);
      iVar8 = iVar3 + 1;
      iVar2 = iVar8;
      if (bVar9 == 4) {
        iVar2 = iVar3 + iVar8;
      }
      if (param_4 == iVar2) {
        if (param_5 == 0) {
          local_2c = bcm__6008b50c();
          param_5 = local_2c;
          if (local_2c == 0) goto LAB_6008e958;
        }
        else {
          local_2c = 0;
        }
        FUN_600e7718(param_5);
        iVar2 = bcm__6008b570(param_5);
        iVar4 = bcm__6008b570(param_5);
        if (((iVar2 != 0) && (iVar4 != 0)) &&
           (iVar5 = FUN_600e7490(param_3 + 1,iVar3,iVar2), iVar5 != 0)) {
          iVar5 = FUN_600e7548(iVar2,iVar7);
          if (iVar5 < 0) {
            if (bVar9 == 2) {
              iVar2 = bcm__6008e700(param_1,param_2,iVar2,bVar1 & 1,param_5);
            }
            else {
              iVar3 = FUN_600e7490(param_3 + iVar8,iVar3,iVar4);
              if (iVar3 == 0) goto LAB_6008e9f8;
              iVar3 = FUN_600e7548(iVar4,iVar7);
              if (-1 < iVar3) {
                uVar11 = 0xc2;
                goto LAB_6008e9ea;
              }
              iVar2 = bcm__6008d730(param_1,param_2,iVar2,iVar4,param_5);
            }
            bVar10 = iVar2 != 0;
          }
          else {
            uVar11 = 0xb5;
LAB_6008e9ea:
            FUN_600e0552(0xf,0,0x6d,DAT_6008ea58,uVar11);
          }
        }
LAB_6008e9f8:
        FUN_600e77c0(param_5);
        goto LAB_6008e958;
      }
      uVar11 = 0x9e;
    }
    else {
      uVar11 = 0x92;
    }
    uVar6 = 0x6d;
  }
  local_2c = 0;
  FUN_600e0552(0xf,0,uVar6,DAT_6008ea58,uVar11);
LAB_6008e958:
  FUN_6008b544(local_2c);
  return bVar10;
}


