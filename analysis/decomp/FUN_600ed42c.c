// 600ed42c  FUN_600ed42c  size=24 bytes
// --- callers ---
//   600ed75e FUN_600ed75e
// --- callees ---
//   600ed2e6 FUN_600ed2e6


bool FUN_600ed42c(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 *puStack_c;
  
  local_10 = param_1;
  puStack_c = param_2;
  iVar1 = FUN_600ed2e6(param_1,&local_10,4);
  if (iVar1 != 0) {
    *param_2 = local_10;
  }
  return iVar1 != 0;
}


