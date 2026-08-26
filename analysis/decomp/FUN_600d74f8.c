// 600d74f8  FUN_600d74f8  size=22 bytes
// --- callers ---
// --- callees ---


void FUN_600d74f8(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)**(undefined4 **)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
                    /* WARNING: Could not recover jumptable at 0x600d750c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


