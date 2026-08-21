// 600ed266  FUN_600ed266  size=128 bytes
// --- callers ---
//   600869ec FUN_600869ec
//   60085340 FUN_60085340
//   600850bc p_dsa_asn1__600850bc
//   600855e0 p_ed25519_asn1__600855e0
//   600917a0 ec_asn1__600917a0
//   60085918 p_rsa_asn1__60085918
//   60085b50 p_x25519_asn1__60085b50
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   600ecfae FUN_600ecfae
//   600ed12a FUN_600ed12a


undefined4 FUN_600ed266(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  
  uStack_28 = param_1;
  uStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  iVar1 = FUN_600ed1b4(param_1,&uStack_28,2);
  if (iVar1 != 0) {
    uVar5 = 0x38;
    bVar3 = false;
    do {
      uVar4 = param_3 >> (uVar5 & 0xff) | param_4 << (0x20 - uVar5 & 0xff) |
              param_4 >> (uVar5 - 0x20 & 0xff);
      uVar6 = uVar4 & 0xff;
      if (bVar3) {
LAB_600ed2a4:
        iVar1 = FUN_600ed12a(&uStack_28,uVar6);
        if (iVar1 == 0) {
          return 0;
        }
        bVar3 = true;
      }
      else if (uVar6 != 0) {
        if (((int)(uVar4 << 0x18) < 0) && (iVar1 = FUN_600ed12a(&uStack_28), iVar1 == 0)) {
          return 0;
        }
        goto LAB_600ed2a4;
      }
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0xfffffff8);
    if ((bVar3) || (iVar1 = FUN_600ed12a(&uStack_28), iVar1 != 0)) {
      uVar2 = FUN_600ecfae(param_1);
      return uVar2;
    }
  }
  return 0;
}


