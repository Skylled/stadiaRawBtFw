// 600ddafa  FUN_600ddafa  size=48 bytes
// --- callers ---
// --- callees ---


void FUN_600ddafa(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != *(int *)(param_1 + 0x14)) {
    if (iVar1 < *(int *)(param_1 + 4) + -1) {
      iVar1 = iVar1 + 1;
    }
    else {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x18) = iVar1;
    iVar1 = *(int *)(param_1 + 0x30);
    if (iVar1 < 1) {
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    *(int *)(param_1 + 0x30) = iVar1 + -1;
    iVar1 = *(int *)(param_1 + 0x48);
    if (iVar1 < 1) {
      iVar1 = *(int *)(param_1 + 0x34);
    }
    *(int *)(param_1 + 0x48) = iVar1 + -1;
  }
  return;
}


