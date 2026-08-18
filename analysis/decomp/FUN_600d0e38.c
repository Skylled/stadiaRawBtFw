// 600d0e38  FUN_600d0e38  size=32 bytes
// --- callers ---
// --- callees ---
//   600d109c FUN_600d109c


int FUN_600d0e38(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (*(char *)((int)param_1 + 0x12) == '\0') {
    iVar1 = FUN_600d109c(*param_1);
    if (iVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0x12) = 1;
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}


