// 6007b1b8  synapse_audio_processor__6007b1b8  size=928 bytes
// src: synapse_audio_processor.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600dc38e FUN_600dc38e
//   601017fc FUN_601017fc
//   6013d3c8 thunk_EXT_FUN_00001680
//   6013d378 thunk_EXT_FUN_0000b532
//   601017e8 FUN_601017e8
//   6010177a FUN_6010177a
//   600dc30e FUN_600dc30e
//   600dbf20 FUN_600dbf20
//   6007aeb0 FUN_6007aeb0
//   6013d068 thunk_EXT_FUN_0000b52e
//   6010165c FUN_6010165c


/* src: synapse_audio_processor.cc */

undefined4 *
synapse_audio_processor__6007b1b8
          (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,int param_5,
          undefined1 *param_6,int param_7)

{
  bool bVar1;
  undefined1 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined *puVar13;
  int local_720;
  int local_71c;
  undefined4 *local_718;
  undefined4 *local_714;
  undefined4 local_710;
  undefined4 local_70c;
  undefined4 local_708;
  undefined4 local_704 [109];
  undefined1 auStack_550 [12];
  undefined4 local_544;
  undefined4 local_53c;
  undefined4 local_530;
  undefined4 uStack_52c;
  undefined4 uStack_528;
  undefined4 uStack_524;
  undefined4 local_520;
  undefined4 uStack_51c;
  undefined4 local_518;
  undefined4 uStack_514;
  undefined4 uStack_510;
  undefined4 local_50c;
  undefined4 uStack_508;
  undefined4 uStack_504;
  undefined4 uStack_500;
  undefined4 local_4fc;
  undefined4 uStack_4f8;
  undefined4 local_4f4;
  undefined4 uStack_4f0;
  undefined4 uStack_4ec;
  undefined4 local_4dc;
  undefined1 local_4d3;
  undefined4 local_43c;
  undefined4 local_42c;
  undefined4 local_428;
  undefined1 local_420;
  undefined4 local_41c;
  undefined4 local_3a4;
  undefined1 auStack_398 [12];
  int local_38c;
  undefined4 local_384;
  undefined4 local_324;
  undefined1 local_31b;
  undefined4 local_284;
  undefined4 local_274;
  undefined4 local_270;
  undefined1 local_268;
  undefined4 local_264;
  undefined4 local_1ec;
  undefined1 auStack_1e0 [12];
  undefined4 local_1d4;
  undefined4 local_1cc;
  undefined4 local_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 local_1b0;
  undefined4 uStack_1ac;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 local_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 local_18c;
  undefined4 uStack_188;
  undefined4 local_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 local_16c;
  undefined1 local_163;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined1 local_b0;
  undefined4 local_ac;
  int local_34;
  
  local_720 = 0;
  if (param_4 == 0) {
    FUN_6010165c(0x14,PTR_s_synapse_audio_processor_cc_6007b580,0x14b,
                 PTR_s_Synapse_echo_canceller_DISABLED__6007b57c);
  }
  else {
    FUN_6007aeb0(&local_708);
    puVar3 = PTR_DAT_6007b3f8;
    puVar13 = PTR_DAT_6007b3e8;
    if (param_5 == 1) {
      puVar11 = auStack_398;
      FUN_6007aeb0(puVar11);
      local_384 = 3;
      local_284 = 0xf;
      local_324 = 0x40800000;
      local_264 = 0x40800000;
      local_274 = 5;
      local_270 = 5;
      local_268 = 0;
      local_1ec = 4;
      local_31b = 1;
      local_38c = param_5;
LAB_6007b26a:
      thunk_EXT_FUN_0000b572(&local_708,puVar11,0x1b8);
    }
    else {
      if (param_5 == 2) {
        puVar11 = auStack_1e0;
        FUN_6007aeb0(puVar11);
        local_163 = 1;
        local_1d4 = 1;
        local_16c = 0x40800000;
        local_1cc = 3;
        local_1c0 = *(undefined4 *)puVar3;
        uStack_1bc = *(undefined4 *)(puVar3 + 4);
        uStack_1b8 = *(undefined4 *)(puVar3 + 8);
        uStack_1b4 = *(undefined4 *)(puVar3 + 0xc);
        local_1b0 = *(undefined4 *)(puVar3 + 0x10);
        uStack_1ac = *(undefined4 *)(puVar3 + 0x14);
        local_1a8 = *(undefined4 *)(puVar3 + 0x18);
        uStack_1a4 = *(undefined4 *)(puVar3 + 0x1c);
        uStack_1a0 = *(undefined4 *)(puVar3 + 0x20);
        local_19c = *(undefined4 *)(puVar3 + 0x24);
        uStack_198 = *(undefined4 *)(puVar3 + 0x28);
        uStack_194 = *(undefined4 *)(puVar3 + 0x2c);
        uStack_190 = *(undefined4 *)(puVar3 + 0x30);
        local_18c = *(undefined4 *)(puVar3 + 0x34);
        uStack_188 = *(undefined4 *)(puVar3 + 0x38);
        local_184 = *(undefined4 *)(puVar3 + 0x3c);
        uStack_180 = *(undefined4 *)(puVar3 + 0x40);
        uStack_17c = *(undefined4 *)(puVar3 + 0x44);
        local_b0 = 0;
        local_ac = 0x40800000;
        local_cc = 0xf;
        local_bc = 5;
        local_b8 = 5;
        local_34 = param_5;
        goto LAB_6007b26a;
      }
      if (param_5 == 0) {
        FUN_6007aeb0(auStack_550);
        local_53c = 3;
        local_4d3 = 1;
        local_544 = 1;
        local_4dc = 0x40800000;
        local_530 = *(undefined4 *)puVar13;
        uStack_52c = *(undefined4 *)(puVar13 + 4);
        uStack_528 = *(undefined4 *)(puVar13 + 8);
        uStack_524 = *(undefined4 *)(puVar13 + 0xc);
        local_520 = *(undefined4 *)(puVar13 + 0x10);
        uStack_51c = *(undefined4 *)(puVar13 + 0x14);
        local_518 = *(undefined4 *)(puVar13 + 0x18);
        uStack_514 = *(undefined4 *)(puVar13 + 0x1c);
        uStack_510 = *(undefined4 *)(puVar13 + 0x20);
        local_50c = *(undefined4 *)(puVar13 + 0x24);
        uStack_508 = *(undefined4 *)(puVar13 + 0x28);
        uStack_504 = *(undefined4 *)(puVar13 + 0x2c);
        uStack_500 = *(undefined4 *)(puVar13 + 0x30);
        local_4fc = *(undefined4 *)(puVar13 + 0x34);
        uStack_4f8 = *(undefined4 *)(puVar13 + 0x38);
        local_4f4 = *(undefined4 *)(puVar13 + 0x3c);
        uStack_4f0 = *(undefined4 *)(puVar13 + 0x40);
        uStack_4ec = *(undefined4 *)(puVar13 + 0x44);
        puVar11 = auStack_550;
        local_43c = 0xf;
        local_41c = 0x40800000;
        local_42c = 5;
        local_428 = 5;
        local_3a4 = 1;
        local_420 = 0;
        goto LAB_6007b26a;
      }
    }
    FUN_6010165c(0x14,PTR_s_synapse_audio_processor_cc_6007b3f0,0x128,
                 PTR_s_Synapse_echo_canceller_ENABLED__6007b3ec);
    local_708 = CONCAT13(local_708._3_1_,*(undefined3 *)(param_6 + 2));
    if (param_7 == 0) {
      uVar12 = 0x133;
      puVar13 = PTR_s_Using_16_kHz_processing_rate__6007b3fc;
LAB_6007b374:
      FUN_6010165c(0x14,PTR_s_synapse_audio_processor_cc_6007b3f0,uVar12,puVar13);
      uVar12 = 16000;
    }
    else {
      if (param_7 != 1) {
        uVar12 = 0x13b;
        puVar13 = PTR_s_Unsupported_processing_rate__def_6007b3f4;
        goto LAB_6007b374;
      }
      uVar12 = 48000;
      FUN_6010165c(0x14,PTR_s_synapse_audio_processor_cc_6007b3f0,0x137,
                   PTR_s_Using_48_kHz_processing_rate__6007b400);
    }
    iVar9 = thunk_EXT_FUN_0000b532(0x474);
    FUN_600dc38e(iVar9,&local_708,*param_6,param_6[1],uVar12);
    iVar4 = local_720;
    bVar1 = local_720 != 0;
    local_720 = iVar9;
    if (bVar1) {
      FUN_600dc30e(iVar4);
      thunk_EXT_FUN_0000b52e(iVar4,0x474);
    }
    if (local_720 == 0) {
      FUN_6010165c(0x28,PTR_s_synapse_audio_processor_cc_6007b3f0,0x147,
                   PTR_s_Failed_to_initialize_Synapse_ech_6007b404);
      *param_1 = 0;
      param_1[1] = 0;
      goto LAB_6007b3d6;
    }
  }
  local_71c = local_720;
  local_720 = 0;
  local_710 = *param_2;
  *param_2 = 0;
  local_70c = param_2[1];
  param_2[1] = 0;
  local_708 = *param_3;
  *param_3 = 0;
  local_704[0] = param_3[1];
  param_3[1] = 0;
  puVar10 = (undefined4 *)thunk_EXT_FUN_0000b532(0x5f18);
  puVar13 = PTR_DAT_6007b584;
  puVar10[0x15] = 0;
  *puVar10 = puVar13;
  FUN_601017fc();
  uVar7 = local_704[0];
  uVar6 = local_708;
  uVar5 = local_70c;
  uVar12 = local_710;
  puVar13 = PTR_PTR_6007b588;
  *(undefined1 *)(puVar10 + 0x18) = 1;
  *puVar10 = puVar13;
  *(undefined1 *)(puVar10 + 0x1b) = 0;
  puVar10[0x19] = puVar13 + 0x28;
  puVar10[0x1a] = puVar13 + 0x44;
  puVar10[0x1c] = local_71c;
  uVar2 = *param_6;
  puVar10[0x50] = puVar10 + 0x52;
  local_71c = 0;
  puVar10[0x51] = 0xc00;
  local_710 = 0;
  puVar10[0x16] = 0;
  puVar10[0x17] = 0;
  puVar10[0xc52] = uVar12;
  local_70c = 0;
  puVar10[0xc53] = uVar5;
  local_708 = 0;
  puVar10[0xc54] = uVar6;
  local_704[0] = 0;
  puVar10[0xc55] = uVar7;
  *(undefined1 *)(puVar10 + 0xc56) = uVar2;
  *(undefined1 *)((int)puVar10 + 0x3159) = param_6[1];
  *(undefined1 *)((int)puVar10 + 0x315a) = param_6[2];
  *(undefined1 *)((int)puVar10 + 0x315b) = param_6[3];
  *(undefined1 *)(puVar10 + 0xc57) = param_6[4];
  *(undefined1 *)((int)puVar10 + 0x315d) = param_6[5];
  *(undefined1 *)((int)puVar10 + 0x315e) = param_6[6];
  *(undefined1 *)((int)puVar10 + 0x315f) = param_6[7];
  puVar10[0xc6c] = 0;
  FUN_601017e8();
  puVar10[0xc6d] = 0;
  puVar10[0x1402] = 0;
  FUN_601017e8();
  puVar10[0x1403] = 0x780;
  puVar10[0x1404] = 0;
  puVar10[0x1405] = puVar10 + 0x1406;
  puVar10[0x17] = puVar10 + 0x1d;
  local_714 = (undefined4 *)0x0;
  *DAT_6007b58c = puVar10;
  local_718 = puVar10;
  local_714 = (undefined4 *)thunk_EXT_FUN_0000b532(0x10);
  puVar13 = PTR_PTR_6007b590;
  local_714[3] = puVar10;
  *local_714 = puVar13;
  local_714[1] = 1;
  local_714[2] = 1;
  thunk_EXT_FUN_00001680(local_704);
  thunk_EXT_FUN_00001680(&local_70c);
  FUN_600dbf20(&local_71c);
  cVar8 = FUN_6010177a(local_718,PTR_s_SynapseAEC_Task_6007b594,6);
  if (cVar8 == '\0') {
    *param_1 = local_718;
    param_1[1] = local_714;
    local_718 = (undefined4 *)0x0;
    local_714 = (undefined4 *)0x0;
  }
  else {
    FUN_6010165c(0x28,PTR_s_synapse_audio_processor_cc_6007b580,0x156,
                 PTR_s_Failed_to_start_Synapse_echo_can_6007b598);
    *param_1 = 0;
    param_1[1] = 0;
  }
  thunk_EXT_FUN_00001680(&local_714);
LAB_6007b3d6:
  FUN_600dbf20(&local_720);
  return param_1;
}


