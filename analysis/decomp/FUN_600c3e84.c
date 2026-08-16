// 600c3e84  FUN_600c3e84  size=118 bytes
// --- callers ---
//   600c4da8 FUN_600c4da8
//   600c39c0 FUN_600c39c0
//   600c3a30 FUN_600c3a30
// --- callees ---
//   600962dc FUN_600962dc
//   600a2280 FUN_600a2280
//   6006dbac FUN_6006dbac
//   600c3f04 FUN_600c3f04


void FUN_600c3e84(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  uVar1 = FUN_600a2280(*(undefined4 *)(DAT_600c3efc + 4));
  *(undefined4 *)(DAT_600c3efc + 4) = uVar1;
  if (*(int *)(DAT_600c3efc + 4) == 0) {
    *(undefined4 *)(DAT_600c3efc + 8) = 0;
    puVar2 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c3f00,0x8d4);
    if (puVar2 != (undefined2 *)0x0) {
      *puVar2 = 0x206;
      puVar2[3] = 0x202;
      FUN_600962dc(puVar2);
    }
  }
  else {
    *(undefined1 *)(DAT_600c3efc + 0x20) = 0;
    *(undefined1 *)(DAT_600c3efc + 0x21) = 0;
    FUN_600c3f04(*(int *)(DAT_600c3efc + 4) + 2);
  }
  return;
}


