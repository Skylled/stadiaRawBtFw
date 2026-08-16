// 60091330  ec_asn1__60091330  size=580 bytes
// src: ec_asn1.c
// --- callers ---
//   60091580 ec_asn1__60091580
// --- callees ---
//   600ed398 FUN_600ed398
//   600ed58a FUN_600ed58a
//   600ed37a FUN_600ed37a
//   600ed62e FUN_600ed62e
//   600eda1c FUN_600eda1c
//   600ed556 FUN_600ed556
//   600eda64 FUN_600eda64
//   6008d7ac bcm__6008d7ac
//   60091238 ec_asn1__60091238
//   600e0552 FUN_600e0552
//   600ed3ba FUN_600ed3ba
//   600ed5b4 FUN_600ed5b4
//   6013d168 thunk_EXT_FUN_0000b554
//   600ed39c FUN_600ed39c
//   6008cbe0 FUN_6008cbe0


/* src: ec_asn1.c */

undefined4 ec_asn1__60091330(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char local_8d;
  int local_8c;
  int local_88;
  int iStack_84;
  undefined1 auStack_80 [8];
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [8];
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  iVar2 = FUN_600ed58a(param_1,DAT_60091574);
  if (iVar2 == 0) {
    uVar3 = ec_asn1__60091238(param_1);
    return uVar3;
  }
  iVar2 = FUN_600ed556(param_1,auStack_50,DAT_60091574);
  if ((((iVar2 == 0) || (iVar2 = FUN_600ed5b4(auStack_50,&local_88), iVar2 == 0)) ||
      (iStack_84 != 0 || local_88 != 1)) ||
     (((iVar2 = FUN_600ed556(auStack_50,auStack_48,DAT_60091574), iVar2 == 0 ||
       (iVar2 = FUN_600ed556(auStack_48,auStack_40,6), iVar2 == 0)) ||
      (iVar2 = FUN_600ed39c(auStack_40), iVar2 != 7)))) {
LAB_60091358:
    uVar3 = 0x125;
  }
  else {
    uVar3 = FUN_600ed398(auStack_40);
    iVar2 = thunk_EXT_FUN_0000b554(uVar3,DAT_6009157c,7);
    if (((((iVar2 != 0) || (iVar2 = FUN_600ed556(auStack_48,auStack_80,2), iVar2 == 0)) ||
         ((iVar2 = FUN_600eda64(auStack_80), iVar2 == 0 ||
          (((iVar2 = FUN_600ed39c(auStack_48), iVar2 != 0 ||
            (iVar2 = FUN_600ed556(auStack_50,auStack_38,DAT_60091574), iVar2 == 0)) ||
           (iVar2 = FUN_600ed556(auStack_38,auStack_78,4), iVar2 == 0)))))) ||
        ((iVar2 = FUN_600ed556(auStack_38,auStack_70,4), iVar2 == 0 ||
         (iVar2 = FUN_600ed62e(auStack_38,0,0,3), iVar2 == 0)))) ||
       ((iVar2 = FUN_600ed39c(auStack_38), iVar2 != 0 ||
        (((iVar2 = FUN_600ed556(auStack_50,auStack_30,4), iVar2 == 0 ||
          (iVar2 = FUN_600ed556(auStack_50,auStack_58,2), iVar2 == 0)) ||
         ((iVar2 = FUN_600eda64(auStack_58), iVar2 == 0 ||
          ((iVar2 = FUN_600ed62e(auStack_50,auStack_28,&local_8c,2), iVar2 == 0 ||
           (iVar2 = FUN_600ed39c(auStack_50), iVar2 != 0)))))))))) goto LAB_60091358;
    if ((local_8c != 0) &&
       ((iVar2 = FUN_600ed39c(auStack_28), iVar2 != 1 ||
        (pcVar4 = (char *)FUN_600ed398(auStack_28), *pcVar4 != '\x01')))) {
      uVar3 = 0x12d;
LAB_60091474:
      uVar8 = 0x7b;
      goto LAB_600914a6;
    }
    iVar2 = FUN_600ed3ba(auStack_30,&local_8d);
    if ((iVar2 == 0) || (local_8d != '\x04')) {
      uVar8 = 0x6f;
      uVar3 = 0x135;
      goto LAB_600914a6;
    }
    iVar2 = FUN_600ed39c(auStack_30);
    if (-1 < iVar2 << 0x1f) {
      uVar5 = FUN_600ed39c(auStack_30);
      uVar5 = uVar5 >> 1;
      uVar3 = FUN_600ed398(auStack_30);
      FUN_600ed37a(auStack_68,uVar3,uVar5);
      iVar2 = FUN_600ed398(auStack_30);
      FUN_600ed37a(auStack_60,iVar2 + uVar5,uVar5);
      iVar6 = FUN_6008cbe0();
      iVar2 = 0;
      iVar9 = iVar6;
      do {
        bVar1 = *(byte *)(iVar9 + 0x10);
        uVar5 = (uint)bVar1;
        iVar7 = FUN_600eda1c(auStack_80,*(undefined4 *)(iVar9 + 0x14),uVar5);
        if ((iVar7 != 0) &&
           (iVar7 = FUN_600eda1c(auStack_78,*(int *)(iVar9 + 0x14) + uVar5,uVar5), iVar7 != 0)) {
          iVar10 = (int)(short)(ushort)bVar1;
          iVar7 = FUN_600eda1c(auStack_70,*(int *)(iVar9 + 0x14) + iVar10 * 2,uVar5);
          if ((iVar7 != 0) &&
             (((iVar7 = FUN_600eda1c(auStack_68,*(int *)(iVar9 + 0x14) + iVar10 * 3,uVar5),
               iVar7 != 0 &&
               (iVar7 = FUN_600eda1c(auStack_60,*(int *)(iVar9 + 0x14) + iVar10 * 4,uVar5),
               iVar7 != 0)) &&
              (iVar7 = FUN_600eda1c(auStack_58,*(int *)(iVar9 + 0x14) + iVar10 * 5,uVar5),
              iVar7 != 0)))) {
            uVar3 = bcm__6008d7ac(*(undefined4 *)(iVar6 + iVar2 * 0x1c));
            return uVar3;
          }
        }
        iVar2 = iVar2 + 1;
        iVar9 = iVar9 + 0x1c;
      } while (iVar2 != 4);
      uVar3 = 0x1a2;
      goto LAB_60091474;
    }
    uVar3 = 0x13a;
  }
  uVar8 = 0x80;
LAB_600914a6:
  FUN_600e0552(0xf,0,uVar8,DAT_60091578,uVar3);
  return 0;
}


