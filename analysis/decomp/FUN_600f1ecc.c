// 600f1ecc  FUN_600f1ecc  size=36 bytes
// --- callers ---
//   600a44bc FUN_600a44bc
//   600a7b44 FUN_600a7b44
// --- callees ---
//   600b264c FUN_600b264c


undefined4 FUN_600f1ecc(int param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x50) = 1;
  uVar1 = FUN_600b264c(*(undefined2 *)(param_1 + 0xc));
  return uVar1;
}


