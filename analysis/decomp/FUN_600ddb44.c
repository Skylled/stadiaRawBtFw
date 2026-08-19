// 600ddb44  FUN_600ddb44  size=74 bytes
// --- callers ---
// --- callees ---


void FUN_600ddb44(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  if (5 < *(uint *)(param_1 + 4)) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  puVar1 = param_2;
  puVar2 = (uint *)(param_1 + 8);
  do {
    if (5 < *puVar2) {
      puVar1[4] = 0;
      puVar1[3] = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (puVar1 != param_2 + 0x3d);
  if (5 < *(uint *)(param_1 + 0xfc)) {
    param_2[0x3f] = 0;
    param_2[0x40] = 0;
  }
  return;
}


