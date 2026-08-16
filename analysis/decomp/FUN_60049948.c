// 60049948  FUN_60049948  size=38 bytes
// --- callers ---
// --- callees ---
//   6004c04c thunk_FUN_600dc512


void FUN_60049948(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 local_14;
  undefined2 *puStack_10;
  
  local_14 = 0xffffffff;
  puStack_10 = param_3;
  iVar1 = thunk_FUN_600dc512(param_1,&local_14,param_3,0xffffffff,param_1);
  if (iVar1 != 0) {
    *param_2 = (undefined2)local_14;
    *param_3 = local_14._2_2_;
  }
  return;
}


