// 600f7138  FUN_600f7138  size=68 bytes
// --- callers ---
//   600ad8fc FUN_600ad8fc
// --- callees ---


undefined4 FUN_600f7138(int param_1,char param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if ((*(char *)(param_1 + 0x1a) != '\0') && (param_2 == *(char *)(param_1 + (uint)local_9)))
    break;
    local_9 = local_9 + 1;
  }
  return 1;
}


