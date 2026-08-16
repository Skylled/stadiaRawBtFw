// 6004bde6  FUN_6004bde6  size=26 bytes
// --- callers ---
// --- callees ---
//   6004c174 thunk_FUN_600cdbbc


int FUN_6004bde6(int param_1)

{
  int iVar1;
  
  iVar1 = thunk_FUN_600cdbbc();
  if ((*(byte *)(iVar1 + param_1 + 1) & 3) == 1) {
    param_1 = param_1 + 0x20;
  }
  return param_1;
}


