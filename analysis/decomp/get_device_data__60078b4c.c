// 60078b4c  get_device_data__60078b4c  size=134 bytes
// src: get_device_data.cc
// --- callers ---
//   60078be0 FUN_60078be0
// --- callees ---
//   600d6e14 FUN_600d6e14
//   600d736c FUN_600d736c
//   60101ba2 FUN_60101ba2
//   601016f0 FUN_601016f0
//   60065eb8 keys__60065eb8
//   60101b76 FUN_60101b76


/* src: get_device_data.cc */

void get_device_data__60078b4c(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *local_a0;
  int local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  iVar3 = FUN_600d6e14();
  if (iVar3 == 0) {
    *param_3 = 0;
  }
  else {
    cVar2 = keys__60065eb8(param_1,param_2,0x20);
    uVar1 = DAT_60078bd4;
    if (cVar2 == '\0') {
      *param_3 = 1;
    }
    else {
      local_94 = 0;
      local_a0 = local_92;
      local_93 = 0;
      local_92[0] = 0;
      local_9c = 0x80;
      iStack_98 = 0;
      FUN_60101b76(&local_a0,DAT_60078bd8);
      uVar4 = FUN_600d736c(param_1,local_a0 + iStack_98,local_9c - iStack_98);
      FUN_60101ba2(&local_a0,uVar4);
      FUN_60101b76(&local_a0,DAT_60078bdc);
      FUN_601016f0(0x28,uVar1,0x14,&local_a0);
      *param_3 = 0;
    }
  }
  return;
}


