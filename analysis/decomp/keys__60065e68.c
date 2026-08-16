// 60065e68  keys__60065e68  size=66 bytes
// src: keys.cc
// --- callers ---
//   600666f0 keys__600666f0
// --- callees ---
//   60101b76 FUN_60101b76
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60065ccc FUN_60065ccc
//   60051120 FUN_60051120


/* src: keys.cc */

uint keys__60065e68(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [144];
  byte local_c;
  
  iVar1 = FUN_60065ccc();
  if (iVar1 == DAT_60065eac) {
    FUN_60051120(auStack_a4,DAT_60065eb0,0x32c,3);
    FUN_600d37ac(auStack_9c,DAT_60065eb4);
    uVar2 = (uint)local_c;
    FUN_600d37b8(auStack_a4);
  }
  else {
    uVar2 = FUN_60101b76(param_2,*(undefined4 *)(iVar1 + 8));
  }
  return uVar2;
}


