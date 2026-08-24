// 600ee058  FUN_600ee058  size=10 bytes
// --- callers ---
//   600ee062 FUN_600ee062
// --- callees ---


void FUN_600ee058(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x600ee05e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*param_1)(param_1[1]);
    return;
  }
  return;
}


