// 600eafb4  FUN_600eafb4  size=40 bytes
// --- callers ---
//   6008d730 bcm__6008d730
//   600eafdc FUN_600eafdc
//   600eb7ce FUN_600eb7ce
//   600eb19c FUN_600eb19c
//   6008da74 bcm__6008da74
//   600eb156 FUN_600eb156
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88


void FUN_600eafb4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_EXT_FUN_0000af88(param_1,param_2,0x44);
  thunk_EXT_FUN_0000af88(param_1 + 0x44,param_2 + 0x44);
  thunk_EXT_FUN_0000af88(param_1 + 0x88,param_2 + 0x88,0x44,param_4);
  return;
}


