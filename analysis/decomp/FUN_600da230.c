// 600da230  FUN_600da230  size=26 bytes
// --- callers ---
//   600da24a FUN_600da24a
// --- callees ---


void FUN_600da230(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 != '\0') {
    *param_1 = *param_2;
  }
  *(bool *)(param_1 + 1) = cVar1 != '\0';
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
  *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_2 + 9);
  *(undefined1 *)((int)param_1 + 10) = *(undefined1 *)((int)param_2 + 10);
  return;
}


