// 600eaf44  FUN_600eaf44  size=74 bytes
// --- callers ---
//   6008e700 bcm__6008e700
// --- callees ---
//   600e72fc FUN_600e72fc
//   600ea896 FUN_600ea896


bool FUN_600eaf44(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  if (((param_2 == 0) || (iVar1 = FUN_600e72fc(param_2,param_1 + 0x24), iVar1 != 0)) &&
     ((param_3 == 0 || (iVar1 = FUN_600ea896(param_1,param_3,param_1 + 0x38), iVar1 != 0)))) {
    if (param_4 == 0) {
      bVar2 = true;
    }
    else {
      iVar1 = FUN_600ea896(param_1,param_4,param_1 + 0x7c);
      bVar2 = iVar1 != 0;
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


