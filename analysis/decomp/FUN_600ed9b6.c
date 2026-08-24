// 600ed9b6  FUN_600ed9b6  size=74 bytes
// --- callers ---
// --- callees ---
//   600e7474 FUN_600e7474


uint FUN_600ed9b6(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_600e7474(*(undefined4 *)(param_1 + 8));
  uVar2 = uVar1 + 1;
  iVar3 = 1;
  if (0x7f < uVar2) {
    do {
      uVar2 = uVar2 >> 8;
      iVar3 = iVar3 + 1;
    } while (uVar2 != 0);
  }
  uVar2 = uVar1 + 2 + iVar3;
  if ((uVar2 < uVar1) || (uVar1 = uVar2 * 2, uVar1 < uVar2)) {
    uVar2 = 0;
  }
  else {
    if (uVar1 < 0x80) {
      iVar3 = 1;
    }
    else {
      iVar3 = 1;
      uVar2 = uVar1;
      do {
        uVar2 = uVar2 >> 8;
        iVar3 = iVar3 + 1;
      } while (uVar2 != 0);
    }
    uVar2 = uVar1 + 1 + iVar3;
    if (uVar2 <= uVar1 && uVar1 - uVar2 != 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


