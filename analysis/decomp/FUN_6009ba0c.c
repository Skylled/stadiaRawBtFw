// 6009ba0c  FUN_6009ba0c  size=112 bytes
// --- callers ---
//   6009ba84 FUN_6009ba84
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009b9b0 FUN_6009b9b0
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600fbc02 FUN_600fbc02


void FUN_6009ba0c(int param_1)

{
  int iVar1;
  undefined1 auStack_20 [23];
  undefined1 local_9;
  
  local_9 = 1;
  if ((param_1 == 0) || (*(short *)(param_1 + 2) != 0x2017)) {
    thunk_EXT_FUN_0000b5ba(DAT_6009ba80,0,0x30);
  }
  else {
    thunk_EXT_FUN_0000b572(DAT_6009ba7c,param_1 + 4,0x10);
    iVar1 = FUN_600fbc02(DAT_6009ba80,0x10,&local_9,1,auStack_20);
    if (iVar1 == 0) {
      thunk_EXT_FUN_0000b5ba(DAT_6009ba80,0,0x30);
    }
    else {
      FUN_6009b9b0(auStack_20);
    }
  }
  return;
}


