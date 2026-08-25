// 600fb4d0  FUN_600fb4d0  size=110 bytes
// --- callers ---
// --- callees ---
//   600fa7de FUN_600fa7de
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848


void FUN_600fb4d0(int param_1,undefined4 param_2)

{
  undefined4 local_20;
  undefined1 auStack_1c [16];
  undefined1 local_c;
  
  FUN_600fa7de(param_1,4,1);
  local_c = *(undefined1 *)(param_1 + 0x2b);
  thunk_EXT_FUN_0000b572(auStack_1c,param_2,0x10);
  local_20 = 0;
  if (((*(byte *)(param_1 + 0x191) & 1) != 0) && ((*(byte *)(param_1 + 0x192) & 1) != 0)) {
    FUN_6009ad00(param_1 + 0x1d,4,&local_20,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


