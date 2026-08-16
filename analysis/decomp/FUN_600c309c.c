// 600c309c  FUN_600c309c  size=168 bytes
// --- callers ---
//   600c330c FUN_600c330c
// --- callees ---
//   600962dc FUN_600962dc
//   600c3bc4 FUN_600c3bc4
//   6006dbac FUN_6006dbac
//   600a1edc FUN_600a1edc
//   600a1efc FUN_600a1efc
//   600c5f64 FUN_600c5f64


void FUN_600c309c(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = FUN_600a1edc();
  if (iVar1 == 0) {
    if (*(char *)(DAT_600c3148 + 0x20) == '\0') {
      puVar2 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c3144,0x532);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0x206;
        puVar2[3] = 0x202;
        FUN_600962dc(puVar2);
      }
    }
  }
  else {
    iVar1 = FUN_600a1efc();
    if (iVar1 == 1) {
      *(undefined1 *)(DAT_600c3148 + 0x13f) = 1;
    }
    else {
      puVar2 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c3144,0x51e);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0x206;
        puVar2[3] = 0x202;
        FUN_600962dc(puVar2);
      }
    }
    FUN_600c3bc4(0);
  }
  if (*(char *)(DAT_600c3148 + 0x149) != '\0') {
    FUN_600c5f64(DAT_600c314c);
  }
  return;
}


