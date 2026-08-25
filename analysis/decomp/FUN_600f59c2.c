// 600f59c2  FUN_600f59c2  size=62 bytes
// --- callers ---
//   600ab9b8 FUN_600ab9b8
// --- callees ---


undefined4 FUN_600f59c2(char param_1,int param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if (param_1 == *(char *)((uint)local_9 + param_2 + 0x1e)) break;
    local_9 = local_9 + 1;
  }
  return 1;
}


