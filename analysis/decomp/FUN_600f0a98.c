// 600f0a98  FUN_600f0a98  size=48 bytes
// --- callers ---
//   600ac2a4 FUN_600ac2a4
// --- callees ---
//   6009ff18 FUN_6009ff18


bool FUN_600f0a98(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    *param_2 = *(undefined1 *)(iVar1 + 0x7b);
  }
  return iVar1 != 0;
}


