// 6004bd8e  FUN_6004bd8e  size=22 bytes
// --- callers ---
//   6004b7a4 FUN_6004b7a4
//   60046588 FUN_60046588
//   60045e4c FUN_60045e4c
//   600467f8 FUN_600467f8
//   6004bb98 FUN_6004bb98
//   60046a74 FUN_60046a74
// --- callees ---


void FUN_6004bd8e(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_1 + -1);
  puVar1 = param_2 + param_3;
  for (; param_2 != puVar1; param_2 = param_2 + 1) {
    puVar2 = puVar2 + 1;
    *puVar2 = *param_2;
  }
  return;
}


