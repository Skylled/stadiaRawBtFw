// 600927d8  FUN_600927d8  size=92 bytes
// --- callers ---
//   600928ac FUN_600928ac
// --- callees ---
//   60097f5c FUN_60097f5c


undefined4 FUN_600927d8(undefined1 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_60097f5c(*param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  if (cVar1 == '\x01') {
    *DAT_60092834 = *(undefined4 *)(param_1 + 8);
  }
  else if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(param_1 + 8))(2,0,cVar1 != '\0');
  }
  return 1;
}


