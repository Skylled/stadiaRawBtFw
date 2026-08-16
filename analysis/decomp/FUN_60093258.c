// 60093258  FUN_60093258  size=96 bytes
// --- callers ---
//   600d89ec adapter__600d89ec
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093258(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x44,DAT_600932b8,0x6a0);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x124;
    *(undefined4 *)(puVar1 + 4) = param_1;
    *(undefined4 *)(puVar1 + 8) = param_3;
    *(undefined2 **)(puVar1 + 6) = puVar1 + 0xc;
    thunk_EXT_FUN_0000b572(*(undefined4 *)(puVar1 + 6),param_2,0x2c);
    *(undefined1 *)(puVar1 + 10) = 0;
    FUN_600962dc(puVar1);
  }
  return;
}


