// 60095700  FUN_60095700  size=114 bytes
// --- callers ---
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_60095700(undefined2 param_1,int param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x20,DAT_60095774,0xda);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x20);
    *puVar1 = 0x1e06;
    puVar1[3] = param_1;
    puVar1[0xe] = param_3;
    *(undefined1 *)(puVar1 + 0xf) = param_4;
    if (param_2 != 0) {
      thunk_EXT_FUN_0000b572(puVar1 + 4,param_2,0x14);
    }
    FUN_600962dc(puVar1);
  }
  return;
}


