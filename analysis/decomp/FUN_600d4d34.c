// 600d4d34  FUN_600d4d34  size=34 bytes
// --- callers ---
// --- callees ---
//   60101b0c FUN_60101b0c
//   60101ba2 FUN_60101ba2


void FUN_600d4d34(int *param_1,int param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = FUN_60101b0c(param_2,param_2 >> 0x1f,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
                    /* WARNING: Could not recover jumptable at 0x600d4d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}


