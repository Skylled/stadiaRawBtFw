// 60085918  p_rsa_asn1__60085918  size=150 bytes
// src: p_rsa_asn1.c
// --- callers ---
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   600869ec FUN_600869ec
//   600ecfae FUN_600ecfae
//   600ed266 FUN_600ed266
//   600e0552 FUN_600e0552
//   600ed0de FUN_600ed0de


/* src: p_rsa_asn1.c */

undefined4 p_rsa_asn1__60085918(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [20];
  
  uVar3 = FUN_600ed1b4(param_1,auStack_60,DAT_600859b0);
  if (((((((int)uVar3 == 0) ||
         (iVar2 = FUN_600ed266(auStack_60,(int)((ulonglong)uVar3 >> 0x20),0,0), iVar2 == 0)) ||
        (iVar2 = FUN_600ed1b4(auStack_60,auStack_50,DAT_600859b0), iVar2 == 0)) ||
       ((iVar2 = FUN_600ed1b4(auStack_50,auStack_40,6), iVar2 == 0 ||
        (iVar2 = FUN_600ed0de(auStack_40,DAT_600859b8,9), iVar2 == 0)))) ||
      ((iVar2 = FUN_600ed1b4(auStack_50,auStack_30,5), iVar2 == 0 ||
       ((iVar2 = FUN_600ed1b4(auStack_60,auStack_20,4), iVar2 == 0 ||
        (iVar2 = FUN_600869ec(auStack_20,*(undefined4 *)(param_2 + 8)), iVar2 == 0)))))) ||
     (iVar2 = FUN_600ecfae(param_1), iVar2 == 0)) {
    FUN_600e0552(6,0,0x69,DAT_600859b4,0x7f);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


