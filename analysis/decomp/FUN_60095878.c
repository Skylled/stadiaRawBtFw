// 60095878  FUN_60095878  size=136 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600962dc FUN_600962dc


void FUN_60095878(undefined2 param_1,undefined2 param_2,short param_3,int param_4,undefined1 param_5
                 )

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x266,DAT_60095900,0x17d);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x266);
    *puVar1 = 0x1e04;
    puVar1[3] = param_1;
    puVar1[4] = param_2;
    *(undefined1 *)(puVar1 + 6) = param_5;
    if ((param_3 != 0) && (param_4 != 0)) {
      puVar1[5] = param_3;
      thunk_EXT_FUN_0000b572((int)puVar1 + 0xd,param_4,param_3);
    }
    FUN_600962dc(puVar1);
  }
  return;
}


