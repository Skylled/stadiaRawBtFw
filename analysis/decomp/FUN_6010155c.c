// 6010155c  FUN_6010155c  size=14 bytes
// --- callers ---
//   601015e6 FUN_601015e6
//   6010156a FUN_6010156a
// --- callees ---
//   60101536 FUN_60101536


void FUN_6010155c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60101536(param_1,*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return;
}


