// 600f0a52  FUN_600f0a52  size=70 bytes
// --- callers ---
//   6009b77c FUN_6009b77c
//   600f0e98 FUN_600f0e98
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600f0a52(undefined4 param_1,char param_2)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    if (param_2 == '\0') {
      *(int *)(iVar1 + 0xdc) = *(int *)(iVar1 + 0xdc) + 1;
    }
    else {
      *(int *)(iVar1 + 0xe0) = *(int *)(iVar1 + 0xe0) + 1;
    }
  }
  return;
}


