// 600ddeba  FUN_600ddeba  size=46 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---
//   600de44e FUN_600de44e
//   600dde54 FUN_600dde54


int * FUN_600ddeba(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 extraout_r3;
  int *piVar1;
  int iStack_14;
  undefined4 uStack_10;
  
  *param_1 = param_2;
  piVar1 = param_1;
  iStack_14 = param_2;
  uStack_10 = param_3;
  FUN_600de44e(param_1 + 1);
  if (param_2 == 8000) {
    param_2 = 1;
  }
  else {
    param_2 = param_2 / 16000;
  }
  FUN_600dde54(param_1 + 2,param_2,&iStack_14,extraout_r3,piVar1);
  return param_1;
}


