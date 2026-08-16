// 600c51d0  FUN_600c51d0  size=74 bytes
// --- callers ---
// --- callees ---
//   60093500 FUN_60093500
//   600962dc FUN_600962dc
//   60095ee8 FUN_60095ee8
//   6006dbac FUN_6006dbac


void FUN_600c51d0(void)

{
  undefined2 *puVar1;
  
  FUN_60093500();
  FUN_60095ee8(0,DAT_600c521c);
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_600c5220,0xe64);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 3;
    puVar1[4] = 0;
    FUN_600962dc(puVar1);
  }
  *(undefined1 *)(DAT_600c5224 + 0x108) = 0;
  return;
}


