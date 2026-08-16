// 60093358  FUN_60093358  size=104 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093358(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x18,DAT_600933c0,0x7e6);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x18);
    *puVar1 = 0x114;
    thunk_EXT_FUN_0000b572((int)puVar1 + 0x11,param_1,6);
    *(undefined1 *)(puVar1 + 4) = param_2;
    *(undefined4 *)(puVar1 + 6) = param_3;
    *(undefined1 *)(puVar1 + 8) = param_4;
    FUN_600962dc(puVar1);
  }
  return;
}


