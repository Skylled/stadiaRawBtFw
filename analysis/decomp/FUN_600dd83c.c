// 600dd83c  FUN_600dd83c  size=182 bytes
// --- callers ---
//   600dd7ca FUN_600dd7ca
// --- callees ---
//   600ddc48 FUN_600ddc48
//   600ddfde FUN_600ddfde
//   6007e204 FUN_6007e204
//   600de44e FUN_600de44e
//   600de4e0 FUN_600de4e0
//   600ddb2a FUN_600ddb2a
//   600ddeba FUN_600ddeba
//   600ddb8e FUN_600ddb8e


int * FUN_600dd83c(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = param_2;
  FUN_600de44e(param_1 + 1);
  param_1[2] = param_3;
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(*param_1 + 0x69);
  FUN_600ddc48(param_1 + 4,param_2);
  FUN_600ddfde(param_1 + 0x8b,*param_1);
  FUN_6007e204(param_1 + 0x2ed);
  FUN_600ddeba(param_1 + 0x372,param_1[2]);
  FUN_600ddb2a(param_1 + 0x377,*param_1);
  FUN_600ddb8e(param_1 + 0x3b7,*param_1);
  *(undefined1 *)(param_1 + 0x3b9) = 0;
  FUN_600de4e0(param_1 + 0x3ba,*param_1);
  param_1[0x4ae] = 0;
  param_1[0x4af] = 0;
  *(undefined1 *)(param_1 + 0x4b0) = 1;
  *(undefined1 *)((int)param_1 + 0x12c1) = 1;
  piVar1 = param_1 + 0x42e;
  do {
    piVar2 = piVar1 + 1;
    *piVar1 = 0;
    piVar1 = piVar2;
  } while (param_1 + 0x46e != piVar2);
  piVar1 = param_1 + 0x46e;
  do {
    piVar2 = piVar1 + 1;
    *piVar1 = 0;
    piVar1 = piVar2;
  } while (piVar2 != param_1 + 0x4ae);
  piVar1 = param_1 + 0x3ee;
  do {
    piVar2 = piVar1 + 1;
    *piVar1 = 0;
    piVar1 = piVar2;
  } while (param_1 + 0x42e != piVar2);
  return param_1;
}


