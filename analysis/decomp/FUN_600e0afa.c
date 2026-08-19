// 600e0afa  FUN_600e0afa  size=46 bytes
// --- callers ---
//   6008b544 FUN_6008b544
// --- callees ---
//   600e0ae2 FUN_600e0ae2


void FUN_600e0afa(uint *param_1,code *param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (param_1 != (uint *)0x0) {
    for (uVar1 = 0; uVar1 < *param_1; uVar1 = uVar1 + 1) {
      if (*(int *)(param_1[1] + uVar1 * 4) != 0) {
        (*param_2)(param_3);
      }
    }
    FUN_600e0ae2(param_1);
    return;
  }
  return;
}


