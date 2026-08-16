// 6006318c  usb_host_audio__6006318c  size=1176 bytes
// src: usb_host_audio.cc
// --- callers ---
// --- callees ---
//   60062aa8 usb_host_audio__60062aa8
//   600644dc usb_host_audio_topology__600644dc
//   600d55e2 FUN_600d55e2
//   6010165c FUN_6010165c
//   600d6052 FUN_600d6052
//   600d1c52 FUN_600d1c52
//   60062f9c usb_host_audio__60062f9c
//   60064110 usb_host_audio_topology__60064110
//   6013d310 thunk_EXT_FUN_0000b52a
//   600d1c8c FUN_600d1c8c
//   600d56ae usb_host_worker__600d56ae
//   600d571c FUN_600d571c
//   60062b1c usb_host_audio__60062b1c
//   600d19ce FUN_600d19ce
//   600d194a FUN_600d194a
//   600d600a FUN_600d600a
//   600d654c FUN_600d654c
//   600d1ba0 FUN_600d1ba0
//   6005592c FUN_6005592c
//   60055b5c FUN_60055b5c
//   600d55fa FUN_600d55fa
//   600d1c18 FUN_600d1c18


/* src: usb_host_audio.cc */

void usb_host_audio__6006318c(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  int iVar14;
  undefined *puVar15;
  int iVar16;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 uStack_1d;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  switch(param_2) {
  case 0:
    if (*(int *)(param_1 + 0xf0) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x560) != 0) {
      FUN_600d194a();
    }
    if (*(int *)(param_1 + 0x130) == 0) {
      return;
    }
    FUN_600d194a(*(undefined4 *)(param_1 + 0xf0));
    return;
  case 1:
    iVar9 = FUN_600d600a(*(undefined4 *)(param_1 + 0xec));
    iVar16 = param_1 + 0x110;
    if ((*(int *)(param_1 + 0x970) == iVar16) && (*(char *)(param_1 + 300) != '\0')) {
      *(int *)(param_1 + 0x970) = param_1 + 0x540;
    }
    iVar14 = *(int *)(param_1 + 0x970);
    if ((iVar14 != param_1 + 0x540) || (*(char *)(param_1 + 0x55c) == '\0')) {
      if (iVar16 == iVar14) {
        FUN_600d55e2(iVar16,2);
        *(int *)(*(int *)(param_1 + 0x970) + 0x18) = *(int *)(*(int *)(param_1 + 0x970) + 0x18) + 1;
        if (*(int *)(*(int *)(param_1 + 0x970) + 0x18) < iVar9) goto LAB_60063232;
        goto LAB_6006328c;
      }
      *(int *)(iVar14 + 0x18) = *(int *)(iVar14 + 0x18) + 1;
      iVar16 = *(int *)(param_1 + 0x970);
      if (iVar9 <= *(int *)(iVar16 + 0x18)) {
        uVar13 = 2;
        if (*(char *)(iVar16 + 0x10) != '\x01') goto LAB_60063234;
        FUN_600d55e2(iVar16,2);
        *(undefined4 *)(*(int *)(param_1 + 0x970) + 0x18) = 0;
      }
      goto LAB_60063232;
    }
    break;
  case 2:
    bVar5 = FUN_600d6052(*(undefined4 *)(param_1 + 0xec),*(int *)(param_1 + 0x970) + 0x24,
                         *(undefined4 *)(*(int *)(param_1 + 0x970) + 0x18));
    uVar7 = (uint)bVar5;
    if (uVar7 == 0) {
      usb_host_audio_topology__60064110(&local_1c,*(undefined4 *)(param_1 + 0xec));
      iVar9 = *(int *)(param_1 + 0xf8);
      *(uint *)(param_1 + 0xf8) = local_1c;
      *(uint *)(param_1 + 0xfc) = local_18;
      *(uint *)(param_1 + 0x100) = local_14;
      local_1c = uVar7;
      local_18 = uVar7;
      local_14 = uVar7;
      if (iVar9 != 0) {
        thunk_EXT_FUN_0000b52a();
      }
      if (local_1c != 0) {
        thunk_EXT_FUN_0000b52a();
      }
      iVar9 = FUN_6005592c(*(undefined4 *)(*(int *)(param_1 + 0x970) + 0x20),
                           *(undefined4 *)(*(int *)(param_1 + 0x970) + 0x24),0,
                           PTR_LAB_600d56ee_1_6006356c,param_1);
      if (iVar9 == 0) {
        return;
      }
      uVar13 = 0x2e0;
      puVar15 = PTR_s_Unable_to_set_control_interface_60063570;
LAB_600632e2:
      FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_60063568,uVar13,puVar15);
    }
    else {
      uVar13 = 0x2d6;
      iVar9 = *(int *)(*(int *)(param_1 + 0x970) + 0x18);
      puVar15 = PTR_s_Unable_to_find_control_interface_60063564;
LAB_60063284:
      FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_60063568,uVar13,puVar15,iVar9);
    }
LAB_6006328c:
    uVar13 = 8;
    goto LAB_60063234;
  case 3:
    iVar9 = *(int *)(param_1 + 0xfc);
    if (*(int *)(param_1 + 0xf8) != iVar9) {
      iVar9 = FUN_600d1c52(*(undefined4 *)(param_1 + 0x130),*(undefined1 *)(iVar9 + -2),2,
                           *(undefined1 *)(iVar9 + -1),DAT_60063578,0x80,PTR_LAB_600d572a_1_60063574
                           ,param_1);
      if (iVar9 == 0) {
        return;
      }
      uVar13 = 0x2fa;
      puVar15 = PTR_s_Failed_to_query_clock_source___d_6006357c;
      goto LAB_60063284;
    }
    goto LAB_60063232;
  case 4:
    puVar10 = *(undefined4 **)(param_1 + 0x970);
    cVar6 = usb_host_audio_topology__600644dc
                      (*(undefined4 *)(param_1 + 0xec),*puVar10,*(undefined1 *)((int)puVar10 + 6),
                       puVar10[2],*(undefined1 *)((int)puVar10 + 5),*(undefined1 *)(puVar10 + 4),
                       puVar10[3],puVar10 + 10,puVar10 + 0xb,puVar10 + 0x103,&local_20,&local_1f,
                       &local_1e,&uStack_1d);
    if (cVar6 == '\0') {
      iVar9 = FUN_600d1c8c(*(undefined4 *)(*(int *)(param_1 + 0x970) + 0x20),local_20,local_1f,
                           local_1e);
      if (iVar9 == 0) {
        FUN_600d654c(&local_1c,*(undefined4 *)(param_1 + 0xec),local_1e);
        uVar7 = local_1c;
        for (iVar9 = 0; iVar16 = *(int *)(param_1 + 0x970), (int)(local_18 - local_1c) >> 2 != iVar9
            ; iVar9 = iVar9 + 1) {
          uVar2 = *(undefined1 *)(uVar7 + 3);
          uVar1 = *(undefined1 *)(uVar7 + 1);
          if (iVar9 == 1) {
            *(undefined1 *)(iVar16 + 0x99) = uVar2;
            *(undefined1 *)(*(int *)(param_1 + 0x970) + 0x1b9) = uVar1;
          }
          else if (iVar9 == 0) {
            *(undefined1 *)(iVar16 + 0x35) = uVar2;
            *(undefined1 *)(*(int *)(param_1 + 0x970) + 0x161) = uVar1;
          }
          else if (iVar9 == 2) {
            *(undefined1 *)(iVar16 + 0xfd) = uVar2;
            *(undefined1 *)(*(int *)(param_1 + 0x970) + 0x211) = uVar1;
          }
          uVar7 = uVar7 + 4;
        }
        iVar9 = FUN_60055bd8(*(undefined4 *)(iVar16 + 0x20),*(undefined4 *)(iVar16 + 0x28),
                             *(undefined1 *)(iVar16 + 0x2c),PTR_LAB_600d56f6_1_60063588,param_1);
        if (iVar9 != 0) {
          usb_host_worker__600d56ae(param_1,8);
        }
        if (local_1c == 0) {
          return;
        }
        thunk_EXT_FUN_0000b52a();
        return;
      }
      uVar13 = 0x31c;
      puVar15 = PTR_s_Error_setting_interface_units_60063584;
      goto LAB_600632e2;
    }
    FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_60063568,0x313,
                 PTR_s_Unable_to_find_streaming_interfa_60063580);
    break;
  case 5:
    iVar9 = **(int **)(param_1 + 0x970);
    uVar13 = FUN_600d19ce((*(int **)(param_1 + 0x970))[8],1,iVar9 != 0);
    puVar4 = PTR_s_playback_60123e8f_0x16_60063590;
    puVar3 = PTR_s_speaker_6006358c;
    *(undefined4 *)(*(int *)(param_1 + 0x970) + 0x30) = uVar13;
    puVar12 = DAT_60063598;
    puVar15 = PTR_DAT_60063594;
    if (iVar9 == 0) {
      puVar12 = puVar4;
      puVar15 = puVar3;
    }
    iVar9 = *(int *)(param_1 + 0x970);
    uVar7 = (uint)*(byte *)(iVar9 + 0x10);
    uVar8 = (uint)*(byte *)(iVar9 + 5);
    uVar11 = *(uint *)(iVar9 + 0xc) / 1000;
    FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_60063568,0x34a,
                 PTR_s_USB__s_will__s_at__lukHz__u_bit___6006359c,puVar15,puVar12,uVar11,uVar8,uVar7
                );
    puVar10 = DAT_60063578;
    iVar9 = *(int *)(param_1 + 0x970);
    if (*(int *)(iVar9 + 0x40c) == 0) {
      uVar13 = *(undefined4 *)(iVar9 + 0x20);
      puVar10 = DAT_60063578 + 0x20;
      *puVar10 = *(undefined4 *)(iVar9 + 0xc);
      puVar15 = PTR_LAB_600d5714_1_600635a0;
      if (*(char *)(iVar9 + 0x410) != '\0') {
        puVar15 = PTR_LAB_600d56ee_1_6006356c;
      }
      iVar9 = FUN_60055b5c(uVar13,puVar10,1,puVar15,param_1);
      if (iVar9 == 0) {
        return;
      }
      if (*(char *)(*(int *)(param_1 + 0x970) + 0x410) != '\0') {
        uVar13 = 0x356;
        puVar15 = PTR_s_Unable_to_set_sampling_frequency_600635a4;
        goto LAB_600632e2;
      }
    }
    else if (*(char *)(iVar9 + 0x41c) == '\0') {
      iVar16 = *(int *)(iVar9 + 0x424);
      if (*(int *)(iVar9 + 0x420) == iVar16) {
        FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_60063568,899,
                     PTR_s_Error_with_USB_audio_clock_defin_600635b0,puVar15,puVar12,uVar11,uVar8,
                     uVar7);
      }
      else {
        uVar2 = *(undefined1 *)(iVar16 + -2);
        *(undefined1 *)DAT_60063578 = *(undefined1 *)(iVar16 + -1);
        iVar9 = FUN_600d1c18(*(undefined4 *)(iVar9 + 0x20),uVar2,1,1,puVar10,1,
                             PTR_FUN_600d57d4_1_600635a8,param_1);
        if (iVar9 == 0) {
          return;
        }
        if (*(char *)(*(int *)(param_1 + 0x970) + 0x410) != '\0') {
          uVar13 = 0x37b;
          puVar15 = PTR_s_Unable_to_set_clock_selector_600635ac;
          goto LAB_600632e2;
        }
      }
    }
    else {
      uVar2 = *(undefined1 *)(iVar9 + 0x414);
      *DAT_60063578 = *(undefined4 *)(iVar9 + 0x418);
      iVar9 = FUN_600d1c18(*(undefined4 *)(iVar9 + 0x20),uVar2,1,1,puVar10,4,
                           PTR_FUN_600d57d4_1_600635a8,param_1);
      if (iVar9 == 0) {
        return;
      }
      if (*(char *)(*(int *)(param_1 + 0x970) + 0x410) != '\0') {
        uVar13 = 0x369;
        puVar15 = PTR_s_Unable_to_set_sampling_frequency_600635a4;
        goto LAB_600632e2;
      }
    }
LAB_60063232:
    uVar13 = 1;
    goto LAB_60063234;
  case 6:
    cVar6 = *(char *)(*(int *)(param_1 + 0xec) + 0x79);
    if (cVar6 == '\0') goto LAB_60063232;
    if (cVar6 != ' ') {
      uVar13 = 0x3db;
      puVar15 = DAT_600636c0;
      goto LAB_600632e2;
    }
    break;
  case 7:
    iVar9 = FUN_600d55fa();
    if (*(undefined1 **)(iVar9 + 0x108) != (undefined1 *)0x0) {
      *(undefined1 *)(iVar9 + 0x104) = 0;
      uVar2 = **(undefined1 **)(iVar9 + 0x108);
      iVar9 = *(int *)(iVar9 + 0x970);
      uVar13 = 2;
      goto LAB_600635fc;
    }
    break;
  case 8:
    uVar13 = 1;
    *(undefined1 *)(param_1 + 0x104) = 4;
    iVar9 = *(int *)(param_1 + 0x970);
    uVar2 = **(undefined1 **)(param_1 + 0x108);
LAB_600635fc:
    iVar9 = FUN_600d1ba0(*(undefined4 *)(iVar9 + 0x20),uVar2,uVar13,2,DAT_600636c8,0x80,DAT_600636c4
                         ,param_1);
    if (iVar9 == 0) {
      return;
    }
    FUN_600d571c(param_1);
    return;
  case 9:
    iVar9 = FUN_600d55fa();
    if (*(int *)(iVar9 + 0x108) != 0) {
      uVar13 = 1;
      goto LAB_60063644;
    }
    break;
  case 10:
    uVar13 = 2;
    goto LAB_60063644;
  case 0xb:
    uVar13 = 3;
    goto LAB_60063644;
  case 0xc:
    uVar13 = 4;
LAB_60063644:
    usb_host_audio__60062b1c(param_1,uVar13);
    return;
  case 0xd:
    if (*(int *)(param_1 + 0x970) != param_1 + 0x110) {
      FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_600636d0,0x476,PTR_s_Mic_volume_600636d4);
      usb_host_audio__60062aa8(param_1 + 0x574);
      goto LAB_60063232;
    }
    FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_600636d0,0x471,PTR_s_Speaker_volume__600636cc);
    usb_host_audio__60062aa8(param_1 + 0x144);
    break;
  case 0xe:
    usb_host_audio__60062f9c(param_1,param_1 + 0x110);
    usb_host_audio__60062f9c(param_1,param_1 + 0x540);
    return;
  case 0xf:
    uVar13 = 0x287;
    puVar15 = PTR_s_Entering_ERROR_state_600636d8;
    goto LAB_600636ae;
  case 0x10:
    uVar13 = 0x116;
    puVar15 = PTR_s_Entering_invalid_state_600636dc;
LAB_600636ae:
    FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_600636d0,uVar13,puVar15);
  default:
    goto switchD_60063196_default;
  }
  uVar13 = 2;
LAB_60063234:
  usb_host_worker__600d56ae(param_1,uVar13);
switchD_60063196_default:
  return;
}


