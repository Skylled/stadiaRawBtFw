// 60058aa8  hid_input_target__60058aa8  size=172 bytes
// src: hid_input_target.cc
// --- callers ---
// --- callees ---
//   600ca560 FUN_600ca560
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   60101ba2 FUN_60101ba2
//   601016f0 FUN_601016f0
//   60101b76 FUN_60101b76
//   60050c18 FUN_60050c18


/* src: hid_input_target.cc */

void hid_input_target__60058aa8(undefined2 *param_1,uint param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  int local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  puVar2 = DAT_60058b5c;
  if (param_2 < 4) {
    local_a8 = DAT_60058b54;
    local_94 = 0;
    local_a4 = 0x8c;
    local_a0 = local_92;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    iStack_98 = 0;
    FUN_60101b76(&local_a0,DAT_60058b58);
    uVar3 = FUN_60050c18(param_2,0,local_a0 + iStack_98,local_9c - iStack_98);
    FUN_60101ba2(&local_a0,uVar3);
    FUN_601016f0(0x1e,local_a8,local_a4,&local_a0);
  }
  else {
    uVar1 = param_1[1];
    uVar5 = *(undefined4 *)(DAT_60058b5c + 2);
    *DAT_60058b5c = *param_1;
    puVar2[1] = uVar1;
    local_a8 = 0;
    uVar3 = FUN_600ca560();
    iVar4 = thunk_EXT_FUN_00007a2c(uVar5,6,uVar3,&local_a8,0);
    if ((iVar4 != 0) && (local_a8 != 0)) {
      *DAT_60058b60 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  return;
}


