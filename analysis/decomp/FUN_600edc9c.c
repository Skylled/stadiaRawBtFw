// 600edc9c  FUN_600edc9c  size=58 bytes
// --- callers ---
//   60092128 util__60092128
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6004cb28 FUN_6004cb28


bool FUN_600edc9c(char param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  if ((param_1 == '\x03') && (iVar1 = FUN_6004cb28(param_6), iVar1 == param_3 - param_2)) {
    iVar1 = thunk_EXT_FUN_0000b554(param_5 + param_2,param_6,iVar1);
    return iVar1 == 0;
  }
  return false;
}


