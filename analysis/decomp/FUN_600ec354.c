// 600ec354  FUN_600ec354  size=16 bytes
// --- callers ---
//   600e70ba FUN_600e70ba
//   6008deac FUN_6008deac
//   600e6dfe FUN_600e6dfe
// --- callees ---


bool FUN_600ec354(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(int *)(param_1 + 0xf0) == 10;
  }
  return bVar1;
}


