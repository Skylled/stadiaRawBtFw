// 6004780c  FUN_6004780c  size=34 bytes
// --- callers ---
//   60047834 queue__60047834
// --- callees ---


void FUN_6004780c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_60047830 + iVar2 * 8;
    if (*(int *)(iVar1 + 4) == param_1) {
      *(undefined4 *)(DAT_60047830 + iVar2 * 8) = 0;
      *(undefined4 *)(iVar1 + 4) = 0;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  return;
}


