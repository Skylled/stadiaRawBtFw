// 600edffe  FUN_600edffe  size=30 bytes
// --- callers ---
//   600cc8f8 FUN_600cc8f8
// --- callees ---
//   6013d328 thunk_EXT_FUN_0000b122


void FUN_600edffe(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b122();
  if (iVar1 == 0) {
    func_0x6013d0c8(param_1,param_2,0xffffffff,param_4);
    return;
  }
  return;
}


