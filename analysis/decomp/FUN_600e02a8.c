// 600e02a8  FUN_600e02a8  size=6 bytes
// --- callers ---
//   600d7ebc FUN_600d7ebc
//   600d7e56 FUN_600d7e56
//   60067a68 gotham__60067a68
// --- callees ---


undefined4 FUN_600e02a8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
  }
  return uVar1;
}


