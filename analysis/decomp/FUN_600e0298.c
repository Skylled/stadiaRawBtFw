// 600e0298  FUN_600e0298  size=16 bytes
// --- callers ---
//   6005a4cc device_info__6005a4cc
// --- callees ---


void FUN_600e0298(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    do {
      iVar1 = param_1;
      param_1 = *(int *)(iVar1 + 0x20);
    } while (param_1 != 0);
    *(undefined4 *)(iVar1 + 0x20) = param_2;
  }
  return;
}


