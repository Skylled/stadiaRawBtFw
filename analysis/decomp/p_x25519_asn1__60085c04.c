// 60085c04  p_x25519_asn1__60085c04  size=136 bytes
// src: p_x25519_asn1.c
// --- callers ---
// --- callees ---
//   600ed0de FUN_600ed0de
//   600ed1b4 FUN_600ed1b4
//   600e0552 FUN_600e0552
//   600ed12a FUN_600ed12a
//   600ecfae FUN_600ecfae


/* src: p_x25519_asn1.c */

undefined4 p_x25519_asn1__60085c04(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [20];
  
  uVar2 = *(undefined4 *)(param_2 + 8);
  iVar1 = FUN_600ed1b4(param_1,auStack_50,DAT_60085c8c);
  if (((((iVar1 == 0) || (iVar1 = FUN_600ed1b4(auStack_50,auStack_40,DAT_60085c8c), iVar1 == 0)) ||
       (iVar1 = FUN_600ed1b4(auStack_40,auStack_30,6), iVar1 == 0)) ||
      ((iVar1 = FUN_600ed0de(auStack_30,DAT_60085c94,3), iVar1 == 0 ||
       (iVar1 = FUN_600ed1b4(auStack_50,auStack_20,3), iVar1 == 0)))) ||
     ((iVar1 = FUN_600ed12a(auStack_20,0), iVar1 == 0 ||
      ((iVar1 = FUN_600ed0de(auStack_20,uVar2,0x20), iVar1 == 0 ||
       (iVar1 = FUN_600ecfae(param_1), iVar1 == 0)))))) {
    FUN_600e0552(6,0,0x69,DAT_60085c90,0x8a);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


