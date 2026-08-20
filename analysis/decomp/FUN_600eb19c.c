// 600eb19c  FUN_600eb19c  size=56 bytes
// --- callers ---
//   600eb7ce FUN_600eb7ce
// --- callees ---
//   600eafb4 FUN_600eafb4
//   600eb192 FUN_600eb192


void FUN_600eb19c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_4 < 0) {
    FUN_600eafb4(param_2,(-param_4 >> 1) * 0xcc + param_3);
    FUN_600eb192(param_1,param_2);
    return;
  }
  FUN_600eafb4(param_2,(param_4 >> 1) * 0xcc + param_3,param_3,param_4);
  return;
}


