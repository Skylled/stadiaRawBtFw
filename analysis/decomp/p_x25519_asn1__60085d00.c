// 60085d00  p_x25519_asn1__60085d00  size=88 bytes
// src: p_x25519_asn1.c
// --- callers ---
// --- callees ---
//   600ed39c FUN_600ed39c
//   600e0552 FUN_600e0552
//   600ed398 FUN_600ed398
//   60085c98 p_x25519_asn1__60085c98
//   600ed556 FUN_600ed556


/* src: p_x25519_asn1.c */

undefined4 p_x25519_asn1__60085d00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [12];
  
  iVar1 = FUN_600ed39c(param_2);
  if (((iVar1 == 0) && (iVar1 = FUN_600ed556(param_3,auStack_18,4), iVar1 != 0)) &&
     (iVar1 = FUN_600ed39c(param_3), iVar1 == 0)) {
    uVar2 = FUN_600ed398(auStack_18);
    uVar3 = FUN_600ed39c(auStack_18);
    uVar2 = p_x25519_asn1__60085c98(param_1,uVar2,uVar3);
  }
  else {
    FUN_600e0552(6,0,0x66,DAT_60085d58,0xa0);
    uVar2 = 0;
  }
  return uVar2;
}


