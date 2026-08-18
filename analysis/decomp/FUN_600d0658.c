// 600d0658  FUN_600d0658  size=34 bytes
// --- callers ---
//   600d52f0 FUN_600d52f0
// --- callees ---
//   600d109c FUN_600d109c


int FUN_600d0658(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    iVar1 = FUN_600d109c(*param_1);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 7) = 0;
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}


