// 600eca86  FUN_600eca86  size=56 bytes
// --- callers ---
//   60090c3c tasn_new__60090c3c
// --- callees ---
//   600eca56 FUN_600eca56


void FUN_600eca86(undefined4 *param_1,undefined1 *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar1;
  
  do {
    switch(*param_2) {
    case 0:
      puVar1 = *(uint **)(param_2 + 8);
      if (puVar1 == (uint *)0x0) goto switchD_600eca90_caseD_5;
      if ((*puVar1 & 0x306) != 0) goto switchD_600eca90_caseD_1;
      param_2 = (undefined1 *)puVar1[4];
      break;
    case 4:
      if ((*(int *)(param_2 + 0x10) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_2 + 0x10) + 0xc),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600ecaa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
    case 1:
    case 2:
    case 3:
    case 6:
switchD_600eca90_caseD_1:
      *param_1 = 0;
switchD_600eca90_default:
      return;
    case 5:
switchD_600eca90_caseD_5:
      FUN_600eca56();
      return;
    default:
      goto switchD_600eca90_default;
    }
  } while( true );
}


