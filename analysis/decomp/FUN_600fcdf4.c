// 600fcdf4  FUN_600fcdf4  size=152 bytes
// --- callers ---
//   600c04c4 FUN_600c04c4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fcdf4(int param_1)

{
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [8];
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 auStack_1c [16];
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  
  thunk_EXT_FUN_0000b572(auStack_1c,param_1 + 0x1c6,0x10);
  local_c = 0;
  local_a = *(undefined1 *)(param_1 + 0x1b1);
  local_9 = *(undefined1 *)(param_1 + 0x2b);
  FUN_6009ad00(param_1 + 0x1d,0x10,auStack_1c,1);
  local_20 = 0;
  thunk_EXT_FUN_0000b5ba(auStack_28,0,8);
  thunk_EXT_FUN_0000b572(auStack_38,param_1 + 0x1c6,0x10);
  local_1e = *(undefined1 *)(param_1 + 0x2b);
  local_1d = *(undefined1 *)(param_1 + 0x1b1);
  FUN_6009ad00(param_1 + 0x1d,1,auStack_38,1);
  return;
}


