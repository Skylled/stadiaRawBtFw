// 60092fb4  FUN_60092fb4  size=204 bytes
// --- callers ---
//   6006c618 FUN_6006c618
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092fb4(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined1 param_5,
                 undefined1 param_6,undefined1 param_7)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_60093080,0x30c);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x140);
    *puVar1 = 0x10a;
    FUN_600efcc6(puVar1 + 4,param_1);
    *(undefined4 *)(puVar1 + 0x12) = param_4;
    *(undefined1 *)(puVar1 + 0x14) = param_5;
    *(undefined1 *)(puVar1 + 0x15) = param_7;
    if (param_3 != 0) {
      *(undefined1 *)((int)puVar1 + 0x2b) = 1;
      *(undefined1 *)((int)puVar1 + 0x29) = param_6;
      thunk_EXT_FUN_0000b572((int)puVar1 + 0x11,param_3,0x10);
    }
    if (param_2 != 0) {
      *(undefined1 *)(puVar1 + 0x16) = 1;
      thunk_EXT_FUN_0000b572(puVar1 + 7,param_2,3);
    }
    thunk_EXT_FUN_0000b5ba((int)puVar1 + 0x2d,0,0xf9);
    thunk_EXT_FUN_0000b5ba(puVar1 + 0x93,0,0x18);
    FUN_600962dc(puVar1);
  }
  return;
}


