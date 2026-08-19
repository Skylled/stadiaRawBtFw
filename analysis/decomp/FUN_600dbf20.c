// 600dbf20  FUN_600dbf20  size=28 bytes
// --- callers ---
//   6007b164 FUN_6007b164
//   6007b1b8 synapse_audio_processor__6007b1b8
// --- callees ---
//   600dc30e FUN_600dc30e
//   6013d068 thunk_EXT_FUN_0000b52e


int * FUN_600dbf20(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_600dc30e(iVar1);
    thunk_EXT_FUN_0000b52e(iVar1,0x474);
  }
  return param_1;
}


