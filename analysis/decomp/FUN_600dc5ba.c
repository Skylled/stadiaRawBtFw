// 600dc5ba  FUN_600dc5ba  size=36 bytes
// --- callers ---
//   600dc5ee FUN_600dc5ee
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int * FUN_600dc5ba(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[1];
  for (piVar1 = (int *)*param_1; piVar2 != piVar1; piVar1 = piVar1 + 3) {
    if (*piVar1 != 0) {
      thunk_EXT_FUN_0000b52a();
    }
  }
  if (*param_1 != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


