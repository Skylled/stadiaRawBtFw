// 600dbf72  FUN_600dbf72  size=72 bytes
// --- callers ---
// --- callees ---
//   6007b59c append_buffer__6007b59c
//   6007b6c0 append_buffer__6007b6c0
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600dbf72(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x4fb8);
  append_buffer__6007b59c(param_1 + 0x500c,*(undefined4 *)(param_1 + 0x5010));
  thunk_EXT_FUN_00007d10(param_1 + 0x4fb8);
  thunk_EXT_FUN_0000b4c2(param_1 + 0x3160);
  append_buffer__6007b6c0(param_1 + 0x31b4,*(undefined4 *)(param_1 + 0x31b4));
  thunk_EXT_FUN_00007d10(param_1 + 0x3160,extraout_r1,extraout_r2,param_4);
  return;
}


