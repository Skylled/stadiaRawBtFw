// 600fd630  FUN_600fd630  size=122 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
//   600c60fc FUN_600c60fc
// --- callees ---
//   600fd6d6 FUN_600fd6d6
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fd630(char *param_1)

{
  byte local_9;
  
  if (*param_1 == '\x02') {
    for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
      if (param_1[(uint)local_9 * 0x10c + 100] != '\0') {
        *param_1 = '\x03';
        FUN_600fd6d6(param_1,param_1 + (uint)local_9 * 0x10c + 0x60);
      }
    }
    if (*param_1 != '\x03') {
      *param_1 = '\0';
      thunk_EXT_FUN_0000b5ba(param_1,0,0x5c8);
    }
  }
  return;
}


