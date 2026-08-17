// 6009ba84  FUN_6009ba84  size=94 bytes
// --- callers ---
// --- callees ---
//   6009ba0c FUN_6009ba0c
//   600fbc02 FUN_600fbc02
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009ba84(int param_1)

{
  undefined1 auStack_20 [23];
  undefined1 local_9;
  
  local_9 = 3;
  if ((param_1 == 0) || (*(short *)(param_1 + 2) != 0x2018)) {
    thunk_EXT_FUN_0000b5ba(DAT_6009bae8,0,0x30);
  }
  else {
    thunk_EXT_FUN_0000b572(DAT_6009bae4,param_1 + 4,8);
    FUN_600fbc02(DAT_6009bae8,0x10,&local_9,1,auStack_20);
    FUN_6009ba0c(auStack_20);
  }
  return;
}


