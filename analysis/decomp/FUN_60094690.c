// 60094690  FUN_60094690  size=118 bytes
// --- callers ---
//   600c5cd8 FUN_600c5cd8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60094690(undefined2 param_1,int param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x20,DAT_60094708,0x106);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x20);
    *puVar1 = 0x1d09;
    puVar1[3] = param_1;
    if (param_2 == 0) {
      *(undefined4 *)(puVar1 + 4) = 0;
    }
    else {
      *(undefined2 **)(puVar1 + 4) = puVar1 + 6;
      thunk_EXT_FUN_0000b572(*(undefined4 *)(puVar1 + 4),param_2,0x14);
    }
    FUN_600962dc(puVar1);
  }
  return;
}


