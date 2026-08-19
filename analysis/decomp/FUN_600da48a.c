// 600da48a  FUN_600da48a  size=34 bytes
// --- callers ---
//   60083080 remote_device_db__60083080
//   6008318c remote_device_db__6008318c
//   600deaea FUN_600deaea
//   6007edf4 recording_pipeline__6007edf4
//   60075088 audio_states__60075088
// --- callees ---
//   60074ec8 FUN_60074ec8
//   6005c44c FUN_6005c44c


int * FUN_600da48a(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (*param_1 != iVar1) {
    if (iVar1 != 0) {
      FUN_60074ec8(iVar1);
    }
    if (*param_1 != 0) {
      FUN_6005c44c();
    }
    *param_1 = iVar1;
  }
  return param_1;
}


