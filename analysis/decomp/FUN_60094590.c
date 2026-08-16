// 60094590  FUN_60094590  size=98 bytes
// --- callers ---
//   600c5ef4 FUN_600c5ef4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60094590(undefined1 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x12,DAT_600945f4,0x8e);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1d00;
    *(undefined1 *)(puVar1 + 7) = param_1;
    *(undefined1 *)((int)puVar1 + 0xf) = param_3;
    *(undefined1 *)(puVar1 + 8) = param_4;
    thunk_EXT_FUN_0000b572(puVar1 + 4,param_2,6);
    FUN_600962dc(puVar1);
  }
  return;
}


