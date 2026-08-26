// 600d754c  FUN_600d754c  size=22 bytes
// --- callers ---
// --- callees ---


void FUN_600d754c(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)**(undefined4 **)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
                    /* WARNING: Could not recover jumptable at 0x600d7560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


