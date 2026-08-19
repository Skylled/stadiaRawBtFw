// 600e0990  FUN_600e0990  size=38 bytes
// --- callers ---
// --- callees ---
//   6004cb28 FUN_6004cb28
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600e092c FUN_600e092c


int FUN_600e0990(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar1 = FUN_6004cb28();
    iVar2 = FUN_600e092c(iVar1 + 1);
    if (iVar2 != 0) {
      thunk_EXT_FUN_0000b572(iVar2,param_1,iVar1 + 1);
    }
  }
  return iVar2;
}


