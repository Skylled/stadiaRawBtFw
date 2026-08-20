// 600e7412  FUN_600e7412  size=34 bytes
// --- callers ---
//   600e87fa FUN_600e87fa
//   600e997c FUN_600e997c
//   600e7dc0 FUN_600e7dc0
//   600e863c FUN_600e863c
//   600eab8c FUN_600eab8c
//   600e809a FUN_600e809a
//   600e7d98 FUN_600e7d98
//   600e7ecc FUN_600e7ecc
//   6008bf44 bcm__6008bf44
//   600e98c6 FUN_600e98c6
//   600e91e6 FUN_600e91e6
// --- callees ---


void FUN_600e7412(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = 0; iVar1 != param_5; iVar1 = iVar1 + 1) {
    uVar2 = *(uint *)(param_4 + iVar1 * 4);
    *(uint *)(param_1 + iVar1 * 4) = (*(uint *)(param_3 + iVar1 * 4) ^ uVar2) & param_2 ^ uVar2;
  }
  return;
}


