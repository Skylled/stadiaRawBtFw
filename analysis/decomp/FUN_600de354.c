// 600de354  FUN_600de354  size=34 bytes
// --- callers ---
//   6007dfcc FUN_6007dfcc
//   6007df4c FUN_6007df4c
//   6007ded0 FUN_6007ded0
// --- callees ---


void FUN_600de354(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = param_1;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (param_1 + 0x41 != puVar2);
  puVar1 = param_1 + 0x41;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (param_1 + 0x82 != puVar2);
  return;
}


