// 6009b914  FUN_6009b914  size=66 bytes
// --- callers ---
// --- callees ---
//   6009b8b4 FUN_6009b8b4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009b914(int param_1)

{
  if ((param_1 == 0) || (*(short *)(param_1 + 2) != 0x2018)) {
    thunk_EXT_FUN_0000b5ba(DAT_6009b95c,0,0x10);
  }
  else {
    thunk_EXT_FUN_0000b572(DAT_6009b958,param_1 + 4,8);
    FUN_6009b8b4(2);
  }
  return;
}


