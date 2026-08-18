// 600aff18  FUN_600aff18  size=106 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
// --- callees ---


undefined1 FUN_600aff18(int param_1,byte param_2,byte *param_3,undefined1 *param_4)

{
  byte local_9;
  
  local_9 = param_2;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if (*(char *)((uint)local_9 + param_1 + 0x1e) != '\0') break;
    local_9 = local_9 + 1;
  }
  *param_4 = *(undefined1 *)(*(int *)(DAT_600aff84 + (uint)local_9 * 0x60 + 0x124c) + 0x2c);
  *param_3 = local_9;
  return 1;
}


