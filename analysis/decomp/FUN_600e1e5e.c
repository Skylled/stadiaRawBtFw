// 600e1e5e  FUN_600e1e5e  size=28 bytes
// --- callers ---
//   600e22a2 FUN_600e22a2
//   600e6f7a FUN_600e6f7a
// --- callees ---


void FUN_600e1e5e(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_1 + -4);
  puVar1 = (uint *)(param_2 + -4);
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar2 = *puVar2 ^ *puVar1;
  } while (puVar2 != (uint *)(param_1 + 0x1c));
  return;
}


