// 600d3386  FUN_600d3386  size=44 bytes
// --- callers ---
//   600d1d66 FUN_600d1d66
//   60055e7c FUN_60055e7c
//   60055a28 FUN_60055a28
//   6005673c FUN_6005673c
//   60055a7c FUN_60055a7c
//   6005592c FUN_6005592c
//   60055cfc FUN_60055cfc
//   600d1ffa FUN_600d1ffa
//   600d176e FUN_600d176e
//   600d1d46 FUN_600d1d46
//   600d1746 FUN_600d1746
//   600d3196 FUN_600d3196
//   600d1d26 FUN_600d1d26
//   60055d78 FUN_60055d78
//   600d1fda FUN_600d1fda
//   600558b8 FUN_600558b8
//   60055e28 FUN_60055e28
//   60055bd8 FUN_60055bd8
//   60055ed0 FUN_60055ed0
//   60055f40 FUN_60055f40
//   600d178e FUN_600d178e
// --- callees ---
//   600d1692 FUN_600d1692
//   600d16ae FUN_600d16ae


undefined4 FUN_600d3386(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_600d1692(*(undefined4 *)(param_1 + 8));
    uVar1 = *(undefined4 *)(param_1 + 8);
    *param_2 = *(undefined4 *)(param_1 + 0x2cc);
    *(undefined4 **)(param_1 + 0x2cc) = param_2;
    FUN_600d16ae(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}


