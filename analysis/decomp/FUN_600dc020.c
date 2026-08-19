// 600dc020  FUN_600dc020  size=34 bytes
// --- callers ---
//   6007bb4c FUN_6007bb4c
// --- callees ---
//   600dc010 FUN_600dc010


void FUN_600dc020(undefined4 *param_1)

{
  undefined4 *puVar1;
  int extraout_r1;
  undefined4 *puVar2;
  
  puVar1 = param_1;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != param_1 + 0x10);
  FUN_600dc010(puVar2,param_1);
  FUN_600dc010(extraout_r1 + 0x60);
  return;
}


