// 600de4e0  FUN_600de4e0  size=84 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---
//   600de492 FUN_600de492
//   600de6fe FUN_600de6fe
//   600dea3a FUN_600dea3a
//   600de4b4 FUN_600de4b4
//   600de47c FUN_600de47c


undefined4 *
FUN_600de4e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  *param_1 = param_2;
  FUN_600de47c(param_1 + 1);
  FUN_600de492(param_1 + 5,*param_1,extraout_r2,param_1 + 0xb,param_4);
  FUN_600de4b4(extraout_r3,*param_1);
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  FUN_600de6fe(param_1 + 0x1e,*param_1);
  FUN_600dea3a(param_1 + 0x33);
  return param_1;
}


