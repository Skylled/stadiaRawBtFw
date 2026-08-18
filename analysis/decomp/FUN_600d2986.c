// 600d2986  FUN_600d2986  size=50 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d2dba FUN_600d2dba
//   600d29b8 FUN_600d29b8
// --- callees ---


void FUN_600d2986(int param_1)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = *(uint *)(param_1 + 0x144) & 0x8000 | *(uint *)(param_1 + 0x140) & 0x20;
    } while (uVar1 == 0x8000);
  } while (uVar1 == 0x20);
  *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) & 0xffffffdf;
  do {
  } while (*(int *)(param_1 + 0x144) << 0x10 < 0);
  return;
}


