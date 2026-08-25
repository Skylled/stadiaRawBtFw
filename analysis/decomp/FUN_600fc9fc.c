// 600fc9fc  FUN_600fc9fc  size=76 bytes
// --- callers ---
//   600fc110 FUN_600fc110
//   600c0930 FUN_600c0930
//   600fc17a FUN_600fc17a
//   600c08c4 FUN_600c08c4
//   600c07e4 FUN_600c07e4
// --- callees ---


void FUN_600fc9fc(int param_1,int param_2)

{
  undefined1 local_9;
  
  for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
    *(byte *)((uint)local_9 + param_1) =
         *(byte *)((uint)local_9 + param_2) ^ *(byte *)((uint)local_9 + param_1);
  }
  return;
}


