// 6008cfd4  bcm__6008cfd4  size=100 bytes
// src: bcm.c
// --- callers ---
//   60091580 ec_asn1__60091580
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e0552 FUN_600e0552
//   6008ac40 bcm__6008ac40
//   6008cf98 bcm__6008cf98


/* src: bcm.c */

undefined4 bcm__6008cfd4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*param_1 == 0) {
    FUN_600e0552(0xf,0,0x72,DAT_6008d038,0xf2,param_2,param_3);
    uVar3 = 0;
  }
  else {
    uVar3 = param_2;
    iVar1 = bcm__6008ac40(*param_1 + 0xc);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      iVar2 = bcm__6008cf98(*param_1,iVar1 + 0x14,param_2);
      if (iVar2 == 0) {
        FUN_600e0552(0xf,0,0x7d,DAT_6008d038,0xfb,uVar3,param_3);
        thunk_EXT_FUN_0000ac5e(iVar1);
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
        thunk_EXT_FUN_0000ac5e(param_1[2]);
        param_1[2] = iVar1;
      }
    }
  }
  return uVar3;
}


