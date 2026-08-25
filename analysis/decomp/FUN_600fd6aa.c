// 600fd6aa  FUN_600fd6aa  size=44 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   60094f58 FUN_60094f58
//   600abb14 FUN_600abb14


void FUN_600fd6aa(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_60094f58(*(undefined1 *)(param_2 + 8));
  if (iVar1 != 0) {
    FUN_600abb14(*(undefined1 *)(param_2 + 8));
  }
  return;
}


