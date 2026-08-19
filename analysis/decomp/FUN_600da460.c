// 600da460  FUN_600da460  size=24 bytes
// --- callers ---
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   60074e6c audio_states__60074e6c


void FUN_600da460(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  audio_states__60074e6c(iVar1);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b52a(iVar1);
    return;
  }
  return;
}


