// 6008d2a8  bcm__6008d2a8  size=82 bytes
// src: bcm.c
// --- callers ---
//   6008d7ac bcm__6008d7ac
//   60091580 ec_asn1__60091580
//   600eb450 FUN_600eb450
//   6008db50 bcm__6008db50
//   60085528 FUN_60085528
// --- callees ---
//   600ea7e4 FUN_600ea7e4
//   600e0552 FUN_600e0552
//   600e092c FUN_600e092c
//   600eaf8e FUN_600eaf8e


/* src: bcm.c */

undefined4 * bcm__6008d2a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_600e0552(0xf,0,0x43,DAT_6008d2fc,0x2a9,param_2,param_3);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_600e092c(0xd0);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_600e0552(0xf,0,0x41,DAT_6008d2fc,0x2af,param_2,param_3);
    }
    else {
      uVar2 = FUN_600ea7e4(param_1);
      *puVar1 = uVar2;
      FUN_600eaf8e(puVar1 + 1);
    }
  }
  return puVar1;
}


