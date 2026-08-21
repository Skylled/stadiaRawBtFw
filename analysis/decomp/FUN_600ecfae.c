// 600ecfae  FUN_600ecfae  size=236 bytes
// --- callers ---
//   600850bc p_dsa_asn1__600850bc
//   600ed09a FUN_600ed09a
//   60090e6c bn_asn1__60090e6c
//   600ed12a FUN_600ed12a
//   60085c04 p_x25519_asn1__60085c04
//   600ed0de FUN_600ed0de
//   600ed10a FUN_600ed10a
//   60085210 p_dsa_asn1__60085210
//   600ed248 FUN_600ed248
//   600855e0 p_ed25519_asn1__600855e0
//   600911d4 FUN_600911d4
//   600859bc p_rsa_asn1__600859bc
//   600868a4 FUN_600868a4
//   600ed22a FUN_600ed22a
//   600ed266 FUN_600ed266
//   600869ec FUN_600869ec
//   60085340 FUN_60085340
//   600912a8 ec_asn1__600912a8
//   600ed1b4 FUN_600ed1b4
//   60085694 p_ed25519_asn1__60085694
//   600ecfae FUN_600ecfae
//   600917a0 ec_asn1__600917a0
//   60085918 p_rsa_asn1__60085918
//   60085b50 p_x25519_asn1__60085b50
//   60085470 FUN_60085470
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ecef4 FUN_600ecef4
//   6013d238 thunk_EXT_FUN_0000b588


undefined4 FUN_600ecfae(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  
  if (*param_1 == 0) {
    return 0;
  }
  if (*(char *)(*param_1 + 0xd) != '\0') {
    return 0;
  }
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    return 1;
  }
  bVar1 = *(byte *)(iVar2 + 0xc);
  if (bVar1 == 0) {
    return 1;
  }
  iVar5 = *(int *)(iVar2 + 8);
  iVar2 = FUN_600ecfae();
  if (iVar2 == 0) goto LAB_600ed04a;
  uVar7 = (uint)bVar1 + iVar5;
  if (uVar7 < *(uint *)(param_1[1] + 8)) goto LAB_600ed04a;
  uVar6 = *(uint *)(*param_1 + 4);
  if (uVar6 < uVar7) goto LAB_600ed04a;
  uVar6 = uVar6 - uVar7;
  if (*(char *)(param_1[1] + 0xd) != '\0') {
    if (uVar6 + 1 == 0) goto LAB_600ed04a;
    if (uVar6 < 0x1000000) {
      if (0xffff < uVar6) {
        uVar8 = 0x83;
        iVar2 = 4;
        goto LAB_600ed05c;
      }
      if (0xff < uVar6) {
        uVar8 = 0x82;
        iVar2 = 3;
        goto LAB_600ed05c;
      }
      if (0x7f < uVar6) {
        uVar8 = 0x81;
        iVar2 = 2;
        goto LAB_600ed05c;
      }
      uVar8 = (undefined1)uVar6;
      iVar2 = 1;
      uVar6 = 0;
    }
    else {
      uVar8 = 0x84;
      iVar2 = 5;
LAB_600ed05c:
      iVar5 = FUN_600ecef4(*param_1,0,iVar2 + -1,uVar6 + 1,param_4);
      if (iVar5 == 0) goto LAB_600ed04a;
      if (uVar6 != 0) {
        thunk_EXT_FUN_0000b588(*(int *)*param_1 + iVar2 + -1 + uVar7,*(int *)*param_1 + uVar7,uVar6)
        ;
      }
    }
    iVar5 = *(int *)*param_1;
    iVar4 = *(int *)(param_1[1] + 8);
    *(int *)(param_1[1] + 8) = iVar4 + 1;
    *(undefined1 *)(iVar5 + iVar4) = uVar8;
    *(char *)(param_1[1] + 0xc) = (char)iVar2 + -1;
  }
  uVar7 = (uint)*(byte *)(param_1[1] + 0xc);
  while( true ) {
    puVar3 = (undefined4 *)param_1[1];
    uVar7 = uVar7 - 1;
    if (*(byte *)(puVar3 + 3) <= uVar7) break;
    *(char *)(*(int *)*param_1 + uVar7 + puVar3[2]) = (char)uVar6;
    uVar6 = uVar6 >> 8;
  }
  if (uVar6 == 0) {
    *puVar3 = 0;
    param_1[1] = 0;
    return 1;
  }
LAB_600ed04a:
  *(undefined1 *)(*param_1 + 0xd) = 1;
  return 0;
}


