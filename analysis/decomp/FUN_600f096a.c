// 600f096a  FUN_600f096a  size=42 bytes
// --- callers ---
//   600c03d8 FUN_600c03d8
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600f096a(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x61) = param_2;
  }
  return;
}


