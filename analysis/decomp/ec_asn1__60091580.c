// 60091580  ec_asn1__60091580  size=530 bytes
// src: ec_asn1.c
// --- callers ---
// --- callees ---
//   6008d6b8 bcm__6008d6b8
//   600e7490 FUN_600e7490
//   6008db50 bcm__6008db50
//   6008cfd4 bcm__6008cfd4
//   6008ce00 FUN_6008ce00
//   600eb400 FUN_600eb400
//   6008d2a8 bcm__6008d2a8
//   600ed556 FUN_600ed556
//   600ea7a4 FUN_600ea7a4
//   600e0552 FUN_600e0552
//   600ed398 FUN_600ed398
//   600ea868 bcm__600ea868
//   600ed58a FUN_600ed58a
//   600ed39c FUN_600ed39c
//   6008e910 bcm__6008e910
//   6008ccb4 bcm__6008ccb4
//   600ed5b4 FUN_600ed5b4
//   60091330 ec_asn1__60091330
//   600ed3ba FUN_600ed3ba
//   600e6a22 FUN_600e6a22


/* src: ec_asn1.c */

int ec_asn1__60091580(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char local_49;
  int local_48;
  int iStack_44;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [12];
  
  iVar1 = FUN_600ed556(param_1,auStack_40,DAT_60091794);
  if ((((iVar1 == 0) || (iVar1 = FUN_600ed5b4(auStack_40,&local_48), iVar1 == 0)) ||
      (iStack_44 != 0 || local_48 != 1)) ||
     (iVar1 = FUN_600ed556(auStack_40,auStack_38,4), iVar1 == 0)) {
    FUN_600e0552(0xf,0,0x80,DAT_60091798,0x52);
    return 0;
  }
  iVar1 = FUN_600ed58a(auStack_40,0xa0000000);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      FUN_600e0552(0xf,0,0x72,DAT_60091798,0x76);
      iVar6 = 0;
      iVar1 = 0;
      iVar7 = 0;
      goto LAB_6009161e;
    }
    iVar1 = 0;
LAB_6009165c:
    iVar6 = bcm__600ea868();
    if (iVar6 == 0) {
      iVar7 = 0;
      goto LAB_6009161e;
    }
    iVar7 = bcm__6008d6b8(iVar6,param_2);
    if (iVar7 == 0) {
      iVar7 = 0;
      goto LAB_6009161e;
    }
    uVar5 = FUN_600ed398(auStack_38);
    uVar4 = FUN_600ed39c(auStack_38);
    iVar7 = FUN_600e7490(uVar5,uVar4,0);
    iVar2 = bcm__6008d2a8(param_2);
    *(int *)(iVar6 + 4) = iVar2;
    if (((iVar7 == 0) || (iVar2 == 0)) || (iVar2 = bcm__6008cfd4(iVar6,iVar7), iVar2 == 0))
    goto LAB_6009161e;
    iVar2 = FUN_600ed58a(auStack_40,DAT_6009179c);
    if (iVar2 == 0) {
      iVar2 = bcm__6008ccb4(param_2,*(int *)(iVar6 + 4) + 4,*(int *)(iVar6 + 8) + 0x14);
      if (iVar2 == 0) goto LAB_6009161e;
      *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) | 2;
LAB_60091740:
      iVar2 = FUN_600ed39c(auStack_40);
      if (iVar2 == 0) {
        iVar2 = bcm__6008db50(iVar6);
        if (iVar2 != 0) {
          FUN_600e6a22(iVar7);
          FUN_600ea7a4(iVar1);
          return iVar6;
        }
        goto LAB_6009161e;
      }
      uVar5 = 0xac;
    }
    else {
      iVar2 = FUN_600ed556(auStack_40,auStack_30,DAT_6009179c);
      if ((((iVar2 != 0) && (iVar2 = FUN_600ed556(auStack_30,auStack_28,3), iVar2 != 0)) &&
          (iVar2 = FUN_600ed3ba(auStack_28,&local_49), iVar2 != 0)) &&
         ((local_49 == '\0' && (iVar2 = FUN_600ed39c(auStack_28), iVar2 != 0)))) {
        uVar8 = *(undefined4 *)(iVar6 + 4);
        uVar5 = FUN_600ed398(auStack_28);
        uVar4 = FUN_600ed39c(auStack_28);
        iVar2 = bcm__6008e910(param_2,uVar8,uVar5,uVar4,0);
        if ((iVar2 != 0) && (iVar2 = FUN_600ed39c(auStack_30), iVar2 == 0)) {
          pbVar3 = (byte *)FUN_600ed398(auStack_28);
          *(byte *)(iVar6 + 0x14) = *pbVar3 & 0xfe;
          goto LAB_60091740;
        }
      }
      uVar5 = 0x98;
    }
    FUN_600e0552(0xf,0,0x80,DAT_60091798,uVar5);
    goto LAB_6009161e;
  }
  iVar1 = FUN_600ed556(auStack_40,auStack_28,0xa0000000);
  if (iVar1 == 0) {
    uVar5 = 0x61;
    iVar1 = 0;
LAB_600915ea:
    uVar4 = 0x80;
LAB_60091612:
    FUN_600e0552(0xf,0,uVar4,DAT_60091798,uVar5);
  }
  else {
    iVar1 = ec_asn1__60091330(auStack_28);
    if (iVar1 != 0) {
      iVar6 = iVar1;
      if ((param_2 == 0) || (iVar7 = FUN_600eb400(param_2,iVar1,0), iVar6 = param_2, iVar7 == 0)) {
        iVar7 = FUN_600ed39c(auStack_28);
        param_2 = iVar6;
        if (iVar7 == 0) goto LAB_6009165c;
        uVar5 = 0x70;
        goto LAB_600915ea;
      }
      uVar4 = 0x82;
      uVar5 = 0x6c;
      goto LAB_60091612;
    }
  }
  iVar7 = 0;
  iVar6 = 0;
LAB_6009161e:
  FUN_6008ce00(iVar6);
  FUN_600e6a22(iVar7);
  FUN_600ea7a4(iVar1);
  return 0;
}


