// 600c4320  FUN_600c4320  size=142 bytes
// --- callers ---
//   600c424c FUN_600c424c
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600a4010 FUN_600a4010
//   601024d8 FUN_601024d8
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac
//   600f34ac FUN_600f34ac


void FUN_600c4320(int param_1)

{
  undefined2 *puVar1;
  
  *(undefined1 *)(DAT_600c43b0 + 0x20) = 1;
  FUN_601024d8(DAT_600c43b4,param_1 + 10,0xf8);
  *(undefined1 *)(DAT_600c43b0 + 0x119) = 0;
  FUN_600a4010(DAT_600c43b8);
  if (*(char *)(DAT_600c43b0 + 0x140) == '\x02') {
    FUN_600f34ac(DAT_600c43bc);
  }
  puVar1 = (undefined2 *)FUN_6006dbac(0x11c,DAT_600c43c0,0xa25);
  if (puVar1 != (undefined2 *)0x0) {
    FUN_600efcc6(puVar1 + 4,DAT_600c43bc);
    FUN_601024d8(puVar1 + 7,param_1 + 10,0xf8);
    *(undefined1 *)(puVar1 + 0x83) = 0;
    *puVar1 = 0x204;
    FUN_600962dc(puVar1);
  }
  return;
}


