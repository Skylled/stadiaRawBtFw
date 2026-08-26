// 600d752c  FUN_600d752c  size=22 bytes
// --- callers ---
// --- callees ---


void FUN_600d752c(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)**(undefined4 **)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
                    /* WARNING: Could not recover jumptable at 0x600d7540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


