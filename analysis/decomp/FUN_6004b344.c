// 6004b344  FUN_6004b344  size=14 bytes
// --- callers ---
// --- callees ---


void FUN_6004b344(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 != '\0') {
    *param_1 = *param_2;
  }
  *(bool *)(param_1 + 1) = cVar1 != '\0';
  return;
}


