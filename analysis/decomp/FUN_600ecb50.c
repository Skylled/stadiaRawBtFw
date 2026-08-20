// 600ecb50  FUN_600ecb50  size=30 bytes
// --- callers ---
// --- callees ---
//   600ecb4a tasn_new__600ecb4a


undefined4 FUN_600ecb50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_c;
  
  uStack_c = 0;
  iVar1 = tasn_new__600ecb4a(&uStack_c,param_1,param_3,&uStack_c,param_1);
  if (iVar1 < 1) {
    uStack_c = 0;
  }
  return uStack_c;
}


