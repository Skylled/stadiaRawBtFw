// 600d3eb4  FUN_600d3eb4  size=26 bytes
// --- callers ---
//   600d3ece FUN_600d3ece
// --- callees ---


void FUN_600d3eb4(undefined4 *param_1,undefined4 *param_2)

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


