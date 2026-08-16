// 600945f8  FUN_600945f8  size=84 bytes
// --- callers ---
//   600c2b3c FUN_600c2b3c
//   600c5f64 FUN_600c5f64
//   600c4da8 FUN_600c4da8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600945f8(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x12,DAT_6009464c,0xae);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1d02;
    *(undefined1 *)(puVar1 + 7) = param_1;
    *(undefined1 *)((int)puVar1 + 0xf) = param_3;
    thunk_EXT_FUN_0000b572(puVar1 + 4,param_2,6);
    FUN_600962dc(puVar1);
  }
  return;
}


