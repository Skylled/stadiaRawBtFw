// 600da478  FUN_600da478  size=18 bytes
// --- callers ---
//   60079bf4 FUN_60079bf4
//   60074ef4 FUN_60074ef4
//   6007f540 receiver__6007f540
//   60079c50 FUN_60079c50
//   6007edf4 recording_pipeline__6007edf4
//   60074f70 audio_states__60074f70
//   6007f510 FUN_6007f510
//   60075088 audio_states__60075088
//   60079d28 audio_tasks__60079d28
// --- callees ---
//   60074ec8 FUN_60074ec8


int * FUN_600da478(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_60074ec8();
  }
  return param_1;
}


