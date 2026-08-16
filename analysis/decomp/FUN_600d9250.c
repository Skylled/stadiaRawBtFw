// 600d9250  FUN_600d9250  size=64 bytes
// --- callers ---
//   600a9b04 FUN_600a9b04
//   600b02e0 FUN_600b02e0
//   600947c0 FUN_600947c0
//   600ad710 FUN_600ad710
//   600ac128 FUN_600ac128
//   6009a72c FUN_6009a72c
//   600c4da8 FUN_600c4da8
//   600af51c FUN_600af51c
//   60094c5c FUN_60094c5c
//   6009c7fc FUN_6009c7fc
//   600f9906 FUN_600f9906
//   600b7b48 FUN_600b7b48
//   600a9234 FUN_600a9234
//   600af170 FUN_600af170
//   600b8ba4 FUN_600b8ba4
//   600a9e14 FUN_600a9e14
//   600bc00c FUN_600bc00c
//   6009a7c0 FUN_6009a7c0
//   600b842c FUN_600b842c
//   600d9290 FUN_600d9290
//   600adc88 FUN_600adc88
//   60095234 FUN_60095234
//   600c66e8 FUN_600c66e8
//   600c63e0 FUN_600c63e0
//   600b9408 FUN_600b9408
//   600aa8a4 FUN_600aa8a4
//   600ac22c FUN_600ac22c
//   600b7800 FUN_600b7800
//   600b85e4 FUN_600b85e4
//   600a5760 FUN_600a5760
//   6006ed2c FUN_6006ed2c
//   600a99cc FUN_600a99cc
//   600bb534 FUN_600bb534
//   600b7374 FUN_600b7374
//   600af4d4 FUN_600af4d4
//   600aa800 FUN_600aa800
//   600bcca8 FUN_600bcca8
//   600af1a4 FUN_600af1a4
// --- callees ---
//   600d938e thunk_EXT_FUN_00007d64
//   600d938a thunk_EXT_FUN_00007dac


int FUN_600d9250(int *param_1)

{
  int iVar1;
  
  thunk_EXT_FUN_00007d64();
  if ((param_1 == (int *)0x0) || ((short)param_1[2] == 0)) {
    iVar1 = 0;
    thunk_EXT_FUN_00007dac();
  }
  else {
    iVar1 = *param_1;
    if (*(int *)(iVar1 + -0x38) == 0) {
      *param_1 = 0;
      param_1[1] = 0;
    }
    else {
      *param_1 = *(int *)(iVar1 + -0x38) + 0x38;
    }
    *(short *)(param_1 + 2) = (short)param_1[2] + -1;
    *(undefined4 *)(iVar1 + -0x38) = 0;
    *(undefined1 *)(iVar1 + -0x32) = 1;
    thunk_EXT_FUN_00007dac();
  }
  return iVar1;
}


