// 600e7766  FUN_600e7766  size=38 bytes
// --- callers ---
//   600e7e0e FUN_600e7e0e
//   600e7efe FUN_600e7efe
//   600e778c FUN_600e778c
// --- callees ---
//   6008b43c bcm__6008b43c
//   6008b570 bcm__6008b570


int FUN_600e7766(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = bcm__6008b570(param_2);
  if ((iVar1 == 0) || (iVar2 = bcm__6008b43c(iVar1,param_1), iVar2 == 0)) {
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 4) = param_1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return iVar1;
}


