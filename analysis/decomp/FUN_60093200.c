// 60093200  FUN_60093200  size=82 bytes
// --- callers ---
//   6006c2f4 FUN_6006c2f4
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093200(undefined4 param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_60093254,0x5d1);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x10);
    *puVar1 = 0x11d;
    FUN_600efcc6(puVar1 + 4,param_1);
    *(undefined1 *)(puVar1 + 7) = param_2;
    FUN_600962dc(puVar1);
  }
  return;
}


