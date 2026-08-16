// 60071f74  adc__60071f74  size=248 bytes
// src: adc.h
// --- callers ---
//   600723b4 FUN_600723b4
// --- callees ---
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740
//   60071478 FUN_60071478
//   600d9a5e FUN_600d9a5e


/* src: adc.h */

undefined4 * adc__60071f74(undefined4 *param_1,char *param_2,uint param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  undefined1 auStack_b8 [156];
  
  iVar1 = DAT_6007206c;
  *param_1 = param_2;
  iVar2 = 0x13;
  iVar4 = 0;
  do {
    iVar3 = iVar4 + iVar2 >> 1;
    pbVar6 = (byte *)(iVar1 + iVar3 * 0x20);
    uVar7 = (uint)*(byte *)(iVar1 + iVar3 * 0x20);
    if (param_3 == uVar7) goto LAB_60071fa6;
    if (param_3 < uVar7) {
      iVar2 = iVar3 + -1;
    }
    else {
      iVar4 = iVar3 + 1;
    }
  } while (iVar4 < iVar2);
  if ((param_3 < *(byte *)(iVar1 + iVar4 * 0x20)) && (iVar4 != 0)) {
    pbVar6 = (byte *)(iVar1 + (iVar4 + -1) * 0x20);
  }
  else {
    pbVar6 = (byte *)(iVar4 * 0x20 + iVar1);
  }
LAB_60071fa6:
  if (*pbVar6 != param_3) {
    pbVar6 = DAT_60072070;
  }
  FUN_60071478(param_1 + 1,*(undefined4 *)(pbVar6 + 4),*(undefined4 *)(pbVar6 + 8),
               *(undefined4 *)(pbVar6 + 0xc),*(undefined4 *)(pbVar6 + 0x10),
               *(undefined4 *)(pbVar6 + 0x14),*(undefined4 *)(pbVar6 + 0x18),
               *(undefined4 *)(pbVar6 + 0x1c),2,0,2,0,*DAT_60072074);
  uVar5 = DAT_6007207c;
  if (*param_2 == '\0') {
    uVar5 = DAT_60072078;
  }
  iVar2 = FUN_600d9a5e(uVar5,param_3);
  uVar5 = *(undefined4 *)(iVar2 + 4);
  *(undefined1 *)(param_1 + 0xe) = param_4;
  param_1[0xc] = uVar5;
  *(undefined1 *)(param_1 + 0xd) = 0;
  if ((*param_2 != '\0') && (iVar2 = FUN_600d9a5e(DAT_6007207c,param_3), DAT_60072080 == iVar2)) {
    FUN_600ce2a0(auStack_b8,DAT_60072088,DAT_60072084,0xaa);
    FUN_60101740(auStack_b8);
  }
  if ((*param_2 != '\x01') && (iVar2 = FUN_600d9a5e(DAT_60072078,param_3), DAT_6007208c == iVar2)) {
    FUN_600ce2a0(auStack_b8,DAT_60072088,DAT_60072084,0xac);
    FUN_60101740(auStack_b8);
  }
  return param_1;
}


