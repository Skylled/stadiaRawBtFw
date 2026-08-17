// 600859bc  p_rsa_asn1__600859bc  size=148 bytes
// src: p_rsa_asn1.c
// --- callers ---
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   600ecfae FUN_600ecfae
//   600868a4 FUN_600868a4
//   600ed12a FUN_600ed12a
//   600e0552 FUN_600e0552
//   600ed0de FUN_600ed0de


/* src: p_rsa_asn1.c */

undefined4 p_rsa_asn1__600859bc(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [20];
  
  iVar1 = FUN_600ed1b4(param_1,auStack_60,DAT_60085a50);
  if ((((((iVar1 == 0) || (iVar1 = FUN_600ed1b4(auStack_60,auStack_50,DAT_60085a50), iVar1 == 0)) ||
        (iVar1 = FUN_600ed1b4(auStack_50,auStack_40,6), iVar1 == 0)) ||
       ((iVar1 = FUN_600ed0de(auStack_40,DAT_60085a58,9), iVar1 == 0 ||
        (iVar1 = FUN_600ed1b4(auStack_50,auStack_30,5), iVar1 == 0)))) ||
      ((iVar1 = FUN_600ed1b4(auStack_60,auStack_20,3), iVar1 == 0 ||
       ((iVar1 = FUN_600ed12a(auStack_20,0), iVar1 == 0 ||
        (iVar1 = FUN_600868a4(auStack_20,*(undefined4 *)(param_2 + 8)), iVar1 == 0)))))) ||
     (iVar1 = FUN_600ecfae(param_1), iVar1 == 0)) {
    FUN_600e0552(6,0,0x69,DAT_60085a54,0x51);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


