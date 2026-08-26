// 600d643e  FUN_600d643e  size=34 bytes
// --- callers ---
//   600d6460 FUN_600d6460
// --- callees ---
//   600d63b4 FUN_600d63b4


int FUN_600d643e(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 == *(undefined4 **)(param_1 + 8)) {
    FUN_600d63b4();
  }
  else {
    *puVar1 = *param_2;
    *(undefined4 **)(param_1 + 4) = puVar1 + 1;
  }
  return *(int *)(param_1 + 4) + -4;
}


