// 600de836  FUN_600de836  size=36 bytes
// --- callers ---
//   600dd98e FUN_600dd98e
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600de836(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 8);
  for (piVar1 = *(int **)(param_1 + 4); piVar2 != piVar1; piVar1 = piVar1 + 3) {
    if (*piVar1 != 0) {
      thunk_EXT_FUN_0000b52a();
    }
  }
  if (*(int *)(param_1 + 4) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


