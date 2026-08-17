// 60075d78  headphone_state_machine__60075d78  size=152 bytes
// src: headphone_state_machine.cc
// --- callers ---
//   600da7be FUN_600da7be
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2
//   600d37ac FUN_600d37ac
//   600cbb14 FUN_600cbb14
//   600d37b8 FUN_600d37b8
//   60101b76 FUN_60101b76


/* src: headphone_state_machine.cc */

bool headphone_state_machine__60075d78(float param_1,int param_2)

{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  byte local_ac [4];
  undefined *local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  int local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  uVar3 = VectorFloatToUnsigned(param_1 * DAT_60075e10,3);
  local_ac[0] = (**(code **)(**(int **)(param_2 + 0x78) + 0x1c))
                          (*(int **)(param_2 + 0x78),uVar3 & 0xffff);
  bVar2 = local_ac[0] == 0;
  if (!bVar2) {
    local_a8 = PTR_s_headphone_state_machine_cc_60075e14;
    local_a4 = 0x96;
    local_a0 = local_92;
    local_9c = 0x80;
    iStack_98 = 0;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    FUN_600d37ac(&local_a0,PTR_s_Failed_to_set_USB_volume_to_60075e18);
    uVar1 = FUN_60050c18(uVar3 & 0xffff,0,local_a0 + iStack_98,local_9c - iStack_98);
    FUN_60101ba2(&local_a0,uVar1);
    FUN_600d37ac(&local_a0,PTR_s_with_error_60075e1c);
    uVar1 = FUN_600cbb14(local_ac);
    FUN_60101b76(&local_a0,uVar1);
    FUN_600d37b8(&local_a8);
  }
  return bVar2;
}


