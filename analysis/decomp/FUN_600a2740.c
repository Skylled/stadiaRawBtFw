// 600a2740  FUN_600a2740  size=180 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
//   600a2ab0 FUN_600a2ab0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


uint * FUN_600a2740(undefined4 param_1)

{
  uint local_18;
  uint *local_14;
  uint *local_10;
  ushort local_a;
  
  local_10 = DAT_600a27f4;
  local_14 = DAT_600a27f4;
  local_18 = 0xffffffff;
  local_a = 0;
  while( true ) {
    if (0x1d < local_a) {
      if (*(int *)(DAT_600a27f8 + 0xb34) != 0) {
        (**(code **)(DAT_600a27f8 + 0xb34))(local_14 + 2,0);
      }
      thunk_EXT_FUN_0000b5ba(local_14,0,0x30);
      thunk_EXT_FUN_0000b572((int)local_14 + 10,param_1,6);
      *(undefined1 *)((int)local_14 + 0x2e) = 1;
      return local_14;
    }
    if (*(char *)((int)local_10 + 0x2e) == '\0') break;
    if (*local_10 < local_18) {
      local_14 = local_10;
      local_18 = *local_10;
    }
    local_a = local_a + 1;
    local_10 = local_10 + 0xc;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0x30);
  thunk_EXT_FUN_0000b572((int)local_10 + 10,param_1,6);
  *(undefined1 *)((int)local_10 + 0x2e) = 1;
  return local_10;
}


