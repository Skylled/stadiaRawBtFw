// 600ec9ca  FUN_600ec9ca  size=34 bytes
// --- callers ---
//   60090940 FUN_60090940
//   600ec5d2 FUN_600ec5d2
// --- callees ---
//   6009089c FUN_6009089c


void FUN_600ec9ca(undefined4 param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 0x10) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600ec9de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  FUN_6009089c(param_1,param_2);
  return;
}


