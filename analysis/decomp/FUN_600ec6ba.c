// 600ec6ba  FUN_600ec6ba  size=66 bytes
// --- callers ---
//   60090568 FUN_60090568
//   600ec8b4 FUN_600ec8b4
//   600902e4 FUN_600902e4
// --- callees ---


int FUN_600ec6ba(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (-1 < param_2) {
    iVar1 = 1;
    if (0x1e < param_3) {
      do {
        param_3 = param_3 >> 7;
        iVar1 = iVar1 + 1;
      } while (param_3 != 0);
    }
    if (param_1 == 2) {
      iVar1 = iVar1 + 3;
    }
    else {
      iVar1 = iVar1 + 1;
      iVar2 = param_2;
      if (0x7f < param_2) {
        do {
          iVar2 = iVar2 >> 8;
          iVar1 = iVar1 + 1;
        } while (iVar2 != 0);
      }
    }
    if (iVar1 < 0x7fffffff - param_2) {
      return iVar1 + param_2;
    }
  }
  return -1;
}


