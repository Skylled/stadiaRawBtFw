// 600ef476  FUN_600ef476  size=56 bytes
// --- callers ---
//   600fdff0 FUN_600fdff0
//   600fe2fe FUN_600fe2fe
//   600fe432 FUN_600fe432
//   600fe916 FUN_600fe916
//   600fe146 FUN_600fe146
//   600fe1ea FUN_600fe1ea
// --- callees ---


bool FUN_600ef476(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x14) == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x14) = param_2;
    *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) | 1;
  }
  return bVar1;
}


