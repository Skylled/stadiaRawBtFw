// 6005990c  sleep_driver__6005990c  size=744 bytes
// src: sleep_driver.cc
// --- callers ---
//   60059d54 sleep_lock__60059d54
// --- callees ---
//   6007f870 FUN_6007f870
//   601016f0 FUN_601016f0
//   600cae38 timers__600cae38
//   600d4dc2 FUN_600d4dc2
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600d3618 FUN_600d3618
//   6013cef8 thunk_EXT_FUN_0000737c
//   60070060 FUN_60070060
//   60060940 FUN_60060940
//   60060794 FUN_60060794
//   60070080 FUN_60070080
//   6006089c FUN_6006089c
//   6010165c FUN_6010165c
//   6006fcf0 FUN_6006fcf0
//   60101b76 FUN_60101b76
//   600cedd8 FUN_600cedd8
//   600cbb14 FUN_600cbb14
//   6013cf80 thunk_EXT_FUN_0000714c
//   600d94c4 FUN_600d94c4
//   60060910 FUN_60060910


/* src: sleep_driver.cc */

uint sleep_driver__6005990c(int *param_1,uint param_2,int *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  bool bVar11;
  ulonglong uVar12;
  undefined1 local_e8 [4];
  byte local_e4 [4];
  uint local_e0;
  int iStack_dc;
  int local_d8;
  undefined4 uStack_d4;
  int local_d0;
  undefined4 uStack_cc;
  int local_c8;
  undefined *local_c0;
  int local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [134];
  
  if ((char)param_1[4] == '\0') {
    uVar9 = 9;
  }
  else if (param_2 < 10) {
    uVar9 = 3;
  }
  else {
    iVar3 = FUN_600d3618();
    iVar4 = FUN_60060794(param_1[1]);
    if (iVar4 == 0) {
      iVar6 = FUN_60070060();
      if (iVar6 == 0) {
        FUN_6010165c(0x28,PTR_s_sleep_driver_cc_60059c04,0x47,
                     PTR_s_Skipping_sleep_as_no_wakeup_sour_60059c08);
        return 10;
      }
      FUN_6010165c(0x1e,PTR_s_sleep_driver_cc_60059c04,0x45,
                   PTR_s_SRTC_isn_t_enabled__so_the_sleep_60059c00);
    }
    else {
      uVar9 = FUN_600d4dc2(param_1[1],&local_e0);
      if ((uVar9 & 0xff) != 0) {
        return uVar9;
      }
      local_b4 = uStack_d4;
      local_c0 = (undefined *)(local_e0 + param_2 / 1000);
      local_bc = iStack_dc + (uint)CARRY4(local_e0,param_2 / 1000);
      local_b8 = (undefined1 *)(DAT_60059bf4 * (param_2 % 1000) + local_d8);
      if (DAT_60059bf8 < (int)local_b8) {
        bVar11 = (undefined *)0xfffffffe < local_c0;
        local_c0 = local_c0 + 1;
        local_bc = local_bc + (uint)bVar11;
        local_b8 = local_b8 + DAT_60059bfc;
      }
      uVar9 = FUN_6006089c(param_1[1],&local_c0);
      if ((uVar9 & 0xff) != 0) {
        return uVar9;
      }
      uVar9 = FUN_60060910(param_1[1]);
      if ((uVar9 & 0xff) != 0) {
        return uVar9;
      }
      FUN_600d94c4(0x2e,1);
    }
    param_2 = param_2 + iVar3;
    FUN_6006fcf0(0);
    uVar5 = FUN_600d3618();
    uVar8 = *(uint *)(param_1[2] + 0x18);
    uVar9 = **(uint **)(param_1[2] + 0x20);
    iVar6 = FUN_6007f870();
    uVar9 = uVar9 >> (uVar8 & 0xff);
    while ((*(int *)(iVar6 + 0x11c) != 0 || ((~uVar9 & 1) != 0))) {
      if (param_2 <= uVar5) goto LAB_60059a56;
      uVar5 = param_2 - uVar5;
      if (0x31 < uVar5) {
        uVar5 = 0x32;
      }
      thunk_EXT_FUN_0000737c(uVar5);
      uVar5 = FUN_600d3618();
      iVar6 = FUN_6007f870();
      uVar9 = **(uint **)(param_1[2] + 0x20) >> (*(uint *)(param_1[2] + 0x18) & 0xff);
    }
    if (uVar5 < param_2) {
      iVar3 = *param_1;
      if ((iVar3 == 0) || (iVar6 = timers__600cae38(*(undefined4 *)(iVar3 + 4)), iVar6 == 0)) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
        thunk_EXT_FUN_00007a2c(*(undefined4 *)(iVar3 + 4),3,0,0,10);
      }
      iVar6 = param_1[3];
      if (iVar6 != 0) {
        FUN_600cedd8(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x18),1);
      }
      uVar12 = FUN_60070080();
      uVar7 = (undefined4)(uVar12 >> 0x20);
      if ((uVar12 & 0xff) != 0) {
        local_c0 = PTR_s_sleep_driver_cc_60059c04;
        local_bc = 0x73;
        local_b8 = local_aa;
        local_b4 = 0x80;
        uStack_b0 = 0;
        local_ac = 0;
        local_ab = 0;
        local_aa[0] = 0;
        FUN_60101b76(&local_b8,PTR_s_SwitchToLowPowerMode_failed__60059c14);
        local_e8[0] = (undefined1)uVar12;
        uVar7 = FUN_600cbb14(local_e8);
        FUN_60101b76(&local_b8,uVar7);
        FUN_601016f0(0x28,local_c0,local_bc,&local_b8);
        uVar7 = extraout_r1;
      }
      if (iVar4 != 0) {
        if (param_3 != (int *)0x0) {
          bVar2 = FUN_600d4dc2(param_1[1],&local_d0);
          if (bVar2 == 0) {
            *param_3 = (local_d0 - local_e0) * 1000 + (local_c8 - local_d8) / DAT_60059bf4;
            uVar7 = uStack_cc;
          }
          else {
            local_c0 = PTR_s_sleep_driver_cc_60059c04;
            local_bc = 0x7e;
            local_b8 = local_aa;
            local_b4 = 0x80;
            uStack_b0 = 0;
            local_ac = 0;
            local_ab = 0;
            local_aa[0] = 0;
            FUN_60101b76(&local_b8,PTR_s_Unable_to_get_time_after_sleep__60059c18);
            local_e4[0] = bVar2;
            uVar7 = FUN_600cbb14(local_e4);
            FUN_60101b76(&local_b8,uVar7);
            FUN_601016f0(0x28,local_c0,local_bc,&local_b8);
            uVar7 = extraout_r1_00;
          }
        }
        cVar1 = FUN_60060940(param_1[1],uVar7);
        if (cVar1 != '\0') {
          FUN_6010165c(0x28,PTR_s_sleep_driver_cc_60059c04,0x82,
                       PTR_s_Unable_to_stop_SRTC_alarm__60059c10);
        }
        FUN_600d94c4(0x2e,0);
      }
      iVar4 = param_1[3];
      if (iVar4 != 0) {
        FUN_600cedd8(*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x18),0);
      }
      if (!bVar11) {
        return (uint)uVar12;
      }
      uVar10 = *(undefined4 *)(iVar3 + 4);
      uVar7 = thunk_EXT_FUN_0000714c();
      thunk_EXT_FUN_00007a2c(uVar10,1,uVar7,0,10);
      return (uint)uVar12;
    }
LAB_60059a56:
    FUN_6010165c(0x14,PTR_s_sleep_driver_cc_60059c04,0x5b,
                 PTR_s_Unable_to_sleep_due_to_the_patte_60059c0c);
    if (param_3 != (int *)0x0) {
      *param_3 = uVar5 - iVar3;
    }
    if (iVar4 != 0) {
      cVar1 = FUN_60060940(param_1[1]);
      if (cVar1 != '\0') {
        FUN_6010165c(0x28,PTR_s_sleep_driver_cc_60059c04,0x61,
                     PTR_s_Unable_to_stop_SRTC_alarm__60059c10);
      }
      FUN_600d94c4(0x2e,0);
    }
    uVar9 = 0;
  }
  return uVar9;
}


