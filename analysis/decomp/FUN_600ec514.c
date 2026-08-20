// 600ec514  FUN_600ec514  size=112 bytes
// --- callers ---
//   60090cbc tasn_utl__60090cbc
// --- callees ---


uint FUN_600ec514(int *param_1)

{
  bool bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[1] == 0x102) {
    bVar1 = true;
  }
  else {
    if (param_1[1] != 2) {
      return 0xffffffff;
    }
    bVar1 = false;
  }
  if (*param_1 < 9) {
    pbVar2 = (byte *)param_1[2];
    if (pbVar2 == (byte *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      uVar5 = 0;
      for (pbVar3 = pbVar2; (int)pbVar3 - (int)pbVar2 < *param_1; pbVar3 = pbVar3 + 1) {
        uVar5 = uVar5 << 8 | uVar4 >> 0x18;
        uVar4 = (uint)*pbVar3 | uVar4 << 8;
      }
      if (uVar5 != 0 || 0x7fffffff < uVar4) {
        return 0xffffffff;
      }
    }
    if (bVar1) {
      return -uVar4;
    }
    return uVar4;
  }
  return 0xffffffff;
}


