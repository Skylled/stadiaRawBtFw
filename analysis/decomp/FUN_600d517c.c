// 600d517c  FUN_600d517c  size=70 bytes
// --- callers ---
//   60061c48 FUN_60061c48
//   60061d38 FUN_60061d38
//   60083900 FUN_60083900
// --- callees ---


int FUN_600d517c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = 0;
  iVar3 = 0x1b;
  do {
    iVar2 = iVar1 + iVar3 >> 1;
    uVar4 = (uint)*(byte *)(param_1 + iVar2 * 0x1c);
    if (uVar4 == param_2) {
      return param_1 + iVar2 * 0x1c;
    }
    if (param_2 < uVar4) {
      iVar3 = iVar2 + -1;
    }
    else {
      iVar1 = iVar2 + 1;
    }
  } while (iVar1 < iVar3);
  if ((param_2 < *(byte *)(param_1 + iVar1 * 0x1c)) && (iVar1 != 0)) {
    iVar1 = iVar1 + -1;
  }
  return iVar1 * 0x1c + param_1;
}


