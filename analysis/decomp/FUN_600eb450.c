// 600eb450  FUN_600eb450  size=44 bytes
// --- callers ---
//   6008dab0 bcm__6008dab0
// --- callees ---
//   600ea802 FUN_600ea802
//   6008da74 bcm__6008da74
//   6008d2a8 bcm__6008d2a8


int FUN_600eb450(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = bcm__6008d2a8(param_2);
    if ((iVar1 == 0) || (iVar2 = bcm__6008da74(iVar1,param_1), iVar2 == 0)) {
      FUN_600ea802(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}


