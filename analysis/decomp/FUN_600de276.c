// 600de276  FUN_600de276  size=18 bytes
// --- callers ---
//   600de288 FUN_600de288
//   600dcc10 FUN_600dcc10
// --- callees ---


void FUN_600de276(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  puVar2 = (undefined4 *)(param_1 + 0x14);
  do {
    puVar3 = puVar2 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar3;
  } while (puVar3 != (undefined4 *)(param_1 + 0xf4));
  return;
}


