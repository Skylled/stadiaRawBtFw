// 600e093e  FUN_600e093e  size=56 bytes
// --- callers ---
//   600e7718 FUN_600e7718
//   600ecea6 FUN_600ecea6
//   600e0bfe FUN_600e0bfe
//   6008f2c0 asn1_lib__6008f2c0
//   600e0be8 FUN_600e0be8
//   600e05bc FUN_600e05bc
//   60090f24 buf__60090f24
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c


int FUN_600e093e(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    iVar1 = FUN_600e092c(param_2,param_2,param_3,param_4);
    return iVar1;
  }
  uVar2 = *(uint *)(param_1 + -8);
  iVar1 = FUN_600e092c(param_2);
  if (iVar1 != 0) {
    if (param_2 <= uVar2) {
      uVar2 = param_2;
    }
    thunk_EXT_FUN_0000b572(iVar1,param_1,uVar2);
    thunk_EXT_FUN_0000ac5e(param_1);
  }
  return iVar1;
}


