// 600fc438  FUN_600fc438  size=138 bytes
// --- callers ---
//   600fbd4c FUN_600fbd4c
// --- callees ---
//   600fbc02 FUN_600fbc02
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600fc438(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 auStack_20 [20];
  undefined1 *local_c;
  
  local_c = auStack_20;
  thunk_EXT_FUN_0000b5ba(local_c,0,0x10);
  if (*(char *)(param_1 + 0x26) == '\0') {
    thunk_EXT_FUN_0000b572(local_c,param_1 + 0x5d,8);
    thunk_EXT_FUN_0000b572(local_c + 8,param_1 + 0x4d,8);
  }
  else {
    thunk_EXT_FUN_0000b572(local_c,param_1 + 0x4d,8);
    thunk_EXT_FUN_0000b572(local_c + 8,param_1 + 0x5d,8);
  }
  uVar1 = FUN_600fbc02(param_1 + 0x1b6,0x10,auStack_20,0x10,param_2);
  return uVar1;
}


