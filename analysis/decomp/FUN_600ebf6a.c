// 600ebf6a  FUN_600ebf6a  size=12 bytes
// --- callers ---
// --- callees ---
//   600ebf64 FUN_600ebf64


void FUN_600ebf6a(int *param_1)

{
  if (*(code **)(*param_1 + 0x14) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x600ebf70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x14))();
    return;
  }
  FUN_600ebf64();
  return;
}


