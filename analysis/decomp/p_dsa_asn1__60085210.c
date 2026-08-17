// 60085210  p_dsa_asn1__60085210  size=168 bytes
// src: p_dsa_asn1.c
// --- callers ---
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   600ed12a FUN_600ed12a
//   60090e6c bn_asn1__60090e6c
//   600ecfae FUN_600ecfae
//   600e0552 FUN_600e0552
//   600ed0de FUN_600ed0de
//   600911d4 FUN_600911d4


/* src: p_dsa_asn1.c */

undefined4 p_dsa_asn1__60085210(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  
  iVar4 = *(int *)(param_2 + 8);
  bVar1 = false;
  if (((*(int *)(iVar4 + 4) != 0) && (bVar1 = false, *(int *)(iVar4 + 8) != 0)) &&
     (bVar1 = false, *(int *)(iVar4 + 0xc) != 0)) {
    bVar1 = true;
  }
  iVar2 = FUN_600ed1b4(param_1,auStack_50,DAT_600852b8);
  if (((((iVar2 == 0) || (iVar2 = FUN_600ed1b4(auStack_50,auStack_40,DAT_600852b8), iVar2 == 0)) ||
       ((iVar2 = FUN_600ed1b4(auStack_40,auStack_30,6), iVar2 == 0 ||
        (iVar2 = FUN_600ed0de(auStack_30,DAT_600852c0,7), iVar2 == 0)))) ||
      ((bVar1 && (iVar2 = FUN_600911d4(auStack_40,iVar4), iVar2 == 0)))) ||
     ((iVar2 = FUN_600ed1b4(auStack_50,auStack_20,3), iVar2 == 0 ||
      (((iVar2 = FUN_600ed12a(auStack_20,0), iVar2 == 0 ||
        (iVar4 = bn_asn1__60090e6c(auStack_20,*(undefined4 *)(iVar4 + 0x10)), iVar4 == 0)) ||
       (iVar4 = FUN_600ecfae(param_1), iVar4 == 0)))))) {
    FUN_600e0552(6,0,0x69,DAT_600852bc,0x78);
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


