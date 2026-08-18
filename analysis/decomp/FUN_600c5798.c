// 600c5798  FUN_600c5798  size=92 bytes
// --- callers ---
// --- callees ---
//   600a1174 FUN_600a1174


void FUN_600c5798(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (*(int *)(DAT_600c57f4 + 0x290) == 0) {
    *(undefined4 *)(DAT_600c57f4 + 0x290) = *(undefined4 *)(param_1 + 0x10);
    iVar2 = FUN_600a1174(param_1 + 8,DAT_600c57f8);
    if (iVar2 == 1) {
      bVar1 = true;
    }
  }
  if ((!bVar1) && (*(undefined4 *)(DAT_600c57f4 + 0x290) = 0, *(int *)(param_1 + 0x10) != 0)) {
    (**(code **)(param_1 + 0x10))(1);
  }
  return;
}


