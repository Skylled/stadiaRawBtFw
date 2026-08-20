// 600eaf8e  FUN_600eaf8e  size=38 bytes
// --- callers ---
//   600eafdc FUN_600eafdc
//   600eb7ce FUN_600eb7ce
//   6008d2a8 bcm__6008d2a8
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90


void FUN_600eaf8e(int param_1)

{
  thunk_EXT_FUN_0000af90(param_1,0,0x44);
  thunk_EXT_FUN_0000af90(param_1 + 0x44,0);
  thunk_EXT_FUN_0000af90(param_1 + 0x88,0,0x44);
  return;
}


