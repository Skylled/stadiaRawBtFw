// 600fc9c4  FUN_600fc9c4  size=56 bytes
// --- callers ---
//   600fc2c6 FUN_600fc2c6
//   600fc302 FUN_600fc302
//   600fbd4c FUN_600fbd4c
// --- callees ---


void FUN_600fc9c4(byte param_1,int param_2)

{
  undefined1 local_9;
  
  local_9 = param_1;
  if (param_1 < 0x10) {
    for (; local_9 < 0x10; local_9 = local_9 + 1) {
      *(undefined1 *)((uint)local_9 + param_2) = 0;
    }
  }
  return;
}


