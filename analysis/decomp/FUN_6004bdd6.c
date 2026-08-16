// 6004bdd6  FUN_6004bdd6  size=16 bytes
// --- callers ---
//   6004b29e FUN_6004b29e
//   60048d54 FUN_60048d54
//   60046fa4 FUN_60046fa4
// --- callees ---


void FUN_6004bdd6(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    *param_1 = param_2;
  }
  return;
}


