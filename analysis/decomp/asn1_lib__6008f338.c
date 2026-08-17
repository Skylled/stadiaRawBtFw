// 6008f338  asn1_lib__6008f338  size=50 bytes
// src: asn1_lib.c
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
//   6008ef7c a_int__6008ef7c
//   600ecabe FUN_600ecabe
//   6008ee9c a_bitstr__6008ee9c
// --- callees ---
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: asn1_lib.c */

undefined4 * asn1_lib__6008f338(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600e092c(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_600e0552(0xc,0,0x41,DAT_6008f36c,0x184,param_2,param_3);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = param_1;
    puVar1[2] = 0;
    puVar1[3] = 0;
  }
  return puVar1;
}


