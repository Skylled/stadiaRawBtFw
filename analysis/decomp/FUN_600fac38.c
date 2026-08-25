// 600fac38  FUN_600fac38  size=140 bytes
// --- callers ---
// --- callees ---
//   600fa7de FUN_600fa7de
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848
//   600c1b74 FUN_600c1b74


void FUN_600fac38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_1c [16];
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  
  FUN_600fa7de(param_1,1,0,param_4,param_2);
  FUN_600c1b74(6,param_1);
  FUN_600c1b74(7,param_1);
  thunk_EXT_FUN_0000b572(auStack_1c,param_1 + 0x1c6,0x10);
  local_c = *(undefined2 *)(param_1 + 0x1d6);
  local_a = *(undefined1 *)(param_1 + 0x1b1);
  local_9 = *(undefined1 *)(param_1 + 0x2b);
  if (((*(byte *)(param_1 + 0x191) & 1) != 0) && ((*(byte *)(param_1 + 0x192) & 1) != 0)) {
    FUN_6009ad00(param_1 + 0x1d,0x10,auStack_1c,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


