// 60095778  FUN_60095778  size=110 bytes
// --- callers ---
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600962dc FUN_600962dc


void FUN_60095778(undefined2 param_1,undefined2 param_2,int param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x20,DAT_600957e8,0x104);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x20);
    *puVar1 = 0x1e07;
    puVar1[3] = param_1;
    puVar1[0xe] = param_2;
    if (param_3 != 0) {
      thunk_EXT_FUN_0000b572(puVar1 + 4,param_3,0x14);
    }
    FUN_600962dc(puVar1);
  }
  return;
}


