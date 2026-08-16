// 60075088  audio_states__60075088  size=1892 bytes
// src: audio_states.cc
// --- callers ---
// --- callees ---
//   60066370 keys__60066370
//   600d4550 FUN_600d4550
//   6010165c FUN_6010165c
//   6007ed74 recording_pipeline__6007ed74
//   6007ad34 usb_audio_send__6007ad34
//   600cbb14 FUN_600cbb14
//   6007ec20 FUN_6007ec20
//   600d4e64 FUN_600d4e64
//   600da48a FUN_600da48a
//   600da478 FUN_600da478
//   60101740 FUN_60101740
//   60074c2c audio_states__60074c2c
//   6007b1b8 synapse_audio_processor__6007b1b8
//   6007a998 usb_audio_receive__6007a998
//   60101b76 FUN_60101b76
//   6010244e FUN_6010244e
//   60074c08 FUN_60074c08
//   6005a9fc FUN_6005a9fc
//   6013d3c8 thunk_EXT_FUN_00001680
//   60079d28 audio_tasks__60079d28
//   601016f0 FUN_601016f0
//   6007edf4 recording_pipeline__6007edf4
//   600da424 FUN_600da424
//   60074ef4 FUN_60074ef4


/* src: audio_states.cc */

void audio_states__60075088(byte *param_1)

{
  byte bVar1;
  byte **ppbVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  byte **ppbVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 uVar11;
  byte **local_138;
  undefined1 auStack_134 [4];
  byte **local_130;
  undefined1 auStack_12c [4];
  byte **local_128;
  undefined1 auStack_124 [4];
  byte **local_120;
  undefined1 auStack_11c [4];
  byte **local_118;
  undefined4 uStack_114;
  byte **local_110;
  undefined4 uStack_10c;
  byte **local_108;
  undefined4 uStack_104;
  byte **local_100;
  undefined1 auStack_fc [4];
  byte **local_f8;
  undefined1 auStack_f4 [4];
  undefined4 local_f0;
  uint local_ec;
  byte **local_e8;
  byte **ppbStack_e4;
  byte **local_e0;
  undefined1 auStack_dc [4];
  byte **local_d8;
  undefined1 auStack_d4 [4];
  byte **local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [16];
  byte **local_b8;
  int local_b4;
  byte *local_b0;
  undefined4 local_ac;
  byte **ppbStack_a8;
  byte local_a4;
  byte local_a3;
  byte local_a2 [130];
  
  puVar10 = PTR_s_audio_states_cc_60075274;
  bVar1 = *param_1;
  if ((byte **)(uint)bVar1 != (byte **)0x0) goto LAB_6007545a;
  FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0x304,PTR_s_Setting_up_usb_audio_source_60075278)
  ;
  usb_audio_receive__6007a998(&local_138);
  if (local_138 == (byte **)0x0) {
    local_b8 = (byte **)puVar10;
    local_b4 = 0x306;
    local_b0 = local_a2;
    local_ac = 0x80;
    ppbStack_a8 = (byte **)(uint)bVar1;
    local_a4 = bVar1;
    local_a3 = bVar1;
    local_a2[0] = bVar1;
    FUN_60101b76(&local_b0,PTR_s_CHECK_failed_60122ce9_9_6007527c);
    FUN_60074c08(&local_b8,PTR_s_Audio_source_could_not_be_create_60075280);
    FUN_60101740(&local_b8);
  }
  usb_audio_send__6007ad34(&local_130);
  if (local_130 == (byte **)0x0) {
    local_a4 = 0;
    local_b4 = 0x309;
    local_b0 = local_a2;
    local_a3 = 0;
    local_a2[0] = 0;
    local_b8 = (byte **)puVar10;
    local_ac = 0x80;
    ppbStack_a8 = local_130;
    FUN_60101b76(&local_b0,PTR_s_CHECK_failed_60122ce9_9_6007527c);
    FUN_60074c08(&local_b8,PTR_s_Audio_sink_could_not_be_created__60075284);
    FUN_60101740(&local_b8);
  }
  local_120 = local_138;
  FUN_600da478(auStack_11c,auStack_134);
  local_128 = local_130;
  FUN_600da478(auStack_124,auStack_12c);
  local_100 = local_120;
  local_118 = (byte **)0x0;
  uStack_114 = 0;
  local_110 = (byte **)0x0;
  uStack_10c = 0;
  local_108 = (byte **)0x0;
  uStack_104 = 0;
  FUN_600da478(auStack_fc,auStack_11c);
  local_f8 = local_128;
  FUN_600da478(auStack_f4,auStack_124);
  local_d0 = (byte **)local_c8;
  local_c8[0] = 0;
  local_cc = 0;
  cVar3 = keys__60066370(0xf,0x18,&local_d0);
  if (cVar3 != '\0') {
    FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xbc,
                 PTR_s_No_AEC_setting_forced__Using__Sy_60075288);
    FUN_6005a9fc(&local_d0,0,local_cc,PTR_s_Synapse_6007528c,7);
  }
  ppbVar2 = local_d0;
  iVar4 = FUN_6010244e(local_d0,PTR_s_Synapse_6007528c);
  if (iVar4 == 0) {
    local_b8 = &local_b0;
    local_b0 = (byte *)((uint)local_b0 & 0xffffff00);
    local_b4 = iVar4;
    FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xc3,PTR_s_Using__Synapse__AEC_60075290);
    cVar3 = keys__60066370(0x10,0x1e,&local_b8);
    ppbVar2 = local_b8;
    if ((cVar3 == '\0') &&
       (iVar4 = FUN_6010244e(local_b8,PTR_s_SettingsDefault_60075294), iVar4 != 0)) {
      iVar4 = FUN_6010244e(ppbVar2,DAT_600752a8);
      if (iVar4 == 0) {
        FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xd1,DAT_600752ac);
        uVar11 = 1;
      }
      else {
        iVar4 = FUN_6010244e(ppbVar2,DAT_600752b0);
        uVar11 = 0;
        if (iVar4 == 0) {
          FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xd5,DAT_600752b4);
          uVar11 = 2;
        }
      }
    }
    else {
      uVar11 = 0;
      FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xcd,
                   PTR_s_Using_default_Synapse_parameters_60075298);
    }
    local_ec = 0;
    local_f0 = 0x10000;
    cVar3 = keys__60066370(0x11,0x19,&local_b8);
    ppbVar2 = local_b8;
    if ((cVar3 == '\0') && (iVar4 = FUN_6010244e(local_b8,DAT_6007529c), iVar4 != 0)) {
      iVar4 = FUN_6010244e(ppbVar2,DAT_600752a0);
      if (iVar4 == 0) {
        FUN_6010165c(0x14,PTR_s_audio_states_cc_60075274,0xe5,DAT_600752a4);
        local_f0 = local_f0 & 0xffffff00;
      }
      else {
        iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_600755bc);
        if (iVar4 != 0) {
          iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_600755c4);
          if (iVar4 == 0) {
            FUN_6010165c(0x14,DAT_6007559c,0xed,PTR_s_Creating_the_Synapse_AEC_and_AGC_600755c8);
            local_f0 = CONCAT22((short)(local_f0 >> 0x10),0x100);
          }
          goto LAB_600752ce;
        }
        FUN_6010165c(0x14,DAT_6007559c,0xe9,PTR_s_Creating_the_Synapse_AEC_and_NS__600755c0);
        local_f0 = CONCAT31(local_f0._1_3_,1);
      }
      local_f0._0_2_ = (ushort)(byte)local_f0;
    }
    else {
      FUN_6010165c(0x14,DAT_6007559c,0xe1,DAT_60075598);
      local_f0 = CONCAT22(local_f0._2_2_,0x101);
    }
LAB_600752ce:
    cVar3 = keys__60066370(0x12,0x1b,&local_b8);
    ppbVar2 = local_b8;
    if ((cVar3 != '\0') || (iVar4 = FUN_6010244e(local_b8,DAT_600755a0), iVar4 == 0)) {
      FUN_6010165c(0x14,DAT_6007559c,0xf9,PTR_s_From_call_start_the_Synapse_AEC_i_600755a8);
      if ((byte)local_f0 == '\0') {
        uVar5 = 0xff;
        puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_600755d4;
      }
      else {
        uVar5 = 0xfb;
        puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_600755cc;
      }
      FUN_6010165c(0x14,DAT_6007559c,uVar5,puVar9);
      if (local_f0._1_1_ == '\0') {
        uVar5 = 0x106;
        puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600755d8;
      }
      else {
        uVar5 = 0x102;
        puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600755d0;
      }
      FUN_6010165c(0x14,DAT_6007559c,uVar5,puVar9);
      local_f0._0_3_ = CONCAT12(1,(ushort)local_f0);
LAB_600754de:
      uVar8 = 1;
      local_f0 = CONCAT13(1,(uint3)local_f0);
      goto LAB_600754e2;
    }
    iVar4 = FUN_6010244e(ppbVar2,PTR_LAB_6011fbd8_1_600755a4);
    if (iVar4 == 0) {
      FUN_6010165c(0x14,DAT_6007559c,0x10c,PTR_s_From_call_start_the_Synapse_AEC_i_600755a8);
      FUN_6010165c(0x14,DAT_6007559c,0x10d,PTR_s_From_call_start_the_Synapse_NS_i_600755ac);
      FUN_6010165c(0x14,DAT_6007559c,0x10e,PTR_s_From_call_start_the_Synapse_AGC_i_600755b0);
      local_f0._0_3_ = CONCAT12(1,(short)local_f0);
      local_f0 = (uint)(uint3)local_f0;
      local_ec = local_ec & 0xffffff00;
    }
    else {
      iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_600755dc);
      if (iVar4 == 0) {
        FUN_6010165c(0x14,DAT_6007559c,0x113,PTR_s_From_call_start_the_Synapse_AEC_i_600755e0);
        if ((byte)local_f0 == '\0') {
          uVar5 = 0x119;
          puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_600755d4;
        }
        else {
          uVar5 = 0x115;
          puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_600755cc;
        }
        FUN_6010165c(0x14,DAT_6007559c,uVar5,puVar9);
        FUN_6010165c(0x14,DAT_6007559c,0x11b,PTR_s_From_call_start_the_Synapse_AGC_i_600755b0);
        uVar8 = 0;
        uVar7 = 1;
        local_f0 = local_f0 & 0xffff;
LAB_60075538:
        local_f0 = CONCAT13(uVar7,(uint3)local_f0);
      }
      else {
        iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_600755e4);
        if (iVar4 == 0) {
          FUN_6010165c(0x14,DAT_6007559c,0x120,PTR_s_From_call_start_the_Synapse_AEC_i_600755e0);
          FUN_6010165c(0x14,DAT_6007559c,0x121,PTR_s_From_call_start_the_Synapse_NS_i_600755ac);
          if (local_f0._1_1_ == '\0') {
            uVar5 = 0x127;
            puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600755d8;
          }
          else {
            uVar5 = 0x123;
            puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600755d0;
          }
          FUN_6010165c(0x14,DAT_6007559c,uVar5,puVar9);
          local_f0._0_3_ = (uint3)local_f0 & 0xffff;
          local_f0 = (uint)(uint3)local_f0;
          uVar8 = 1;
        }
        else {
          iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_60075884);
          if (iVar4 != 0) {
            iVar4 = FUN_6010244e(ppbVar2,PTR_DAT_6007589c);
            if (iVar4 != 0) {
              iVar4 = FUN_6010244e(ppbVar2,DAT_600758ac);
              if (iVar4 == 0) {
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x147,DAT_600758b0);
                if ((byte)local_f0 == '\0') {
                  uVar5 = 0x14d;
                  puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_60075898;
                }
                else {
                  uVar5 = 0x149;
                  puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_60075890;
                }
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,uVar5,puVar9);
                if (local_f0._1_1_ == '\0') {
                  uVar5 = 0x154;
                  puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600758a8;
                }
                else {
                  uVar5 = 0x150;
                  puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600758a4;
                }
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,uVar5,puVar9);
                local_f0._0_3_ = (uint3)(ushort)local_f0;
                goto LAB_600754de;
              }
              iVar4 = FUN_6010244e(ppbVar2,DAT_600758b4);
              if (iVar4 == 0) {
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x15a,DAT_600758b0);
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x15b,
                             PTR_s_From_call_start_the_Synapse_NS_i_600758a0);
                FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x15c,
                             PTR_s_From_call_start_the_Synapse_AGC_i_60075894);
                local_f0._0_3_ = (uint3)local_f0 & 0xffff;
                local_f0 = (uint)(uint3)local_f0;
                local_ec = local_ec & 0xffffff00;
              }
              goto LAB_60075338;
            }
            FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x13a,
                         PTR_s_From_call_start_the_Synapse_AEC_i_60075888);
            FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x13b,
                         PTR_s_From_call_start_the_Synapse_NS_i_600758a0);
            if (local_f0._1_1_ == '\0') {
              uVar5 = 0x141;
              puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600758a8;
            }
            else {
              uVar5 = 0x13d;
              puVar9 = PTR_s_From_call_start_the_Synapse_AGC_i_600758a4;
            }
            FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,uVar5,puVar9);
            uVar8 = 1;
            uVar7 = 0;
            local_f0._0_3_ = CONCAT12(1,(ushort)local_f0);
            local_f0 = (uint)(uint3)local_f0;
            goto LAB_60075538;
          }
          FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x12d,
                       PTR_s_From_call_start_the_Synapse_AEC_i_60075888);
          if ((byte)local_f0 == '\0') {
            uVar5 = 0x133;
            puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_60075898;
          }
          else {
            uVar5 = 0x12f;
            puVar9 = PTR_s_From_call_start_the_Synapse_NS_i_60075890;
          }
          FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,uVar5,puVar9);
          FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x135,
                       PTR_s_From_call_start_the_Synapse_AGC_i_60075894);
          local_f0._0_3_ = CONCAT12(1,(ushort)local_f0);
          local_f0 = CONCAT13(1,(uint3)local_f0);
          uVar8 = 0;
        }
      }
LAB_600754e2:
      local_ec = CONCAT31(local_ec._1_3_,uVar8);
    }
LAB_60075338:
    uVar5 = audio_states__60074c2c();
    local_d8 = local_100;
    FUN_600da478(auStack_d4,auStack_fc);
    local_e0 = local_f8;
    FUN_600da478(auStack_dc,auStack_f4);
    synapse_audio_processor__6007b1b8(&local_e8,&local_d8,&local_e0,1,uVar11,&local_f0,uVar5);
    thunk_EXT_FUN_00001680(auStack_dc);
    thunk_EXT_FUN_00001680(auStack_d4);
    FUN_60074ef4(&local_d8,&local_e8);
    FUN_600da424(&local_108,&local_d8);
    thunk_EXT_FUN_00001680(auStack_d4);
    local_118 = local_e8;
    if (local_e8 != (byte **)0x0) {
      local_118 = local_e8 + 0x19;
    }
    FUN_600da48a(&uStack_114,&ppbStack_e4);
    local_110 = local_e8;
    if (local_e8 != (byte **)0x0) {
      local_110 = local_e8 + 0x1a;
    }
    FUN_600da48a(&uStack_10c,&ppbStack_e4);
    thunk_EXT_FUN_00001680(&ppbStack_e4);
    FUN_600d4550(&local_b8);
LAB_600753b8:
    cVar3 = '\0';
  }
  else {
    ppbVar6 = (byte **)FUN_6010244e(ppbVar2,DAT_600758b4);
    if (ppbVar6 == (byte **)0x0) {
      FUN_6010165c(0x14,PTR_s_audio_states_cc_6007588c,0x173,
                   PTR_s_Aec_mode_is_NONE_start_Synapse_d_600758b8);
      local_e8 = ppbVar6;
      ppbStack_e4 = ppbVar6;
      uVar11 = audio_states__60074c2c();
      local_b8 = local_100;
      FUN_600da478(&local_b4,auStack_fc);
      local_d8 = local_f8;
      FUN_600da478(auStack_d4,auStack_f4);
      synapse_audio_processor__6007b1b8(&local_e0,&local_b8,&local_d8,0,0,&local_e8,uVar11);
      thunk_EXT_FUN_00001680(auStack_d4);
      thunk_EXT_FUN_00001680(&local_b4);
      FUN_60074ef4(&local_b8,&local_e0);
      FUN_600da424(&local_108,&local_b8);
      thunk_EXT_FUN_00001680(&local_b4);
      local_118 = local_e0;
      if (local_e0 != (byte **)0x0) {
        local_118 = local_e0 + 0x19;
      }
      FUN_600da48a(&uStack_114,auStack_dc);
      local_110 = local_e0;
      if (local_e0 != (byte **)0x0) {
        local_110 = local_e0 + 0x1a;
      }
      FUN_600da48a(&uStack_10c,auStack_dc);
      thunk_EXT_FUN_00001680(auStack_dc);
      goto LAB_600753b8;
    }
    cVar3 = '\x03';
    FUN_6010165c(0x28,PTR_s_audio_states_cc_6007588c,0x18d,
                 PTR_s_Unknown_echo_cancellation_type____600758bc,ppbVar2);
  }
  FUN_600d4550(&local_d0);
  thunk_EXT_FUN_00001680(auStack_f4);
  thunk_EXT_FUN_00001680(auStack_fc);
  iVar4 = 0;
  if (cVar3 == '\0') {
    puVar10 = PTR_s_Audio_setup_failed_to_set_the_pl_600758c0;
    if (local_118 == (byte **)0x0) {
      uVar11 = 0x2ed;
    }
    else if (local_110 == (byte **)0x0) {
      uVar11 = 0x2f2;
    }
    else {
      uVar11 = FUN_6007ec20();
      uVar11 = recording_pipeline__6007ed74(uVar11,0);
      local_d0 = local_110;
      FUN_600da478(&local_cc,&uStack_10c);
      local_b8 = local_108;
      FUN_600da478(&local_b4,&uStack_104);
      recording_pipeline__6007edf4(uVar11,&local_d0,&local_b8);
      thunk_EXT_FUN_00001680(&local_b4);
      thunk_EXT_FUN_00001680(&local_cc);
      local_d0 = local_118;
      FUN_600da478(&local_cc,&uStack_114);
      local_b8 = local_108;
      FUN_600da478(&local_b4,&uStack_104);
      iVar4 = audio_tasks__60079d28(&local_d0,&local_b8);
      thunk_EXT_FUN_00001680(&local_b4);
      thunk_EXT_FUN_00001680(&local_cc);
      if (iVar4 != 0) goto LAB_6007541a;
      uVar11 = 0x2fc;
      puVar10 = PTR_s_Failed_to_start_audio_playback_600758c4;
    }
    FUN_6010165c(0x28,PTR_s_audio_states_cc_6007588c,uVar11,puVar10);
  }
  else {
    local_b4 = 0x2e8;
    local_b0 = local_a2;
    local_b8 = (byte **)puVar10;
    local_ac = 0x80;
    ppbStack_a8 = (byte **)0x0;
    local_a4 = 0;
    local_a3 = 0;
    local_a2[0] = 0;
    FUN_60101b76(&local_b0,PTR_s_Failed_to_setup_audio_paths_and_a_600755b4);
    local_d0 = (byte **)CONCAT31(local_d0._1_3_,cVar3);
    uVar11 = FUN_600cbb14(&local_d0);
    FUN_60101b76(&local_b0,uVar11);
    FUN_601016f0(0x28,local_b8,local_b4,&local_b0);
  }
LAB_6007541a:
  thunk_EXT_FUN_00001680(&uStack_104);
  thunk_EXT_FUN_00001680(&uStack_10c);
  thunk_EXT_FUN_00001680(&uStack_114);
  thunk_EXT_FUN_00001680(auStack_124);
  thunk_EXT_FUN_00001680(auStack_11c);
  if (iVar4 == 0) {
    thunk_EXT_FUN_00001680(auStack_12c);
    thunk_EXT_FUN_00001680(auStack_134);
    return;
  }
  uVar11 = FUN_6007ec20();
  recording_pipeline__6007ed74(uVar11,1);
  *param_1 = 1;
  thunk_EXT_FUN_00001680(auStack_12c);
  thunk_EXT_FUN_00001680(auStack_134);
LAB_6007545a:
  FUN_600d4e64(DAT_600755b8);
  return;
}


