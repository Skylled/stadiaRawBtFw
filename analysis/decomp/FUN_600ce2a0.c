// 600ce2a0  FUN_600ce2a0  size=38 bytes
// --- callers ---
//   60076e1c FUN_60076e1c
//   60073bf0 timer__60073bf0
//   60078340 firmware_image_upload__60078340
//   60066a74 keys__60066a74
//   600511c8 timer__600511c8
//   60058c30 FUN_60058c30
//   60066ce0 keys__60066ce0
//   60066284 keys__60066284
//   600668dc keys__600668dc
//   600669a8 keys__600669a8
//   6007b6c0 append_buffer__6007b6c0
//   600662e0 dynamic_buffer__600662e0
//   6007b694 frames__6007b694
//   600721e8 timer__600721e8
//   60074658 timer__60074658
//   60066944 keys__60066944
//   60051168 main__60051168
//   60066b40 keys__60066b40
//   60058c64 FUN_60058c64
//   60071f74 adc__60071f74
//   6007818c partition_table__6007818c
//   6007b59c append_buffer__6007b59c
//   60066ba8 keys__60066ba8
//   60058e0c timer__60058e0c
//   60066c28 keys__60066c28
// --- callees ---
//   60101b76 FUN_60101b76


undefined4 *
FUN_600ce2a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[2] = (int)param_1 + 0x16;
  param_1[3] = 0x80;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  FUN_60101b76();
  return param_1;
}


