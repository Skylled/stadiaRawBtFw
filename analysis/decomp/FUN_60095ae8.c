// 60095ae8  FUN_60095ae8  size=64 bytes
// --- callers ---
//   600efc1a FUN_600efc1a
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60095ae8(int param_1,undefined2 param_2)

{
  thunk_EXT_FUN_0000b572(param_1,DAT_60095b28,0x10);
  *(char *)(param_1 + 0xc) = (char)param_2;
  *(char *)(param_1 + 0xd) = (char)((ushort)param_2 >> 8);
  return;
}


