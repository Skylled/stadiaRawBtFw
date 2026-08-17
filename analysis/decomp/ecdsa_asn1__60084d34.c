// 60084d34  ecdsa_asn1__60084d34  size=92 bytes
// src: ecdsa_asn1.c
// --- callers ---
// --- callees ---
//   600ea77a FUN_600ea77a
//   600ed556 FUN_600ed556
//   60090dd8 bn_asn1__60090dd8
//   600ed39c FUN_600ed39c
//   600e0552 FUN_600e0552
//   600ea75c FUN_600ea75c


/* src: ecdsa_asn1.c */

undefined4 * ecdsa_asn1__60084d34(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  puVar1 = (undefined4 *)FUN_600ea77a();
  if ((puVar1 != (undefined4 *)0x0) &&
     ((((iVar2 = FUN_600ed556(param_1,auStack_18,DAT_60084d90), iVar2 == 0 ||
        (iVar2 = bn_asn1__60090dd8(auStack_18,*puVar1), iVar2 == 0)) ||
       (iVar2 = bn_asn1__60090dd8(auStack_18,puVar1[1]), iVar2 == 0)) ||
      (iVar2 = FUN_600ed39c(auStack_18), iVar2 != 0)))) {
    FUN_600e0552(0x1a,0,100,DAT_60084d94,0xa2);
    FUN_600ea75c(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}


