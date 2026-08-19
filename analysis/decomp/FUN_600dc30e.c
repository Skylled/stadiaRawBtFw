// 600dc30e  FUN_600dc30e  size=100 bytes
// --- callers ---
//   600dbf20 FUN_600dbf20
//   6007b1b8 synapse_audio_processor__6007b1b8
// --- callees ---
//   600dc292 FUN_600dc292
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dc5ee FUN_600dc5ee
//   6013d068 thunk_EXT_FUN_0000b52e


int FUN_600dc30e(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x464) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_600dc292(param_1 + 0x1d8);
  iVar1 = *(int *)(param_1 + 0x1d4);
  if (iVar1 != 0) {
    piVar3 = *(int **)(iVar1 + 0x10);
    for (piVar2 = *(int **)(iVar1 + 0xc); piVar3 != piVar2; piVar2 = piVar2 + 3) {
      if (*piVar2 != 0) {
        thunk_EXT_FUN_0000b52a();
      }
    }
    if (*(int *)(iVar1 + 0xc) != 0) {
      thunk_EXT_FUN_0000b52a();
    }
    thunk_EXT_FUN_0000b52e(iVar1,0x18);
  }
  if (*(int *)(param_1 + 0x1c8) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  iVar1 = *(int *)(param_1 + 0x1b8);
  if (iVar1 != 0) {
    FUN_600dc5ee(iVar1);
    thunk_EXT_FUN_0000b52e(iVar1,0x13d4);
  }
  return param_1;
}


