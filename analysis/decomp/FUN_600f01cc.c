// 600f01cc  FUN_600f01cc  size=134 bytes
// --- callers ---
//   60098f88 FUN_60098f88
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600f01cc(int param_1,undefined4 param_2,undefined1 *param_3)

{
  char cVar1;
  undefined1 local_9;
  
  local_9 = 1;
  if (param_1 == 0) {
    local_9 = 0;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x7a);
    if (cVar1 == '\x01') {
      thunk_EXT_FUN_0000b572(param_2,param_1 + 0x74,6);
      *param_3 = 1;
    }
    else if (cVar1 == '\x02') {
      thunk_EXT_FUN_0000b572(param_2,param_1 + 0x6c,6);
      *param_3 = *(undefined1 *)(param_1 + 0x6b);
    }
    else if (cVar1 == '\0') {
      thunk_EXT_FUN_0000b572(param_2,param_1 + 0x10,6);
      *param_3 = *(undefined1 *)(param_1 + 0x6a);
    }
    else {
      local_9 = 0;
    }
  }
  return local_9;
}


