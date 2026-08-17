// 60090dd8  bn_asn1__60090dd8  size=142 bytes
// src: bn_asn1.c
// --- callers ---
//   600eda00 FUN_600eda00
//   60084d34 ecdsa_asn1__60084d34
//   600e0a54 FUN_600e0a54
// --- callees ---
//   600ed398 FUN_600ed398
//   600e7490 FUN_600e7490
//   600e0552 FUN_600e0552
//   600ed556 FUN_600ed556
//   600ed39c FUN_600ed39c


/* src: bn_asn1.c */

bool bn_asn1__60090dd8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_18 [12];
  
  iVar1 = FUN_600ed556(param_1,auStack_18,2);
  if ((iVar1 == 0) || (iVar1 = FUN_600ed39c(auStack_18), iVar1 == 0)) {
    uVar5 = 0x19;
  }
  else {
    pcVar2 = (char *)FUN_600ed398(auStack_18);
    if (*pcVar2 < '\0') {
      uVar4 = 0x6d;
      uVar5 = 0x1e;
      goto LAB_60090e12;
    }
    pcVar2 = (char *)FUN_600ed398(auStack_18);
    if (((*pcVar2 != '\0') || (uVar3 = FUN_600ed39c(auStack_18), uVar3 < 2)) ||
       (iVar1 = FUN_600ed398(auStack_18), *(char *)(iVar1 + 1) < '\0')) {
      uVar5 = FUN_600ed398(auStack_18);
      uVar4 = FUN_600ed39c(auStack_18);
      iVar1 = FUN_600e7490(uVar5,uVar4,param_2);
      return iVar1 != 0;
    }
    uVar5 = 0x26;
  }
  uVar4 = 0x75;
LAB_60090e12:
  FUN_600e0552(3,0,uVar4,DAT_60090e68,uVar5);
  return false;
}


