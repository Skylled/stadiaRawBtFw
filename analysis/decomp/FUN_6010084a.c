// 6010084a  FUN_6010084a  size=66 bytes
// --- callers ---
//   6010088c FUN_6010088c
// --- callees ---
//   6010080a FUN_6010080a


bool FUN_6010084a(undefined4 *param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  bool bVar2;
  
  iVar1 = (*param_2)();
  if ((((iVar1 == 0) || (iVar1 = (*param_2)(*param_1), iVar1 == 0)) ||
      (iVar1 = (*param_2)(param_1[0xc]), iVar1 == 0)) ||
     ((0x20 < (uint)param_1[0xb] ||
      (iVar1 = FUN_6010080a(param_1 + 1,param_2,extraout_r2,param_1[0xb],param_4), iVar1 != 0)))) {
    bVar2 = true;
  }
  else {
    iVar1 = FUN_6010080a(param_1 + 6,param_2);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


