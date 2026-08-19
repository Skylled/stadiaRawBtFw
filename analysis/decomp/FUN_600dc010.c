// 600dc010  FUN_600dc010  size=16 bytes
// --- callers ---
//   600dc020 FUN_600dc020
//   6007bb4c FUN_6007bb4c
// --- callees ---


void FUN_600dc010(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = param_1;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != param_1 + 8);
  return;
}


