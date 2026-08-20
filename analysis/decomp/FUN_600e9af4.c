// 600e9af4  FUN_600e9af4  size=40 bytes
// --- callers ---
//   6008d7ac bcm__6008d7ac
//   6008d228 bcm__6008d228
// --- callees ---
//   600e92f0 FUN_600e92f0
//   600e9a8e FUN_600e9a8e
//   600e92ca FUN_600e92ca


int FUN_600e9af4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600e92ca();
  if ((iVar1 == 0) || (iVar2 = FUN_600e9a8e(iVar1,param_1,param_2), iVar2 == 0)) {
    FUN_600e92f0(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}


