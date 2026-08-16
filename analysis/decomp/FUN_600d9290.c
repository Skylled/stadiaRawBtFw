// 600d9290  FUN_600d9290  size=104 bytes
// --- callers ---
//   600a82a0 FUN_600a82a0
//   600bb15c FUN_600bb15c
//   600b842c FUN_600b842c
//   600a957c FUN_600a957c
//   600a830c FUN_600a830c
//   600ab318 FUN_600ab318
//   600a943c FUN_600a943c
//   600af020 FUN_600af020
//   600ab110 FUN_600ab110
//   600ab424 FUN_600ab424
// --- callees ---
//   600d938e thunk_EXT_FUN_00007d64
//   600d9250 FUN_600d9250
//   600d938a thunk_EXT_FUN_00007dac


int FUN_600d9290(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  thunk_EXT_FUN_00007d64();
  if (*param_1 == param_2) {
    thunk_EXT_FUN_00007dac();
    iVar2 = FUN_600d9250(param_1);
    return iVar2;
  }
  piVar1 = (int *)(*param_1 + -0x38);
  do {
    piVar3 = piVar1;
    if (piVar3 == (int *)0x0) {
      thunk_EXT_FUN_00007dac();
      return 0;
    }
    piVar1 = (int *)*piVar3;
  } while ((int *)*piVar3 != (int *)(param_2 + -0x38));
  *piVar3 = *(int *)(param_2 + -0x38);
  if (param_1[1] == param_2) {
    piVar3 = piVar3 + 0xe;
  }
  *(short *)(param_1 + 2) = (short)param_1[2] + -1;
  if (param_1[1] == param_2) {
    param_1[1] = (int)piVar3;
  }
  *(undefined4 *)(param_2 + -0x38) = 0;
  *(undefined1 *)(param_2 + -0x32) = 1;
  thunk_EXT_FUN_00007dac();
  return param_2;
}


