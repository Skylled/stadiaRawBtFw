// 600d5b80  FUN_600d5b80  size=26 bytes
// --- callers ---
//   600638f8 FUN_600638f8
// --- callees ---
//   6013d068 thunk_EXT_FUN_0000b52e
//   600d5b44 FUN_600d5b44


int * FUN_600d5b80(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_600d5b44(iVar1);
    thunk_EXT_FUN_0000b52e(iVar1,0x7c);
  }
  return param_1;
}


