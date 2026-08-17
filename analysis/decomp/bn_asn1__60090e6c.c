// 60090e6c  bn_asn1__60090e6c  size=130 bytes
// src: bn_asn1.c
// --- callers ---
//   60085210 p_dsa_asn1__60085210
//   600850bc p_dsa_asn1__600850bc
//   600867fc FUN_600867fc
//   60091138 FUN_60091138
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   600ece3c FUN_600ece3c
//   600ecfae FUN_600ecfae
//   600e7474 FUN_600e7474
//   600e72f2 FUN_600e72f2
//   600e7450 FUN_600e7450
//   600ed12a FUN_600ed12a
//   600e0552 FUN_600e0552


/* src: bn_asn1.c */

undefined4 bn_asn1__60090e6c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_20 [16];
  
  iVar1 = FUN_600e72f2(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_600ed1b4(param_1,auStack_20,2);
    if ((iVar1 != 0) &&
       ((uVar2 = FUN_600e7450(param_2), (uVar2 & 7) != 0 ||
        (iVar1 = FUN_600ed12a(auStack_20,0), iVar1 != 0)))) {
      uVar3 = FUN_600e7474(param_2);
      iVar1 = FUN_600ece3c(auStack_20,uVar3,param_2);
      if ((iVar1 != 0) && (iVar1 = FUN_600ecfae(param_1), iVar1 != 0)) {
        return 1;
      }
    }
    FUN_600e0552(3,0,0x76,DAT_60090ef0,0x3b);
  }
  else {
    FUN_600e0552(3,0,0x6d,DAT_60090ef0,0x30);
  }
  return 0;
}


