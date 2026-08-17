// 60092838  FUN_60092838  size=106 bytes
// --- callers ---
//   600928ac FUN_600928ac
// --- callees ---
//   6009819c FUN_6009819c


undefined4 FUN_60092838(undefined1 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_6009819c(*param_1,param_1[1],*(undefined4 *)(param_1 + 4),DAT_600928a4);
  if (cVar1 == '\x01') {
    *DAT_600928a8 = *(undefined4 *)(param_1 + 8);
  }
  else if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(param_1 + 8))(2,param_1[1],cVar1 != '\0');
  }
  return 1;
}


