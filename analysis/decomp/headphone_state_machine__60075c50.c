// 60075c50  headphone_state_machine__60075c50  size=270 bytes
// src: headphone_state_machine.cc
// --- callers ---
//   600da7be FUN_600da7be
// --- callees ---
//   600d37ac FUN_600d37ac
//   600da67e FUN_600da67e
//   600d37b8 FUN_600d37b8


/* src: headphone_state_machine.cc */

undefined4 headphone_state_machine__60075c50(float param_1,int param_2)

{
  char cVar1;
  float fVar2;
  float local_b8;
  float local_b4;
  undefined *local_b0;
  undefined4 local_ac;
  byte *local_a8;
  undefined4 local_a4;
  uint uStack_a0;
  byte local_9c;
  byte local_9b;
  byte local_9a [134];
  
  local_9c = (**(code **)(**(int **)(param_2 + 0x78) + 0x14))
                       (*(int **)(param_2 + 0x78),&local_b8,&local_b4);
  uStack_a0 = (uint)local_9c;
  if (uStack_a0 == 0) {
    if (local_b4 - local_b8 <= 0.0) {
      local_b0 = PTR_s_headphone_state_machine_cc_60075d64;
      local_ac = 0x88;
      local_a8 = local_9a;
      local_a4 = 0x80;
      local_9b = local_9c;
      local_9a[0] = local_9c;
      FUN_600d37ac(&local_a8,PTR_s_Failed_to_set_sound_codec_volume_60075d6c);
      FUN_600da67e(local_b4,&local_a8);
      FUN_600d37ac(&local_a8,PTR_s___min_volume_db___60075d70);
    }
    else {
      fVar2 = DAT_60075d60;
      if (param_1 != 0.0) {
        fVar2 = local_b8 + (local_b4 - local_b8) * param_1;
      }
      cVar1 = (**(code **)(**(int **)(param_2 + 0x78) + 0x18))(fVar2);
      if (cVar1 == '\0') {
        return 1;
      }
      local_b0 = PTR_s_headphone_state_machine_cc_60075d64;
      local_9c = 0;
      local_ac = 0x85;
      local_a8 = local_9a;
      local_9b = 0;
      local_9a[0] = 0;
      local_a4 = 0x80;
      uStack_a0 = 0;
      FUN_600d37ac(&local_a8,PTR_s_Failed_to_set_sound_codec_volume_60075d68);
      local_b8 = fVar2;
    }
    FUN_600da67e(local_b8,&local_a8);
  }
  else {
    local_b0 = PTR_s_headphone_state_machine_cc_60075d64;
    local_9c = 0;
    local_ac = 0x8d;
    local_a8 = local_9a;
    local_9b = 0;
    local_9a[0] = 0;
    local_a4 = 0x80;
    uStack_a0 = 0;
    FUN_600d37ac(&local_a8,PTR_s_Failed_to_get_sound_codec_volume_60075d74);
  }
  FUN_600d37b8(&local_b0);
  return 0;
}


