// 600d9a00  FUN_600d9a00  size=38 bytes
// --- callers ---
// --- callees ---
//   600d4df0 FUN_600d4df0


undefined4 FUN_600d9a00(int param_1)

{
  undefined4 uVar1;
  
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if (*(char *)(param_1 + 200) != '\0') {
    uVar1 = FUN_600d4df0();
    return uVar1;
  }
  return 0;
}


