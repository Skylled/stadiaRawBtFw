// 6008ccb4  bcm__6008ccb4  size=40 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
//   6008db50 bcm__6008db50
// --- callees ---
//   600e0552 FUN_600e0552


/* src: bcm.c */

bool bcm__6008ccb4(int *param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    (**(code **)(*param_1 + 0x1c))();
  }
  else {
    FUN_600e0552(0xf,0,0x43,DAT_6008ccdc,0x3ca,param_2);
  }
  return param_3 != 0;
}


