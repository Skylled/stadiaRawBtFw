// 60085c98  p_x25519_asn1__60085c98  size=100 bytes
// src: p_x25519_asn1.c
// --- callers ---
//   60085d00 p_x25519_asn1__60085d00
// --- callees ---
//   600e0904 FUN_600e0904
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552
//   600e1dde FUN_600e1dde


/* src: p_x25519_asn1.c */

undefined4 p_x25519_asn1__60085c98(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar6;
  undefined4 *puVar5;
  
  puVar3 = param_2;
  if (param_3 == 0x20) {
    iVar1 = FUN_600e092c(0x41);
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)(iVar1 + 0x20);
      puVar4 = param_2;
      do {
        puVar5 = puVar4 + 1;
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar5;
      } while (puVar5 != param_2 + 8);
      FUN_600e1dde(iVar1);
      *(undefined1 *)(iVar1 + 0x40) = 1;
      FUN_600e0904(param_1);
      *(int *)(param_1 + 8) = iVar1;
      return 1;
    }
    uVar2 = 0x41;
    uVar6 = 0x27;
  }
  else {
    uVar2 = 0x66;
    uVar6 = 0x21;
  }
  FUN_600e0552(6,0,uVar2,DAT_60085cfc,uVar6,puVar3);
  return 0;
}


