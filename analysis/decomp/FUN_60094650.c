// 60094650  FUN_60094650  size=58 bytes
// --- callers ---
//   600c5eac FUN_600c5eac
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60094650(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_6009468c,0xca);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1d08;
    puVar1[3] = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


