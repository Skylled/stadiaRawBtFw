// 600f6f52  FUN_600f6f52  size=128 bytes
// --- callers ---
//   600f622a FUN_600f622a
//   600ad4f4 FUN_600ad4f4
// --- callees ---
//   600f6ee2 FUN_600f6ee2


void FUN_600f6f52(int param_1,char param_2,char param_3,char param_4)

{
  byte bVar1;
  
  bVar1 = param_2 - 1;
  if (param_1 != 0) {
    if (param_4 != '\0') {
      FUN_600f6ee2(param_1);
    }
    if (param_3 == '\0') {
      if (*(char *)((uint)bVar1 + param_1 + 0x58) != '\0') {
        *(char *)((uint)bVar1 + param_1 + 0x58) = *(char *)(param_1 + (uint)bVar1 + 0x58) + -1;
      }
    }
    else {
      *(char *)((uint)bVar1 + param_1 + 0x58) = *(char *)(param_1 + (uint)bVar1 + 0x58) + '\x01';
    }
  }
  return;
}


