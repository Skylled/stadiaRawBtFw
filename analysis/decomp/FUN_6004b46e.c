// 6004b46e  FUN_6004b46e  size=12 bytes
// --- callers ---
// --- callees ---


void FUN_6004b46e(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_2 != 0) {
    puVar1 = param_1 + param_2;
    for (; param_1 != puVar1; param_1 = param_1 + 1) {
      *param_1 = 0;
    }
    return;
  }
  return;
}


