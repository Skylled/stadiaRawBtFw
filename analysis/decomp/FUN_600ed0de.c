// 600ed0de  FUN_600ed0de  size=44 bytes
// --- callers ---
//   600ed332 FUN_600ed332
//   60085340 FUN_60085340
//   600912a8 ec_asn1__600912a8
//   600850bc p_dsa_asn1__600850bc
//   60085694 p_ed25519_asn1__60085694
//   60085c04 p_x25519_asn1__60085c04
//   60085918 p_rsa_asn1__60085918
//   60085b50 p_x25519_asn1__60085b50
//   60085210 p_dsa_asn1__60085210
//   600855e0 p_ed25519_asn1__600855e0
//   600859bc p_rsa_asn1__600859bc
//   60090fd0 FUN_60090fd0
//   60085470 FUN_60085470
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ecfae FUN_600ecfae
//   600ecef4 FUN_600ecef4


undefined4 FUN_600ed0de(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r3;
  undefined4 *puVar3;
  undefined4 local_14;
  
  puVar3 = param_1;
  local_14 = param_2;
  iVar1 = FUN_600ecfae();
  uVar2 = 0;
  if ((iVar1 != 0) &&
     (iVar1 = FUN_600ecef4(*param_1,&local_14,param_3,extraout_r3,puVar3), uVar2 = 0, iVar1 != 0)) {
    if (param_3 != 0) {
      thunk_EXT_FUN_0000b572(local_14,param_2,param_3);
    }
    uVar2 = 1;
  }
  return uVar2;
}


