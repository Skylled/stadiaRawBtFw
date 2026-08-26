// 600d5512  FUN_600d5512  size=22 bytes
// --- callers ---
//   600d5528 FUN_600d5528
//   6005acc0 FUN_6005acc0
// --- callees ---


undefined4 FUN_600d5512(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x90) == 3) && (*(char *)(param_1 + 0x104) != '\0')) {
    uVar1 = func_0x600d5aca();
    return uVar1;
  }
  return 0;
}


