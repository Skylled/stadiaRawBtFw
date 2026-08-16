// 60093310  FUN_60093310  size=68 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093310(undefined1 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_60093354,0x7bc);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,10);
    *puVar1 = 0x122;
    *(undefined1 *)(puVar1 + 4) = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


