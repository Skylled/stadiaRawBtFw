// 600ea87a  FUN_600ea87a  size=12 bytes
// --- callers ---
// --- callees ---


uint FUN_600ea87a(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x1c) & 1;
  }
  return uVar1;
}


