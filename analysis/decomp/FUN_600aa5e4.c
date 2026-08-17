// 600aa5e4  FUN_600aa5e4  size=92 bytes
// --- callers ---
//   6006d5a8 FUN_6006d5a8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600cdd2c FUN_600cdd2c


undefined4 FUN_600aa5e4(undefined1 *param_1)

{
  thunk_EXT_FUN_0000b5ba(DAT_600aa640,0,0x12);
  FUN_600cdd2c(DAT_600aa640,DAT_600aa644,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
               param_1[5]);
  return DAT_600aa640;
}


