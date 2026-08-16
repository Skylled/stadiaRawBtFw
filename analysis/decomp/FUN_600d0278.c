// 600d0278  FUN_600d0278  size=378 bytes
// --- callers ---
//   600d0332 FUN_600d0332
// --- callees ---


undefined4 FUN_600d0278(int param_1,int *param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  
  switch(*(undefined1 *)(*param_2 + 1)) {
  case 0x81:
    break;
  case 0x82:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x8202;
      break;
    case 3:
      uVar1 = 0x8203;
      break;
    case 4:
      uVar1 = 0x8204;
      break;
    case 5:
      uVar1 = 0x8205;
      break;
    case 6:
      uVar1 = 0x8206;
      break;
    default:
      goto switchD_600cff1a_caseD_7;
    case 8:
      uVar1 = 0x8208;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600cff3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600cff1a_caseD_7:
    return 1;
  case 0x83:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x8302;
      break;
    case 3:
      uVar1 = 0x8303;
      break;
    case 4:
      uVar1 = 0x8304;
      break;
    case 5:
      uVar1 = 0x8305;
      break;
    case 6:
      uVar1 = 0x8306;
      break;
    default:
      goto switchD_600cff72_caseD_7;
    case 8:
      uVar1 = 0x8308;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600cff92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600cff72_caseD_7:
    return 1;
  case 0x84:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x8402;
      break;
    case 3:
      uVar1 = 0x8403;
      break;
    case 4:
      uVar1 = 0x8404;
      break;
    case 5:
      uVar1 = 0x8405;
      break;
    case 6:
      uVar1 = 0x8406;
      break;
    default:
      goto switchD_600cffca_caseD_7;
    case 8:
      uVar1 = 0x8408;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600cffea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600cffca_caseD_7:
    return 1;
  default:
    return 1;
  }
  switch(*(ushort *)(*param_2 + 2) >> 8) {
  case 1:
    uVar1 = 0x8101;
    break;
  case 2:
    uVar1 = 0x8102;
    break;
  case 3:
    uVar1 = 0x8103;
    break;
  case 4:
    uVar1 = 0x8104;
    break;
  case 5:
    uVar1 = 0x8105;
    break;
  case 6:
    uVar1 = 0x8106;
    break;
  case 7:
    uVar1 = 0x8107;
    break;
  case 8:
    uVar1 = 0x8108;
    break;
  case 9:
    uVar1 = 0x8109;
    break;
  case 10:
    uVar1 = 0x810a;
    break;
  default:
    goto switchD_600cfea8_default;
  }
  if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
     (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
     UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600cfeca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
    return uVar1;
  }
switchD_600cfea8_default:
  return 1;
}


