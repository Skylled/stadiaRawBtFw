// 600e092c  FUN_600e092c  size=18 bytes
// --- callers ---
//   600ecc40 FUN_600ecc40
//   600e0990 FUN_600e0990
//   6008b50c bcm__6008b50c
//   60085c98 p_x25519_asn1__60085c98
//   6008f0a0 a_object__6008f0a0
//   60091098 dsa__60091098
//   6008f2c0 asn1_lib__6008f2c0
//   60084bec bio__60084bec
//   60085728 p_ed25519_asn1__60085728
//   600ecf50 FUN_600ecf50
//   600e064c FUN_600e064c
//   6008ac40 bcm__6008ac40
//   600e0a70 FUN_600e0a70
//   6008ee9c a_bitstr__6008ee9c
//   600ea77a FUN_600ea77a
//   6008cbfc bcm__6008cbfc
//   600ec95a FUN_600ec95a
//   6008ef7c a_int__6008ef7c
//   6008c334 bcm__6008c334
//   600ecabe FUN_600ecabe
//   60086b08 FUN_60086b08
//   6008f338 asn1_lib__6008f338
//   6008cb7c bcm__6008cb7c
//   60090568 FUN_60090568
//   600ebf76 bcm__600ebf76
//   600ecb4a tasn_new__600ecb4a
//   60090ef4 buf__60090ef4
//   6008b384 bcm__6008b384
//   6008f0d8 a_object__6008f0d8
//   600edbc8 FUN_600edbc8
//   600ea868 bcm__600ea868
//   600ebf2c FUN_600ebf2c
//   600e093e FUN_600e093e
//   600ea6e4 FUN_600ea6e4
//   6008c834 bcm__6008c834
//   600e05bc FUN_600e05bc
//   600e02ae FUN_600e02ae
//   600e92ca FUN_600e92ca
//   6008b43c bcm__6008b43c
//   6008d2a8 bcm__6008d2a8
// --- callees ---
//   6013d038 thunk_EXT_FUN_00008832


int * FUN_600e092c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)thunk_EXT_FUN_00008832(param_1 + 8);
  piVar2 = piVar1;
  if (piVar1 != (int *)0x0) {
    piVar2 = piVar1 + 2;
    *piVar1 = param_1;
  }
  return piVar2;
}


