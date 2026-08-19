// 600dcd38  FUN_600dcd38  size=14 bytes
// --- callers ---
//   6007cf14 FUN_6007cf14
// --- callees ---


void FUN_600dcd38(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_2 + 0x81;
  do {
    *param_2 = param_1;
    param_2 = param_2 + 1;
  } while (param_2 != puVar1);
  return;
}


