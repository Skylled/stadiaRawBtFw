// 6007edf4  recording_pipeline__6007edf4  size=392 bytes
// src: recording_pipeline.cc
// src: stereo_to_mono_receiver.h
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6013d3c8 thunk_EXT_FUN_00001680
//   6007ec78 FUN_6007ec78
//   600da48a FUN_600da48a
//   6005e12c FUN_6005e12c
//   60101b76 FUN_60101b76
//   6007f540 receiver__6007f540
//   6010165c FUN_6010165c
//   60051120 FUN_60051120
//   6013d378 thunk_EXT_FUN_0000b532
//   600d37b8 FUN_600d37b8
//   600da478 FUN_600da478


/* src: recording_pipeline.cc
   src: stereo_to_mono_receiver.h */

void recording_pipeline__6007edf4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int *piVar7;
  int local_d4;
  undefined1 auStack_d0 [4];
  undefined4 *local_cc;
  undefined4 *local_c8;
  undefined4 *local_c4;
  undefined1 auStack_c0 [4];
  undefined4 *local_bc;
  undefined1 auStack_b8 [4];
  undefined1 auStack_b4 [152];
  
  local_bc = (undefined4 *)*param_3;
  FUN_600da478(auStack_b8,param_3 + 1);
  receiver__6007f540(&local_d4,&local_bc);
  thunk_EXT_FUN_00001680(auStack_b8);
  if (local_d4 == 0) {
    uVar5 = 0x2e;
    puVar6 = PTR_s_Failed_to_start_SPI_task_6007ef7c;
  }
  else {
    if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
      local_c4 = (undefined4 *)*param_2;
      FUN_600da478(auStack_c0,param_2 + 1);
      puVar3 = local_c4;
      if (local_c4 == (undefined4 *)0x0) {
        FUN_6010165c(0x28,PTR_s_stereo_to_mono_receiver_h_6007ef8c,0x35,
                     PTR_s_Cannot_create_stereo_to_mono_sin_6007ef88);
        local_cc = puVar3;
        local_c8 = puVar3;
      }
      else {
        local_cc = (undefined4 *)0x0;
        local_c8 = (undefined4 *)0x0;
        puVar3 = (undefined4 *)thunk_EXT_FUN_0000b532(0x10);
        local_bc = local_c4;
        FUN_600da478(auStack_b8,auStack_c0);
        *puVar3 = PTR_DAT_6007ef98;
        puVar3[1] = local_bc;
        FUN_600da478(puVar3 + 2,auStack_b8);
        puVar3[3] = 2;
        thunk_EXT_FUN_00001680(auStack_b8);
        local_bc = (undefined4 *)0x0;
        puVar4 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
        puVar4[4] = puVar3;
        puVar4[1] = 1;
        puVar4[2] = 1;
        *puVar4 = PTR_PTR_6007ef9c;
        local_bc = local_c8;
        local_cc = puVar3;
        local_c8 = puVar4;
        thunk_EXT_FUN_00001680(&local_bc);
      }
      thunk_EXT_FUN_00001680(auStack_c0);
      local_c4 = local_cc;
      FUN_600da478(auStack_c0,&local_c8);
      local_bc = (undefined4 *)*param_2;
      FUN_600da478(auStack_b8,param_2 + 1);
      *(undefined4 **)(local_d4 + 0x9a0) = local_c4;
      FUN_600da48a(local_d4 + 0x9a4,auStack_c0);
      *(undefined4 **)(local_d4 + 0x9a8) = local_bc;
      FUN_600da48a(local_d4 + 0x9ac,auStack_b8);
      thunk_EXT_FUN_00001680(auStack_b8);
      thunk_EXT_FUN_00001680(auStack_c0);
      puVar3 = local_c8;
      *(undefined4 **)(param_1 + 8) = local_cc;
      if (local_c8 != (undefined4 *)0x0) {
        if (PTR_FUN_600ee062_1_6007ef90 == (undefined *)0x0) {
          local_c8[2] = local_c8[2] + 1;
        }
        else {
          piVar7 = local_c8 + 2;
          DataMemoryBarrier(0x1b);
          do {
            ExclusiveAccess(piVar7);
            bVar1 = (bool)hasExclusiveAccess(piVar7);
          } while (!bVar1);
          *piVar7 = *piVar7 + 1;
          DataMemoryBarrier(0x1b);
        }
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        FUN_6005e12c();
      }
      *(undefined4 **)(param_1 + 0xc) = puVar3;
      uVar2 = FUN_6007ec78(param_1);
      if ((uVar2 & 0xff) != 0) {
        FUN_60051120(&local_bc,PTR_s_recording_pipeline_cc_6007ef80,0x3b,uVar2);
        FUN_60101b76(auStack_b4,PTR_s_Failed_to_update_audio_source_6007ef94);
        FUN_600d37b8(&local_bc);
      }
      thunk_EXT_FUN_00001680(&local_c8);
      goto LAB_6007ee2e;
    }
    uVar5 = 0x32;
    puVar6 = PTR_s_No_target_for_recording_pipeline_6007ef84;
  }
  FUN_6010165c(0x28,PTR_s_recording_pipeline_cc_6007ef80,uVar5,puVar6);
LAB_6007ee2e:
  thunk_EXT_FUN_00001680(auStack_d0);
  return;
}


