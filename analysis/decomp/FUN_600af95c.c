// 600af95c  FUN_600af95c  size=64 bytes
// --- callers ---
//   600f68f0 FUN_600f68f0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600af95c(int param_1,undefined2 param_2)

{
  thunk_EXT_FUN_0000b572(param_1,DAT_600af99c,0x10);
  *(char *)(param_1 + 0xc) = (char)param_2;
  *(char *)(param_1 + 0xd) = (char)((ushort)param_2 >> 8);
  return;
}


