// 600af9a0  FUN_600af9a0  size=88 bytes
// --- callers ---
//   600f68f0 FUN_600f68f0
//   600f57f6 FUN_600f57f6
//   600ae2e8 FUN_600ae2e8
//   600ac524 FUN_600ac524
//   600f69f0 FUN_600f69f0
//   600f4ff4 FUN_600f4ff4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600af9a0(int param_1,undefined4 param_2)

{
  thunk_EXT_FUN_0000b572(param_1,DAT_600af9f8,0x10);
  *(char *)(param_1 + 0xc) = (char)param_2;
  *(char *)(param_1 + 0xd) = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + 0xe) = (char)((uint)param_2 >> 0x10);
  *(char *)(param_1 + 0xf) = (char)((uint)param_2 >> 0x18);
  return;
}


