// 600c41c0  FUN_600c41c0  size=130 bytes
// --- callers ---
//   600c2f68 FUN_600c2f68
// --- callees ---
//   600962dc FUN_600962dc
//   600c3bc4 FUN_600c3bc4
//   6006dbac FUN_6006dbac


void FUN_600c41c0(int param_1)

{
  undefined2 *puVar1;
  
  if (*(char *)(DAT_600c4244 + 0x13f) == '\0') {
    puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c4248,0x9b5);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = 0x203;
      *(undefined1 *)(puVar1 + 4) = *(undefined1 *)(param_1 + 1);
      FUN_600962dc(puVar1);
    }
  }
  else {
    *(undefined1 *)(DAT_600c4244 + 0x13f) = 0;
    FUN_600c3bc4(0);
    puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c4248,0x9c5);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = 0x206;
      puVar1[3] = 0x202;
      FUN_600962dc(puVar1);
    }
  }
  return;
}


