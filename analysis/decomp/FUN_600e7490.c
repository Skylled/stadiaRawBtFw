// 600e7490  FUN_600e7490  size=116 bytes
// --- callers ---
//   60090dd8 bn_asn1__60090dd8
//   60091580 ec_asn1__60091580
//   6008d7ac bcm__6008d7ac
//   6008e910 bcm__6008e910
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e6a22 FUN_600e6a22
//   6008b384 bcm__6008b384


int * FUN_600e7490(byte *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  
  if (param_3 == (int *)0x0) {
    param_3 = (int *)bcm__6008b384();
    piVar6 = param_3;
    if (param_3 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  else {
    piVar6 = (int *)0x0;
  }
  if (param_2 != 0) {
    iVar4 = (param_2 - 1U >> 2) + 1;
    iVar1 = bcm__6008b43c(param_3,iVar4);
    if (iVar1 == 0) {
      if (piVar6 != (int *)0x0) {
        FUN_600e6a22(piVar6);
      }
      return (int *)0x0;
    }
    uVar2 = 0;
    uVar3 = param_2 - 1U & 3;
    param_3[1] = iVar4;
    param_3[3] = 0;
    pbVar5 = param_1;
    while (pbVar5 != param_1 + param_2) {
      uVar2 = (uint)*pbVar5 | uVar2 << 8;
      if (uVar3 == 0) {
        iVar4 = iVar4 + -1;
        *(uint *)(*param_3 + iVar4 * 4) = uVar2;
        uVar3 = 3;
        uVar2 = 0;
        pbVar5 = pbVar5 + 1;
      }
      else {
        uVar3 = uVar3 - 1;
        pbVar5 = pbVar5 + 1;
      }
    }
    return param_3;
  }
  param_3[1] = 0;
  return param_3;
}


