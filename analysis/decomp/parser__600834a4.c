// 600834a4  parser__600834a4  size=136 bytes
// src: parser.cc
// --- callers ---
//   600d4664 FUN_600d4664
// --- callees ---
//   60101ba2 FUN_60101ba2
//   601016f0 FUN_601016f0
//   600edcd6 FUN_600edcd6
//   60101b76 FUN_60101b76
//   60101b0c FUN_60101b0c
//   600edfcc FUN_600edfcc


/* src: parser.cc */

undefined4 parser__600834a4(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_b4 [12];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  int local_9c;
  int local_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  FUN_600edfcc(auStack_b4);
  iVar1 = FUN_600edcd6(auStack_b4,*param_1,param_1[1],param_1[2],param_1[3]);
  param_1[4] = iVar1;
  if (iVar1 < 0) {
    local_a8 = DAT_6008352c;
    local_94 = 0;
    local_a4 = 0x1f;
    local_a0 = local_92;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    local_98 = 0;
    FUN_60101b76(&local_a0,DAT_60083530);
    uVar2 = FUN_60101b0c(param_1[4],(int)param_1[4] >> 0x1f,local_a0 + local_98,local_9c - local_98)
    ;
    FUN_60101ba2(&local_a0,uVar2);
    FUN_601016f0(0x28,local_a8,local_a4,&local_a0);
    iVar1 = param_1[4];
    param_1[4] = 0;
    if (iVar1 == -1) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0xf;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


