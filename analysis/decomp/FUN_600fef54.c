// 600fef54  FUN_600fef54  size=88 bytes
// --- callers ---
//   600c6ab0 FUN_600c6ab0
//   600959cc FUN_600959cc
// --- callees ---
//   600ab9b8 FUN_600ab9b8
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fef54(char *param_1)

{
  byte local_9;
  
  if (*param_1 != '\0') {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (param_1[(uint)local_9 * 0x20 + 4] != '\0') {
        FUN_600ab9b8(param_1[(uint)local_9 * 0x20 + 0x20]);
      }
    }
    thunk_EXT_FUN_0000b5ba(param_1,0,0x25c);
  }
  return;
}


