// 600e22a2  FUN_600e22a2  size=76 bytes
// --- callers ---
//   600e6dfe FUN_600e6dfe
//   600e6e26 FUN_600e6e26
//   600e7124 FUN_600e7124
// --- callees ---
//   600e1e7a FUN_600e1e7a
//   600e1e5e FUN_600e1e5e
//   600e2126 FUN_600e2126
//   600e21aa FUN_600e21aa


void FUN_600e22a2(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  FUN_600e1e5e(param_3,param_1);
  for (uVar1 = 1; uVar1 < param_2; uVar1 = uVar1 + 1) {
    FUN_600e1e7a(param_3);
    FUN_600e2126(param_3);
    FUN_600e21aa(param_3);
    FUN_600e1e5e(param_3,param_1 + uVar1 * 0x20);
  }
  FUN_600e1e7a(param_3);
  FUN_600e2126();
  FUN_600e1e5e(param_3,param_1 + param_2 * 0x20);
  return;
}


