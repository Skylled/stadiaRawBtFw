// 6004b35e  FUN_6004b35e  size=30 bytes
// --- callers ---
// --- callees ---


void FUN_6004b35e(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  
  if (*(char *)(param_1 + 1) == '\0') {
    if (*(char *)(param_2 + 1) == '\0') {
      return;
    }
    *param_1 = *param_2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) != '\0') {
      *param_1 = *param_2;
      return;
    }
  }
  *(undefined1 *)(param_1 + 1) = uVar1;
  return;
}


