// 60085b50  p_x25519_asn1__60085b50  size=168 bytes
// src: p_x25519_asn1.c
// --- callers ---
// --- callees ---
//   600ed0de FUN_600ed0de
//   600ed1b4 FUN_600ed1b4
//   600e0552 FUN_600e0552
//   600ecfae FUN_600ecfae
//   600ed266 FUN_600ed266


/* src: p_x25519_asn1.c */

undefined4 p_x25519_asn1__60085b50(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  
  iVar3 = *(int *)(param_2 + 8);
  if (*(char *)(iVar3 + 0x40) == '\0') {
    uVar2 = 0x82;
    uVar5 = 0xaa;
  }
  else {
    uVar4 = FUN_600ed1b4(param_1,auStack_60,DAT_60085bfc);
    if (((((((int)uVar4 != 0) &&
           (iVar1 = FUN_600ed266(auStack_60,(int)((ulonglong)uVar4 >> 0x20),0,0), iVar1 != 0)) &&
          (iVar1 = FUN_600ed1b4(auStack_60,auStack_50,DAT_60085bfc), iVar1 != 0)) &&
         ((iVar1 = FUN_600ed1b4(auStack_50,auStack_40,6), iVar1 != 0 &&
          (iVar1 = FUN_600ed0de(auStack_40,DAT_60085c00,3), iVar1 != 0)))) &&
        ((iVar1 = FUN_600ed1b4(auStack_60,auStack_30,4), iVar1 != 0 &&
         ((iVar1 = FUN_600ed1b4(auStack_30,auStack_20,4), iVar1 != 0 &&
          (iVar3 = FUN_600ed0de(auStack_20,iVar3 + 0x20), iVar3 != 0)))))) &&
       (iVar3 = FUN_600ecfae(param_1), iVar3 != 0)) {
      return 1;
    }
    uVar2 = 0x69;
    uVar5 = 0xbb;
  }
  FUN_600e0552(6,0,uVar2,DAT_60085bf8,uVar5);
  return 0;
}


