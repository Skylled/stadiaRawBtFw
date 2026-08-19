// 600e19ec  FUN_600e19ec  size=38 bytes
// --- callers ---
//   60087964 FUN_60087964
// --- callees ---


void FUN_600e19ec(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_1 + -4);
  puVar1 = (uint *)(param_2 + -4);
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar2 = (*puVar1 ^ *puVar2) & -param_3 ^ *puVar2;
  } while (puVar2 != (uint *)(param_1 + 0x24));
  return;
}


