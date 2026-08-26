// 600d69f8  FUN_600d69f8  size=68 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d69f8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = *(int *)(param_1 + 0x74);
  iVar5 = 9;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + iVar5 >> 1;
    uVar6 = (uint)*(byte *)(iVar2 + iVar1 * 8);
    if (param_2 == uVar6) goto LAB_600d6a10;
    if (param_2 < uVar6) {
      iVar5 = iVar1 + -1;
    }
    else {
      iVar3 = iVar1 + 1;
    }
  } while (iVar3 < iVar5);
  iVar1 = iVar3;
  if ((param_2 < *(byte *)(iVar2 + iVar3 * 8)) && (iVar3 != 0)) {
    iVar1 = iVar3 + -1;
  }
LAB_600d6a10:
  pbVar4 = (byte *)(iVar2 + iVar1 * 8);
  if (*pbVar4 != param_2) {
    pbVar4 = (byte *)(iVar2 + 0x50);
  }
  return *(undefined4 *)(pbVar4 + 4);
}


