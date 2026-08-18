// 600d2a3c  FUN_600d2a3c  size=50 bytes
// --- callers ---
// --- callees ---


void FUN_600d2a3c(int param_1)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = *(uint *)(param_1 + 0x144) & 0x4000 | *(uint *)(param_1 + 0x140) & 0x10;
    } while (uVar1 == 0x4000);
  } while (uVar1 == 0x10);
  *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) & 0xffffffef;
  do {
  } while (*(int *)(param_1 + 0x144) << 0x11 < 0);
  return;
}


