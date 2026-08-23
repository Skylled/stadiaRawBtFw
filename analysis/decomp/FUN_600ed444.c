// 600ed444  FUN_600ed444  size=30 bytes
// --- callers ---
//   600ed462 FUN_600ed462
// --- callees ---


int * FUN_600ed444(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  int unaff_r5;
  
  uVar1 = param_1[1];
  if (uVar1 < param_3) {
    param_1 = (int *)0x0;
    uVar2 = uVar1;
  }
  else {
    unaff_r4 = *param_1;
    uVar2 = uVar1 - param_3;
    unaff_r5 = unaff_r4 + param_3;
  }
  if (param_3 <= uVar1) {
    param_1[1] = uVar2;
    *param_1 = unaff_r5;
    param_1 = (int *)0x1;
    *param_2 = unaff_r4;
    param_2[1] = param_3;
  }
  return param_1;
}


