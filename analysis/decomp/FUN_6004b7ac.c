// 6004b7ac  FUN_6004b7ac  size=8 bytes
// --- callers ---
// --- callees ---


void FUN_6004b7ac(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_3 != 0) {
    puVar1 = param_1 + param_3;
    for (; param_1 != puVar1; param_1 = param_1 + 1) {
      *param_1 = param_2;
    }
    return;
  }
  return;
}


