// 6008db50  bcm__6008db50  size=216 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
// --- callees ---
//   6008b50c bcm__6008b50c
//   6008d2a8 bcm__6008d2a8
//   6008ccb4 bcm__6008ccb4
//   6008b544 FUN_6008b544
//   6008d6f8 bcm__6008d6f8
//   6008db08 bcm__6008db08
//   600ea802 FUN_600ea802
//   600e0552 FUN_600e0552
//   6008da3c bcm__6008da3c


/* src: bcm.c */

int bcm__6008db50(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    FUN_600e0552(0xf,0,0x43,DAT_6008dc28,300,param_2,param_3);
    return 0;
  }
  iVar1 = bcm__6008da3c();
  if (iVar1 != 0) {
    iVar5 = 0;
    iVar1 = 0;
    FUN_600e0552(0xf,0,0x77,DAT_6008dc28,0x131,param_2,param_3);
    iVar3 = 0;
    goto LAB_6008db98;
  }
  iVar5 = bcm__6008b50c();
  iVar1 = 0;
  if (iVar5 == 0) {
    iVar3 = 0;
    goto LAB_6008db98;
  }
  iVar2 = bcm__6008d6f8(*param_1,param_1[1],iVar5);
  iVar3 = iVar1;
  if (iVar2 == 0) {
    FUN_600e0552(0xf,0,0x78,DAT_6008dc28,0x13d,param_2,param_3);
    goto LAB_6008db98;
  }
  if (param_1[2] == 0) {
LAB_6008dc24:
    iVar1 = 1;
  }
  else {
    iVar3 = bcm__6008d2a8(*param_1);
    if ((iVar3 == 0) || (iVar2 = bcm__6008ccb4(*param_1,iVar3 + 4,param_1[2] + 0x14), iVar2 == 0)) {
      uVar4 = 0xf;
      uVar6 = 0x147;
    }
    else {
      iVar2 = bcm__6008db08(*param_1,iVar3,param_1[1],iVar5);
      if (iVar2 == 0) goto LAB_6008dc24;
      uVar4 = 0x71;
      uVar6 = 0x14b;
    }
    FUN_600e0552(0xf,0,uVar4,DAT_6008dc28,uVar6);
  }
LAB_6008db98:
  FUN_6008b544(iVar5);
  FUN_600ea802(iVar3);
  return iVar1;
}


