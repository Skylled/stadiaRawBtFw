// 60094f14  FUN_60094f14  size=64 bytes
// --- callers ---
//   600ef2da FUN_600ef2da
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60094f14(int param_1,undefined2 param_2)

{
  thunk_EXT_FUN_0000b572(param_1,DAT_60094f54,0x10);
  *(char *)(param_1 + 0xc) = (char)param_2;
  *(char *)(param_1 + 0xd) = (char)((ushort)param_2 >> 8);
  return;
}


