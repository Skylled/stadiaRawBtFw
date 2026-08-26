// 600d543c  FUN_600d543c  size=26 bytes
// --- callers ---
//   60058bdc FUN_60058bdc
//   6005ad74 application_state__6005ad74
// --- callees ---
//   600d5364 FUN_600d5364


void FUN_600d543c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 8) = *param_2;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  if (*(char *)(param_1 + 0x18) != '\0') {
    FUN_600d5364((undefined4 *)(param_1 + 8));
  }
  return;
}


