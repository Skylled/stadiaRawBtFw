// 600ed12a  FUN_600ed12a  size=30 bytes
// --- callers ---
//   600ed266 FUN_600ed266
//   600ed1b4 FUN_600ed1b4
//   60085694 p_ed25519_asn1__60085694
//   60090e6c bn_asn1__60090e6c
//   600917a0 ec_asn1__600917a0
//   60085c04 p_x25519_asn1__60085c04
//   600ed828 FUN_600ed828
//   60085210 p_dsa_asn1__60085210
//   60091ddc FUN_60091ddc
//   600ed794 FUN_600ed794
//   600859bc p_rsa_asn1__600859bc
//   600ed148 FUN_600ed148
//   60090fd0 FUN_60090fd0
//   60085470 FUN_60085470
// --- callees ---
//   600ecfae FUN_600ecfae
//   600ecf0a FUN_600ecf0a


void FUN_600ed12a(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  uVar1 = FUN_600ecfae();
  if ((int)uVar1 != 0) {
    FUN_600ecf0a(*param_1,(int)((ulonglong)uVar1 >> 0x20),param_2,0,1,uVar2,param_3);
  }
  return;
}


