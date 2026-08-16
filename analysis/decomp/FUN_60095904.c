// 60095904  FUN_60095904  size=132 bytes
// --- callers ---
//   6006ae20 gatt_server__6006ae20
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600962dc FUN_600962dc


void FUN_60095904(undefined2 param_1,undefined4 param_2,undefined1 param_3,int param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x276,DAT_60095988,0x1a5);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x276);
    *puVar1 = 0x1e0b;
    puVar1[3] = param_1;
    *(undefined4 *)(puVar1 + 4) = param_2;
    *(undefined1 *)(puVar1 + 6) = param_3;
    if (param_4 != 0) {
      *(undefined2 **)(puVar1 + 8) = puVar1 + 10;
      thunk_EXT_FUN_0000b572(*(undefined4 *)(puVar1 + 8),param_4,0x262);
    }
    FUN_600962dc(puVar1);
  }
  return;
}


