// 600f0f48  FUN_600f0f48  size=70 bytes
// --- callers ---
//   600a44bc FUN_600a44bc
//   600f0f8e FUN_600f0f8e
//   6009be40 FUN_6009be40
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600f0f48(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined2 local_c;
  
  local_10 = 0;
  local_c = 0;
  iVar1 = thunk_EXT_FUN_0000b554(param_1 + 100,&local_10,6);
  if (iVar1 == 0) {
    thunk_EXT_FUN_0000b572(param_1 + 100,param_2,6);
  }
  return iVar1 == 0;
}


