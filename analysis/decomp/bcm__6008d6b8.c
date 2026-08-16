// 6008d6b8  bcm__6008d6b8  size=58 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
//   60085528 FUN_60085528
//   600e080c FUN_600e080c
// --- callees ---
//   600ea7e4 FUN_600ea7e4
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428


/* src: bcm.c */

bool bcm__6008d6b8(int *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  
  if (*param_1 == 0) {
    iVar1 = FUN_600ea7e4(param_2);
    *param_1 = iVar1;
    bVar2 = iVar1 != 0;
  }
  else {
    iVar1 = FUN_600eb428(*param_1);
    if (iVar1 == 0) {
      bVar2 = true;
    }
    else {
      FUN_600e0552(0xf,0,0x82,DAT_6008d6f4,0xde,param_2);
      bVar2 = false;
    }
  }
  return bVar2;
}


