// 600f6fd2  FUN_600f6fd2  size=128 bytes
// --- callers ---
//   600f622a FUN_600f622a
// --- callees ---
//   600f6f1a FUN_600f6f1a


void FUN_600f6fd2(int param_1,char param_2,char param_3,char param_4)

{
  byte bVar1;
  
  bVar1 = param_2 - 1;
  if (param_1 != 0) {
    if (param_4 != '\0') {
      FUN_600f6f1a(param_1);
    }
    if (param_3 == '\0') {
      if (*(char *)((uint)bVar1 + param_1 + 0x8c) != '\0') {
        *(char *)((uint)bVar1 + param_1 + 0x8c) = *(char *)(param_1 + (uint)bVar1 + 0x8c) + -1;
      }
    }
    else {
      *(char *)((uint)bVar1 + param_1 + 0x8c) = *(char *)(param_1 + (uint)bVar1 + 0x8c) + '\x01';
    }
  }
  return;
}


