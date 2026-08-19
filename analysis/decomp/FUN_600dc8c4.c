// 600dc8c4  FUN_600dc8c4  size=48 bytes
// --- callers ---
//   6007bb4c FUN_6007bb4c
// --- callees ---


void FUN_600dc8c4(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar3;
  undefined4 *puVar2;
  
  puVar3 = (undefined4 *)(param_1 + 600);
  do {
    puVar1 = puVar3 + -0x96;
    do {
      puVar2 = puVar1 + 1;
      *puVar1 = 0;
      puVar1 = puVar2;
    } while (puVar3 + -0x87 != puVar2);
    puVar1 = puVar3 + 0xf;
    do {
      puVar2 = puVar3 + 1;
      *puVar3 = 0;
      puVar3 = puVar2;
    } while (puVar1 != puVar2);
    puVar3 = puVar1;
  } while ((undefined4 *)(param_1 + 0x4b0) != puVar1);
  return;
}


