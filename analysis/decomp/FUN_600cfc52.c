// 600cfc52  FUN_600cfc52  size=30 bytes
// --- callers ---
//   600cfc8e FUN_600cfc8e
// --- callees ---


undefined4 FUN_600cfc52(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_3 == 0) {
    return 3;
  }
  *(undefined1 *)(param_3 + 0x1d) = 0;
  if ((*(undefined4 **)(param_3 + 4) != (undefined4 *)0x0) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(param_3 + 4),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600cfc66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_3,2,param_2);
    return uVar1;
  }
  return 1;
}


