// 600ed556  FUN_600ed556  size=52 bytes
// --- callers ---
//   600ed62e FUN_600ed62e
//   60085d00 p_x25519_asn1__60085d00
//   60091160 FUN_60091160
//   600ed5b4 FUN_600ed5b4
//   60091330 ec_asn1__60091330
//   60091580 ec_asn1__60091580
//   60091238 ec_asn1__60091238
//   60084d34 ecdsa_asn1__60084d34
//   60085780 p_ed25519_asn1__60085780
//   600868fc FUN_600868fc
//   60086824 FUN_60086824
//   60090dd8 bn_asn1__60090dd8
// --- callees ---
//   600ed380 FUN_600ed380
//   600ed548 FUN_600ed548


undefined4 FUN_600ed556(undefined4 param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  int local_1c;
  undefined1 auStack_18 [12];
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = auStack_18;
  }
  iVar1 = FUN_600ed548(param_1,param_2,&local_1c,&local_20);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (param_3 == local_1c) {
      iVar1 = FUN_600ed380(param_2,local_20);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


