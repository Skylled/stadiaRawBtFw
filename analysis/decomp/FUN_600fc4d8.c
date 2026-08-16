// 600fc4d8  FUN_600fc4d8  size=106 bytes
// --- callers ---
//   600fb9d2 FUN_600fb9d2
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c8798 FUN_600c8798


void FUN_600fc4d8(int param_1)

{
  undefined1 auStack_e8 [32];
  undefined1 auStack_c8 [96];
  undefined1 auStack_68 [32];
  undefined1 auStack_48 [64];
  
  thunk_EXT_FUN_0000b572(auStack_e8,param_1 + 0x6d,0x20);
  thunk_EXT_FUN_0000b572(auStack_68,param_1 + 0x14d,0x20);
  thunk_EXT_FUN_0000b572(auStack_48,param_1 + 0x16d,0x20);
  FUN_600c8798(auStack_c8,auStack_68,auStack_e8,8);
  thunk_EXT_FUN_0000b572(param_1 + 0x8d,auStack_c8,0x20);
  return;
}


