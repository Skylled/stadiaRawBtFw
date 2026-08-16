// 60093138  FUN_60093138  size=100 bytes
// --- callers ---
//   6006c618 FUN_6006c618
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093138(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x30,DAT_6009319c,0x551);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x30);
    *puVar1 = 0x119;
    *(undefined1 *)(puVar1 + 0x16) = param_3;
    FUN_600efcc6(puVar1 + 4,param_1);
    thunk_EXT_FUN_0000b572(puVar1 + 8,param_2,0x1c);
    FUN_600962dc(puVar1);
  }
  return;
}


