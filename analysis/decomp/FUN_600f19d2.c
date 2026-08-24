// 600f19d2  FUN_600f19d2  size=60 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600f19d2(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (((iVar1 != 0) && (*(char *)(iVar1 + 0xef) != '\0')) && (*(int *)(iVar1 + 0xf0) != 0)) {
    *(undefined1 *)(iVar1 + 0xef) = 0;
  }
  return;
}


