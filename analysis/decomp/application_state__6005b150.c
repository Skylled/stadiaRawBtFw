// 6005b150  application_state__6005b150  size=102 bytes
// src: application_state.cc
// --- callers ---
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   600d382e FUN_600d382e
//   60101b76 FUN_60101b76
//   600cbb14 FUN_600cbb14
//   6006180c info__6006180c
//   600d3b3a FUN_600d3b3a
//   600d6e14 FUN_600d6e14


/* src: application_state.cc */

bool application_state__6005b150(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  byte local_b0 [4];
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [148];
  
  iVar2 = FUN_600d6e14(0x28);
  bVar4 = false;
  if (iVar2 != 0) {
    local_ac = 0;
    bVar1 = FUN_600d382e(0x28,&local_ac);
    if (bVar1 == 0) {
      iVar2 = info__6006180c();
      bVar4 = local_ac == iVar2;
    }
    else {
      local_a8 = DAT_6005b1b8;
      local_a4 = 0x101;
      FUN_600d3b3a(auStack_a0);
      FUN_600d37ac(auStack_a0,DAT_6005b1bc);
      local_b0[0] = bVar1;
      uVar3 = FUN_600cbb14(local_b0);
      FUN_60101b76(auStack_a0,uVar3);
      FUN_600d37b8(&local_a8);
      bVar4 = false;
    }
  }
  return bVar4;
}


