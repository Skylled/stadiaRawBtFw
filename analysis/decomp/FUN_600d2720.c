// 600d2720  FUN_600d2720  size=66 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d2dba FUN_600d2dba
//   600d29b8 FUN_600d29b8
// --- callees ---


void FUN_600d2720(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  if (-1 < *(int *)(iVar2 + 0x144) << 0x10) {
    do {
      do {
        uVar1 = *(uint *)(iVar2 + 0x144) & 0x8000 | *(uint *)(iVar2 + 0x140) & 0x20;
      } while (uVar1 == 0x8000);
    } while (uVar1 == 0x20);
    *(undefined4 *)(iVar2 + 0x158) = *(undefined4 *)(param_1 + 0x2c);
    *(uint *)(iVar2 + 0x140) = *(uint *)(iVar2 + 0x140) | 0x20;
    do {
    } while (-1 < *(int *)(iVar2 + 0x144) << 0x10);
  }
  return;
}


