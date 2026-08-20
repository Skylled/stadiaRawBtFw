// 600eb428  FUN_600eb428  size=40 bytes
// --- callers ---
//   6008e700 bcm__6008e700
//   6008dab0 bcm__6008dab0
//   6008e910 bcm__6008e910
//   6008db08 bcm__6008db08
//   6008d6f8 bcm__6008d6f8
//   6008da3c bcm__6008da3c
//   6008d5e0 bcm__6008d5e0
//   6008d730 bcm__6008d730
//   6008da74 bcm__6008da74
//   6008d6b8 bcm__6008d6b8
// --- callees ---
//   600eb3a4 FUN_600eb3a4


undefined4 FUN_600eb428(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == param_2) {
LAB_600eb446:
    uVar1 = 0;
  }
  else {
    if (param_1[7] == param_2[7]) {
      if (param_1[7] != 0) goto LAB_600eb446;
      if (*param_1 == *param_2) {
        uVar1 = FUN_600eb3a4();
        return uVar1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


