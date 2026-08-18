// 600ce8de  FUN_600ce8de  size=84 bytes
// --- callers ---
//   600d4724 FUN_600d4724
// --- callees ---


undefined8 FUN_600ce8de(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = (*(uint *)(param_1 + 0x44) & 0x2000) != 0;
  if (bVar2) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xffffdfff;
  }
  *(undefined4 *)(param_1 + 0x4c) = 2;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x80;
  do {
    uVar1 = 0;
    if ((*(uint *)(param_1 + 0x48) & 0x80) == 0) goto LAB_600ce906;
  } while (-1 < *(int *)(param_1 + 0x4c) << 0x1e);
  uVar1 = 1;
LAB_600ce906:
  if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
    uVar1 = 1;
  }
  if ((*(uint *)(param_1 + 0x4c) & 2) != 0) {
    uVar1 = 1;
  }
  if (bVar2) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x2000;
  }
  return CONCAT44(*(undefined4 *)(param_1 + 0x24),uVar1);
}


