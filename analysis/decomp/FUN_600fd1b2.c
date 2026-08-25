// 600fd1b2  FUN_600fd1b2  size=58 bytes
// --- callers ---
// --- callees ---
//   600f1800 FUN_600f1800


void FUN_600fd1b2(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600f1800(param_1 + 8,*(undefined4 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 0xe));
  if ((iVar1 != 1) && (*(int *)(param_1 + 0x10) != 0)) {
    (**(code **)(param_1 + 0x10))(0);
  }
  return;
}


