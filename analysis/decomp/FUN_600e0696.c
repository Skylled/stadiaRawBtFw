// 600e0696  FUN_600e0696  size=30 bytes
// --- callers ---
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600867c8 FUN_600867c8
//   600e0680 FUN_600e0680


void FUN_600e0696(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = FUN_600867c8(), iVar1 != 0)) {
    FUN_600e0680(param_1);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}


