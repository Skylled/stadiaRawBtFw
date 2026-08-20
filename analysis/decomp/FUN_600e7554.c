// 600e7554  FUN_600e7554  size=52 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008ce70 bcm__6008ce70
//   600eb400 FUN_600eb400
//   6008d120 bcm__6008d120
//   6008d7ac bcm__6008d7ac
//   6008e700 bcm__6008e700
//   6008eb24 bcm__6008eb24
//   600e94ca FUN_600e94ca
// --- callees ---
//   600e7548 FUN_600e7548


int FUN_600e7554(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if (param_2 != 0) {
      iVar1 = 1;
    }
  }
  else if (param_2 == 0) {
    iVar1 = -1;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 == *(int *)(param_2 + 0xc)) {
      iVar1 = FUN_600e7548();
      if (iVar2 != 0) {
        iVar1 = -iVar1;
      }
    }
    else if (iVar2 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


