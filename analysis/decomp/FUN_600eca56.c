// 600eca56  FUN_600eca56  size=48 bytes
// --- callers ---
//   600eca86 FUN_600eca86
// --- callees ---


void FUN_600eca56(undefined4 *param_1,char *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_2 + 0x10) == 0) {
      if ((*param_2 != '\x05') && (*(int *)(param_2 + 4) == 1)) {
        uVar1 = *(undefined4 *)(param_2 + 0x14);
        goto LAB_600eca6e;
      }
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0x10);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x600eca6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
    }
  }
  uVar1 = 0;
LAB_600eca6e:
  *param_1 = uVar1;
  return;
}


