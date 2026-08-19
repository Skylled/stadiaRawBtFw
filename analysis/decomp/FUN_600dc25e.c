// 600dc25e  FUN_600dc25e  size=52 bytes
// --- callers ---
//   6007bb4c FUN_6007bb4c
//   600dc292 FUN_600dc292
// --- callees ---
//   600dc248 FUN_600dc248
//   6013d310 thunk_EXT_FUN_0000b52a
//   6013d068 thunk_EXT_FUN_0000b52e


void FUN_600dc25e(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[1];
  for (piVar1 = (int *)*param_1; piVar2 != piVar1; piVar1 = piVar1 + 3) {
    FUN_600dc248(*piVar1,piVar1[1]);
    if (*piVar1 != 0) {
      thunk_EXT_FUN_0000b52a();
    }
  }
  if (*param_1 != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  thunk_EXT_FUN_0000b52e(param_1,0x10);
  return;
}


