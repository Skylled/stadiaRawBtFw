// 6008d120  bcm__6008d120  size=258 bytes
// src: bcm.c
// --- callers ---
//   6008d228 bcm__6008d228
// --- callees ---
//   6008b50c bcm__6008b50c
//   6008bf00 FUN_6008bf00
//   600e7668 FUN_600e7668
//   600e7480 FUN_600e7480
//   6008b570 bcm__6008b570
//   600e0552 FUN_600e0552
//   600e7718 FUN_600e7718
//   600e7554 FUN_600e7554
//   600e7450 FUN_600e7450
//   600e7706 FUN_600e7706
//   6008b544 FUN_6008b544
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   6008b3b8 FUN_6008b3b8
//   6008ce70 bcm__6008ce70


/* src: bcm.c */

bool bcm__6008d120(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  
  uVar5 = param_2;
  uVar8 = param_3;
  uVar1 = FUN_600e7450(param_2);
  if ((uVar1 < 3) || (iVar2 = FUN_600e7706(param_2), iVar2 == 0)) {
    FUN_600e0552(0xf,0,0x6e,DAT_6008d224,0x6d,uVar5,uVar8);
    return false;
  }
  if (param_5 == 0) {
    param_5 = bcm__6008b50c();
    iVar2 = param_5;
    if (param_5 == 0) {
      return false;
    }
  }
  else {
    iVar2 = 0;
  }
  FUN_600e7718(param_5);
  iVar3 = bcm__6008b570(param_5);
  if (iVar3 != 0) {
    iVar6 = param_1 + 0x24;
    iVar4 = FUN_600e72fc(iVar6,param_2);
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      FUN_600e7480(iVar6);
      iVar4 = FUN_6008bf00(iVar3,param_3,iVar6,param_5);
      if (((iVar4 != 0) && (iVar4 = bcm__6008ce70(param_1,param_1 + 0x38,iVar3), iVar4 != 0)) &&
         (iVar4 = FUN_600e7668(iVar3,3), iVar4 != 0)) {
        iVar4 = FUN_600e7554(iVar3,iVar6);
        *(uint *)(param_1 + 0xc0) = (uint)(iVar4 == 0);
        iVar4 = FUN_6008bf00(iVar3,param_4,iVar6,param_5);
        if ((iVar4 != 0) && (iVar3 = bcm__6008ce70(param_1,param_1 + 0x7c,iVar3), iVar3 != 0)) {
          uVar5 = FUN_6008b3b8();
          iVar3 = bcm__6008ce70(param_1,param_1 + 0x114,uVar5);
          bVar7 = iVar3 != 0;
          goto LAB_6008d17a;
        }
      }
    }
  }
  bVar7 = false;
LAB_6008d17a:
  FUN_600e77c0(param_5);
  FUN_6008b544(iVar2);
  return bVar7;
}


