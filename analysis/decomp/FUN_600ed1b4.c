// 600ed1b4  FUN_600ed1b4  size=118 bytes
// --- callers ---
//   600ed266 FUN_600ed266
//   600869ec FUN_600869ec
//   60085340 FUN_60085340
//   600912a8 ec_asn1__600912a8
//   600850bc p_dsa_asn1__600850bc
//   60085694 p_ed25519_asn1__60085694
//   60090e6c bn_asn1__60090e6c
//   600917a0 ec_asn1__600917a0
//   60085c04 p_x25519_asn1__60085c04
//   60085918 p_rsa_asn1__60085918
//   60085b50 p_x25519_asn1__60085b50
//   60085210 p_dsa_asn1__60085210
//   600855e0 p_ed25519_asn1__600855e0
//   600911d4 FUN_600911d4
//   600859bc p_rsa_asn1__600859bc
//   600868a4 FUN_600868a4
//   60085470 FUN_60085470
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ed12a FUN_600ed12a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ed148 FUN_600ed148


undefined4 FUN_600ed1b4(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_600ecfae();
  if (iVar1 != 0) {
    uVar2 = param_3 >> 0x18 & 0xe0;
    if ((param_3 & 0x1fffffff) < 0x1f) {
      iVar1 = FUN_600ed12a(param_1,uVar2 | param_3 & 0xff);
    }
    else {
      uVar4 = FUN_600ed12a(param_1,uVar2 | 0x1f);
      if ((int)uVar4 == 0) {
        return 0;
      }
      iVar1 = FUN_600ed148(param_1,(int)((ulonglong)uVar4 >> 0x20),param_3 & 0x1fffffff,0);
    }
    if (iVar1 != 0) {
      iVar3 = *(int *)(*param_1 + 4);
      iVar1 = FUN_600ed12a(param_1,0);
      if (iVar1 != 0) {
        thunk_EXT_FUN_0000b5ba(param_2,0,0x10);
        *param_2 = *param_1;
        *(undefined1 *)((int)param_2 + 0xe) = 1;
        param_1[1] = (int)param_2;
        param_2[2] = iVar3;
        *(undefined2 *)(param_2 + 3) = 0x101;
        return 1;
      }
    }
  }
  return 0;
}


