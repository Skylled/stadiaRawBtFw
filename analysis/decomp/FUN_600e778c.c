// 600e778c  FUN_600e778c  size=52 bytes
// --- callers ---
//   600e7e0e FUN_600e7e0e
//   600e7efe FUN_600e7efe
// --- callees ---
//   600e7766 FUN_600e7766
//   6008b4b8 bcm__6008b4b8
//   600e72fc FUN_600e72fc


int FUN_600e778c(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 4) < param_2) &&
     (((iVar1 = FUN_600e7766(param_2,param_3), iVar1 == 0 ||
       (iVar2 = FUN_600e72fc(iVar1,param_1), iVar2 == 0)) ||
      (iVar2 = bcm__6008b4b8(iVar1,param_2), param_1 = iVar1, iVar2 == 0)))) {
    param_1 = 0;
  }
  return param_1;
}


