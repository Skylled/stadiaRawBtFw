// 600c5db0  FUN_600c5db0  size=232 bytes
// --- callers ---
//   600c5fa4 FUN_600c5fa4
//   600c5f64 FUN_600c5f64
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600c54ec FUN_600c54ec
//   601024d8 FUN_601024d8
//   600962dc FUN_600962dc
//   600c5cd8 FUN_600c5cd8
//   6006dbac FUN_6006dbac
//   60096314 FUN_60096314


void FUN_600c5db0(short param_1,char param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if (*(char *)(DAT_600c5e98 + 0x148) != '\0') {
    *(char *)(DAT_600c5e98 + 0x148) = *(char *)(DAT_600c5e98 + 0x148) + -1;
  }
  if ((param_2 == '\0') && (*(char *)(DAT_600c5e98 + 0x148) != '\0')) {
    FUN_600c5cd8(param_1);
  }
  else {
    *(undefined1 *)(DAT_600c5e98 + 0x148) = 0;
    puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c5e9c,0x1713);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = 0x207;
      *(bool *)(puVar1 + 0x86) = param_2 != '\0';
      *(undefined4 *)(puVar1 + 0x84) = *(undefined4 *)(DAT_600c5e98 + 0x10);
      FUN_600efcc6(puVar1 + 4,DAT_600c5ea0);
      uVar2 = FUN_600c54ec();
      FUN_601024d8(puVar1 + 7,uVar2,0xf8);
      *(undefined1 *)(puVar1 + 0x83) = 0;
      FUN_600962dc(puVar1);
    }
    if (param_1 != -1) {
      FUN_60096314(DAT_600c5ea4,0x209,1000);
      FUN_600efcc6(DAT_600c5ea8,DAT_600c5ea0);
    }
    *(undefined1 *)(DAT_600c5e98 + 0x149) = 0;
  }
  return;
}


