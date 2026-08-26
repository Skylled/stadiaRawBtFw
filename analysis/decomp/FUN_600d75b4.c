// 600d75b4  FUN_600d75b4  size=22 bytes
// --- callers ---
// --- callees ---


void FUN_600d75b4(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)**(undefined4 **)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
                    /* WARNING: Could not recover jumptable at 0x600d75c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


