// 60092920  FUN_60092920  size=74 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092920(undefined1 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_6009296c,0x2c0);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,10);
    *puVar1 = 0x12a;
    puVar1[3] = 1;
    *(undefined1 *)(puVar1 + 4) = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


