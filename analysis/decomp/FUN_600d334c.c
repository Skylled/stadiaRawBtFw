// 600d334c  FUN_600d334c  size=58 bytes
// --- callers ---
//   60055e7c FUN_60055e7c
//   6005663c FUN_6005663c
//   60055d78 FUN_60055d78
//   60055a28 FUN_60055a28
//   600558b8 FUN_600558b8
//   60055a7c FUN_60055a7c
//   6005592c FUN_6005592c
//   60055cfc FUN_60055cfc
//   60055e28 FUN_60055e28
//   60055bd8 FUN_60055bd8
//   60055ed0 FUN_60055ed0
//   60055f40 FUN_60055f40
// --- callees ---
//   600d1692 FUN_600d1692
//   600d16ae FUN_600d16ae


undefined4 FUN_600d334c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar1 = 3;
  }
  else {
    FUN_600d1692(*(undefined4 *)(param_1 + 8));
    iVar2 = *(int *)(param_1 + 0x2cc);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      FUN_600d16ae(*(undefined4 *)(param_1 + 8));
      uVar1 = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x2cc) = **(undefined4 **)(param_1 + 0x2cc);
      FUN_600d16ae(*(undefined4 *)(param_1 + 8));
      uVar1 = 0;
    }
  }
  return uVar1;
}


