// 600da358  FUN_600da358  size=52 bytes
// --- callers ---
// --- callees ---
//   600da24a FUN_600da24a


undefined4 FUN_600da358(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  
  switch(param_4) {
  case 2:
    uVar1 = 1;
    break;
  case 3:
    uVar1 = 0;
    break;
  default:
    goto switchD_600da362_caseD_4;
  case 8:
    uVar1 = 1;
    goto LAB_600da370;
  case 9:
    uVar1 = 0;
LAB_600da370:
    *(undefined1 *)(param_2 + 0x78) = uVar1;
    goto switchD_600da362_caseD_4;
  }
  *(undefined1 *)(param_2 + 0x79) = uVar1;
switchD_600da362_caseD_4:
  FUN_600da24a(param_1);
  return param_1;
}


