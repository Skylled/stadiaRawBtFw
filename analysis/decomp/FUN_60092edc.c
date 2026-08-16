// 60092edc  FUN_60092edc  size=120 bytes
// --- callers ---
//   600d89a6 FUN_600d89a6
//   600d88d6 FUN_600d88d6
//   600d890c FUN_600d890c
//   6006c57c FUN_6006c57c
//   60069780 adapter__60069780
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092edc(undefined2 param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_60092f54,0xe0);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x103;
    puVar1[4] = param_1;
    puVar1[5] = param_2;
    *(undefined1 *)(puVar1 + 6) = param_3;
    *(undefined1 *)((int)puVar1 + 0xd) = param_4;
    FUN_600962dc(puVar1);
    *DAT_60092f58 = param_1;
    *DAT_60092f5c = param_2;
    *DAT_60092f60 = param_3;
    *DAT_60092f64 = param_4;
  }
  return;
}


