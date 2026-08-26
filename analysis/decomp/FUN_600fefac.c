// 600fefac  FUN_600fefac  size=44 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600abb14 FUN_600abb14
//   60095b2c FUN_60095b2c


void FUN_600fefac(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_60095b2c(*(undefined1 *)(param_2 + 8));
  if (iVar1 != 0) {
    FUN_600abb14(*(undefined1 *)(param_2 + 8));
  }
  return;
}


