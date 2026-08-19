// 600deb62  FUN_600deb62  size=54 bytes
// --- callers ---
// --- callees ---


int FUN_600deb62(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = 0;
  while( true ) {
    uVar3 = param_1[1];
    if (uVar3 == 0) {
      return iVar1;
    }
    uVar5 = param_1[3];
    uVar2 = uVar5 - *param_1;
    if (uVar3 <= uVar2) {
      uVar2 = uVar3;
    }
    if (param_2 <= uVar2) {
      uVar2 = param_2;
    }
    param_2 = param_2 - uVar2;
    if (uVar2 == 0) break;
    uVar4 = *param_1 + uVar2;
    iVar1 = iVar1 + uVar2;
    param_1[1] = uVar3 - uVar2;
    *param_1 = uVar4 - uVar5 * (uVar4 / uVar5);
  }
  return iVar1;
}


