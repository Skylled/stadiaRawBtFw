// 600e732a  FUN_600e732a  size=44 bytes
// --- callers ---
// --- callees ---
//   600e72fc FUN_600e72fc
//   6008b384 bcm__6008b384
//   600e6a22 FUN_600e6a22


int FUN_600e732a(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == 0) || (iVar2 = bcm__6008b384(), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar1 = FUN_600e72fc(iVar2,param_1);
    if (iVar1 == 0) {
      FUN_600e6a22(iVar2);
      iVar2 = 0;
    }
  }
  return iVar2;
}


