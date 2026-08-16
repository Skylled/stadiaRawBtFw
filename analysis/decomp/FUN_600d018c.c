// 600d018c  FUN_600d018c  size=378 bytes
// --- callers ---
//   600d0332 FUN_600d0332
// --- callees ---


undefined4 FUN_600d018c(int param_1,int *param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  
  switch(*(undefined1 *)(*param_2 + 1)) {
  case 1:
    break;
  case 2:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x202;
      break;
    case 3:
      uVar1 = 0x203;
      break;
    case 4:
      uVar1 = 0x204;
      break;
    case 5:
      uVar1 = 0x205;
      break;
    case 6:
      uVar1 = 0x206;
      break;
    default:
      goto switchD_600d0094_caseD_7;
    case 8:
      uVar1 = 0x208;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600d00b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600d0094_caseD_7:
    return 1;
  case 3:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x302;
      break;
    case 3:
      uVar1 = 0x303;
      break;
    case 4:
      uVar1 = 0x304;
      break;
    case 5:
      uVar1 = 0x305;
      break;
    case 6:
      uVar1 = 0x306;
      break;
    default:
      goto switchD_600d00ec_caseD_7;
    case 8:
      uVar1 = 0x308;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600d010c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600d00ec_caseD_7:
    return 1;
  case 4:
    switch(*(ushort *)(*param_2 + 2) >> 8) {
    case 2:
      uVar1 = 0x402;
      break;
    case 3:
      uVar1 = 0x403;
      break;
    case 4:
      uVar1 = 0x404;
      break;
    case 5:
      uVar1 = 0x405;
      break;
    case 6:
      uVar1 = 0x406;
      break;
    default:
      goto switchD_600d0144_caseD_7;
    case 8:
      uVar1 = 0x408;
    }
    if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
       UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600d0164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
      return uVar1;
    }
switchD_600d0144_caseD_7:
    return 1;
  default:
    return 1;
  }
  switch(*(ushort *)(*param_2 + 2) >> 8) {
  case 1:
    uVar1 = 0x101;
    break;
  case 2:
    uVar1 = 0x102;
    break;
  case 3:
    uVar1 = 0x103;
    break;
  case 4:
    uVar1 = 0x104;
    break;
  case 5:
    uVar1 = 0x105;
    break;
  case 6:
    uVar1 = 0x106;
    break;
  case 7:
    uVar1 = 0x107;
    break;
  case 8:
    uVar1 = 0x108;
    break;
  case 9:
    uVar1 = 0x109;
    break;
  case 10:
    uVar1 = 0x10a;
    break;
  default:
    goto switchD_600d0022_default;
  }
  if ((*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) &&
     (UNRECOVERED_JUMPTABLE_00 = (code *)**(undefined4 **)(param_1 + 4),
     UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600d0044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,param_2);
    return uVar1;
  }
switchD_600d0022_default:
  return 1;
}


