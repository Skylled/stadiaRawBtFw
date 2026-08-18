// 600c2d00  FUN_600c2d00  size=88 bytes
// --- callers ---
// --- callees ---
//   600a4820 FUN_600a4820


void FUN_600c2d00(int param_1)

{
  undefined1 local_124 [283];
  char local_9;
  
  local_9 = FUN_600a4820(param_1 + 8);
  if (((*(int *)(DAT_600c2d58 + 0xe8) != 0) && (local_9 != '\x01')) && (local_9 != '\0')) {
    local_124[0] = 1;
    (**(code **)(DAT_600c2d58 + 0xe8))(9,local_124);
  }
  return;
}


