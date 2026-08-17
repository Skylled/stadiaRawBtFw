// 60067ddc  logging__60067ddc  size=98 bytes
// src: logging.cc
// --- callers ---
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60101b76 FUN_60101b76
//   601016f0 FUN_601016f0
//   600d7fec FUN_600d7fec


/* src: logging.cc */

undefined4 logging__60067ddc(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *local_a0;
  int local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  uVar1 = DAT_60067e40;
  if (*(int *)(param_1 + 0x6c) != 0) {
    local_94 = 0;
    local_a0 = local_92;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    iStack_98 = 0;
    FUN_60101b76(&local_a0,*(undefined4 *)(param_1 + 8));
    uVar2 = FUN_600d7fec(param_1,local_a0 + iStack_98,local_9c - iStack_98);
    FUN_60101ba2(&local_a0,uVar2);
    FUN_601016f0(0x14,uVar1,0x28,&local_a0);
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return 0;
}


