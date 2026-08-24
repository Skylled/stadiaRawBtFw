// 600f1f5c  FUN_600f1f5c  size=38 bytes
// --- callers ---
//   600fcfbc FUN_600fcfbc
//   600c2e9c FUN_600c2e9c
// --- callees ---
//   6009ff18 FUN_6009ff18


int FUN_600f1f5c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + 4;
  }
  return iVar1;
}


