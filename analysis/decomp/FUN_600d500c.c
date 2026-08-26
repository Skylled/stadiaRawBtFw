// 600d500c  FUN_600d500c  size=54 bytes
// --- callers ---
//   600618f8 FUN_600618f8
// --- callees ---


int FUN_600d500c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 0;
  iVar3 = 0x14;
  do {
    iVar1 = iVar2 + iVar3 >> 1;
    uVar4 = (uint)*(byte *)(param_1 + iVar1 * 8);
    if (uVar4 == param_2) goto LAB_600d5022;
    if (param_2 < uVar4) {
      iVar3 = iVar1 + -1;
    }
    else {
      iVar2 = iVar1 + 1;
    }
  } while (iVar2 < iVar3);
  iVar1 = iVar2;
  if ((param_2 < *(byte *)(param_1 + iVar2 * 8)) && (iVar2 != 0)) {
    iVar1 = iVar2 + -1;
  }
LAB_600d5022:
  return param_1 + iVar1 * 8;
}


