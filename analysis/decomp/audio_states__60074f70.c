// 60074f70  audio_states__60074f70  size=196 bytes
// src: audio_states.cc
// --- callers ---
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   60101b76 FUN_60101b76
//   60079c50 FUN_60079c50
//   6013d3c8 thunk_EXT_FUN_00001680
//   600da478 FUN_600da478
//   60101740 FUN_60101740


/* src: audio_states.cc */

undefined4 * audio_states__60074f70(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *local_c0;
  undefined1 auStack_bc [4];
  undefined4 *local_b8;
  undefined4 *local_b4;
  undefined4 *local_b0;
  undefined1 auStack_ac [4];
  undefined4 *local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 *puStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  FUN_60079c50(&local_c0);
  local_b8 = local_c0;
  local_b4 = local_b8;
  if (local_c0 != (undefined4 *)0x0) {
    local_b8 = (undefined4 *)0x0;
    local_b4 = (undefined4 *)0x0;
    puVar1 = (undefined4 *)thunk_EXT_FUN_0000b532(0xc);
    local_b0 = local_c0;
    FUN_600da478(auStack_ac,auStack_bc);
    *puVar1 = PTR_PTR_60075034;
    puVar1[1] = local_b0;
    FUN_600da478(puVar1 + 2,auStack_ac);
    if (local_b0 == (undefined4 *)0x0) {
      local_a8 = (undefined4 *)PTR_s_audio_states_cc_60075038;
      local_94 = 0;
      local_a4 = 0x226;
      local_a0 = local_92;
      local_93 = 0;
      local_92[0] = 0;
      local_9c = 0x80;
      puStack_98 = local_b0;
      FUN_60101b76(&local_a0,PTR_s_CHECK_failed_60122ce9_9_6007503c);
      FUN_60101740(&local_a8);
    }
    thunk_EXT_FUN_00001680(auStack_ac);
    local_a8 = (undefined4 *)0x0;
    puVar2 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
    puVar2[4] = puVar1;
    puVar2[1] = 1;
    puVar2[2] = 1;
    *puVar2 = PTR_DAT_60075040;
    local_a8 = local_b4;
    local_b8 = puVar1;
    local_b4 = puVar2;
    thunk_EXT_FUN_00001680(&local_a8);
  }
  *param_1 = local_b8;
  param_1[1] = local_b4;
  local_b4 = (undefined4 *)0x0;
  local_b8 = (undefined4 *)0x0;
  thunk_EXT_FUN_00001680(&local_b4);
  thunk_EXT_FUN_00001680(auStack_bc);
  return param_1;
}


