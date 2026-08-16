// 600931a0  FUN_600931a0  size=92 bytes
// --- callers ---
//   6006c618 FUN_6006c618
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600931a0(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_600931fc,0x574);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x10);
    *puVar1 = 0x11a;
    FUN_600efcc6(puVar1 + 4,param_1);
    *(undefined1 *)((int)puVar1 + 0xf) = param_2;
    *(undefined1 *)(puVar1 + 7) = param_3;
    FUN_600962dc(puVar1);
  }
  return;
}


