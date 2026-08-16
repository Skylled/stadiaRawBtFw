// 60092e5c  FUN_60092e5c  size=46 bytes
// --- callers ---
//   60095f9c FUN_60095f9c
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092e5c(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_60092e8c,0x67);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x101;
    FUN_600962dc(puVar1);
  }
  return;
}


