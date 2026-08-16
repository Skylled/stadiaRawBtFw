// 600d9a5e  FUN_600d9a5e  size=66 bytes
// --- callers ---
//   60071f74 adc__60071f74
// --- callees ---


byte * FUN_600d9a5e(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = 0;
  iVar4 = 0xf;
  do {
    iVar1 = iVar2 + iVar4 >> 1;
    uVar5 = (uint)*(byte *)(param_1 + iVar1 * 8);
    if (param_2 == uVar5) goto LAB_600d9a74;
    if (param_2 < uVar5) {
      iVar4 = iVar1 + -1;
    }
    else {
      iVar2 = iVar1 + 1;
    }
  } while (iVar2 < iVar4);
  iVar1 = iVar2;
  if ((param_2 < *(byte *)(param_1 + iVar2 * 8)) && (iVar2 != 0)) {
    iVar1 = iVar2 + -1;
  }
LAB_600d9a74:
  pbVar3 = (byte *)(param_1 + iVar1 * 8);
  if (*pbVar3 != param_2) {
    pbVar3 = (byte *)(param_1 + 0x80);
  }
  return pbVar3;
}


