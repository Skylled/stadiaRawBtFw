// 60074658  timer__60074658  size=538 bytes
// src: timer.h
// src: board.cc
// --- callers ---
//   600cbd68 FUN_600cbd68
// --- callees ---
//   600d7d1c FUN_600d7d1c
//   600d5494 FUN_600d5494
//   60061e98 FUN_60061e98
//   6006820c i2c_device__6006820c
//   60068cb4 battery_gauge_bq2742X__60068cb4
//   60060f28 usb_device__60060f28
//   6006816c accessory_detect_ts3a227e__6006816c
//   6006b2e8 usb_port_controller_tusb320__6006b2e8
//   600d6dda FUN_600d6dda
//   600ce2a0 FUN_600ce2a0
//   600d6e14 FUN_600d6e14
//   60101740 FUN_60101740
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   600679d4 gotham__600679d4
//   60071580 board__60071580
//   6006581c haptics_cluster__6006581c
//   600cc984 FUN_600cc984
//   600d4ec8 FUN_600d4ec8
//   600cc8f8 FUN_600cc8f8
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   60101c48 FUN_60101c48
//   600686e4 FUN_600686e4
//   6005d714 trigger_bug_report__6005d714
//   600d9414 FUN_600d9414
//   600d54a6 FUN_600d54a6
//   600cad24 timers__600cad24
//   6006b630 sound_codec_wm8904__6006b630
//   6013cf80 thunk_EXT_FUN_0000714c
//   600d72ec FUN_600d72ec
//   6010165c FUN_6010165c


/* src: timer.h
   src: board.cc */

void timer__60074658(int param_1)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte local_b1;
  uint local_b0;
  undefined4 local_ac;
  
  uVar4 = FUN_600d7d1c();
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0xe38) = uVar4;
  puVar2 = DAT_60074874;
  DataMemoryBarrier(0x1b);
  local_b1 = 0;
  iVar6 = FUN_600d6e14(0x14);
  if ((iVar6 == 0) || (cVar5 = FUN_600d72ec(0x14,&local_b1), cVar5 != '\0')) {
    DataMemoryBarrier(0x1b);
    uVar13 = 2;
  }
  else {
    uVar13 = (uint)local_b1;
    DataMemoryBarrier(0x1b);
  }
  *puVar2 = uVar13;
  DataMemoryBarrier(0x1b);
  uVar7 = accessory_detect_ts3a227e__6006816c(param_1 + 0x433c);
  uVar13 = board__60071580(uVar7,DAT_60074878);
  uVar7 = i2c_device__6006820c(param_1 + 0x433c,3);
  uVar8 = board__60071580(uVar7,DAT_6007487c);
  uVar7 = sound_codec_wm8904__6006b630(param_1 + 0x432c);
  uVar9 = board__60071580(uVar7,DAT_60074880);
  uVar7 = FUN_60061e98(param_1 + 0x3a68);
  uVar10 = board__60071580(uVar7,DAT_60074884);
  uVar7 = FUN_600d9414(param_1 + 0x431c);
  uVar11 = board__60071580(uVar7,DAT_60074888);
  uVar7 = FUN_600686e4(param_1 + 0x4364);
  uVar12 = board__60071580(uVar7,DAT_6007488c);
  uVar13 = (uVar13 | uVar8) & 0xff | uVar9 & 0xff | uVar10 & 0xff | uVar11 & 0xff | uVar12 & 0xff;
  cVar5 = battery_gauge_bq2742X__60068cb4(param_1 + 0x4348,1);
  if (cVar5 != '\0') {
    FUN_6010165c(0x28,DAT_60074894,0x14b,DAT_60074890);
    pbVar3 = DAT_60074898;
    local_b0 = local_b0 & 0xffffff00;
    DataMemoryBarrier(0x1b);
    if ((-1 < (int)((uint)*DAT_60074898 << 0x1f)) &&
       (iVar6 = FUN_600cc8f8(DAT_60074898), iVar6 != 0)) {
      FUN_600d6dda(DAT_6007489c);
      FUN_600cc984(pbVar3);
    }
    FUN_600d72ec(0x2a,&local_b0);
    uVar13 = uVar13 | local_b0 & 0xff ^ 1;
  }
  iVar6 = param_1 + 0x3de8;
  uVar7 = haptics_cluster__6006581c(param_1 + 0x6b10);
  cVar5 = board__60071580(uVar7,DAT_600748a0);
  local_b0 = DAT_600748a4;
  local_ac = DAT_600748a8;
  FUN_600d5494(iVar6,DAT_600748a4,DAT_600748a8);
  local_b0 = DAT_600748ac;
  local_ac = DAT_600748b0;
  FUN_600d54a6(iVar6,DAT_600748ac,DAT_600748b0);
  usb_device__60060f28(iVar6);
  FUN_600d4ec8(param_1 + 0x39c0);
  local_b0 = DAT_600748b4;
  local_ac = DAT_600748b8;
  usb_port_controller_tusb320__6006b2e8(param_1 + 0x3f04,DAT_600748b4,DAT_600748b8);
  usb_port_controller_tusb320__6006b3e8(param_1 + 0x3f04);
  puVar2 = DAT_600748c0;
  bVar1 = *DAT_600748bc;
  DataMemoryBarrier(0x1b);
  if (((bVar1 & 1) == 0) && (iVar6 = FUN_600cc8f8(), uVar8 = DAT_600748c4, iVar6 != 0)) {
    *puVar2 = bVar1 & 1;
    puVar2[2] = uVar8;
    uVar7 = DAT_600748cc;
    puVar2[3] = DAT_600748c8;
    uVar8 = timers__600cad24(uVar7,1000,1,puVar2,DAT_600748d0,puVar2 + 4);
    puVar2[1] = uVar8;
    if (uVar8 == 0) {
      FUN_600ce2a0(&local_b0,DAT_600748d8,DAT_600748d4,0x4f);
      FUN_60101740(&local_b0);
    }
    FUN_600cc984(DAT_600748bc);
    FUN_60101c48(DAT_600748c0,DAT_600748e0,DAT_600748dc);
  }
  uVar8 = puVar2[1];
  uVar7 = thunk_EXT_FUN_0000714c();
  thunk_EXT_FUN_00007a2c(uVar8,1,uVar7,0,10);
  uVar7 = gotham__600679d4();
  iVar6 = board__60071580(uVar7,DAT_600748e4);
  if ((uVar13 != 0 || cVar5 != '\0') || (iVar6 != 0)) {
    trigger_bug_report__6005d714(DAT_600748e8,0);
  }
  return;
}


