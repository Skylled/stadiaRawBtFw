// 600c5c20  FUN_600c5c20  size=104 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c5c20(byte param_1,undefined4 param_2)

{
  undefined1 auStack_124 [283];
  undefined1 local_9;
  
  if ((param_1 - 1 < 2) && (*(int *)(DAT_600c5c88 + 0xe8) != 0)) {
    thunk_EXT_FUN_0000b572(auStack_124,param_2,0x30);
    if (param_1 == 1) {
      local_9 = 0x14;
    }
    else {
      local_9 = 0x15;
    }
    (**(code **)(DAT_600c5c88 + 0xe8))(local_9,auStack_124);
  }
  return;
}


