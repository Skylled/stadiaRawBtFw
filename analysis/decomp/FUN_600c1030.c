// 600c1030  FUN_600c1030  size=112 bytes
// --- callers ---
//   600c0f34 FUN_600c0f34
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c8798 FUN_600c8798
//   600c1a34 FUN_600c1a34


void FUN_600c1030(int param_1)

{
  undefined1 auStack_88 [32];
  undefined1 auStack_68 [32];
  undefined1 auStack_48 [64];
  
  thunk_EXT_FUN_0000b572(auStack_88,param_1 + 0x6d,0x20);
  FUN_600c8798(auStack_68,DAT_600c10a0,auStack_88,8);
  thunk_EXT_FUN_0000b572(param_1 + 0x10d,auStack_68,0x20);
  thunk_EXT_FUN_0000b572(param_1 + 0x12d,auStack_48,0x20);
  *(ushort *)(param_1 + 0x28) = *(ushort *)(param_1 + 0x28) | 0x100;
  FUN_600c1a34(param_1,0x1c,0);
  return;
}


