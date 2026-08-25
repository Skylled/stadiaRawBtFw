// 600fbc9a  FUN_600fbc9a  size=94 bytes
// --- callers ---
//   600c0930 FUN_600c0930
// --- callees ---


void FUN_600fbc9a(int param_1,int param_2)

{
  byte bVar1;
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = 0;
  for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
    bVar1 = *(byte *)((uint)local_9 + param_1);
    *(byte *)((uint)local_9 + param_2) = local_a | *(char *)((uint)local_9 + param_1) << 1;
    local_a = bVar1 >> 7;
  }
  return;
}


