// 6007946c  transfer_bug_report__6007946c  size=48 bytes
// src: transfer_bug_report.cc
// --- callers ---
// --- callees ---
//   6010165c FUN_6010165c


/* src: transfer_bug_report.cc */

undefined4 transfer_bug_report__6007946c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0x10) == '\t')) {
    FUN_6010165c(0x14,PTR_s_transfer_bug_report_cc_600794a0,99,PTR_s_Transfering_Bug_report_6007949c
                );
    uVar1 = 2;
    *(undefined4 *)(param_2 + 8) = 0xe;
    *(undefined **)(param_2 + 0x10) = PTR_LAB_60079398_1_600794a4;
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


