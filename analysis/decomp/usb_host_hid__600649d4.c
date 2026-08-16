// 600649d4  usb_host_hid__600649d4  size=870 bytes
// src: usb_host_hid.cc
// --- callers ---
// --- callees ---
//   600d1ee0 FUN_600d1ee0
//   60055d78 FUN_60055d78
//   60101832 FUN_60101832
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60055704 FUN_60055704
//   600d6946 FUN_600d6946
//   600d1fb6 FUN_600d1fb6
//   600d1f44 FUN_600d1f44
//   600d68ba FUN_600d68ba
//   6013d268 thunk_EXT_FUN_00006d2c
//   600d68fe FUN_600d68fe
//   600d1f78 FUN_600d1f78
//   600d15c4 private_heap__600835ac
//   6010165c FUN_6010165c
//   600d6956 FUN_600d6956
//   60055e7c FUN_60055e7c
//   60101822 FUN_60101822
//   600d15e4 thunk_EXT_FUN_000080d8
//   600d1f58 FUN_600d1f58
//   60055e28 FUN_60055e28
//   600d1f98 FUN_600d1f98


/* src: usb_host_hid.cc */

void usb_host_hid__600649d4(int param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined *puVar5;
  byte *pbVar6;
  int iVar7;
  undefined *puVar8;
  int local_20;
  undefined4 local_1c;
  
  switch(param_2) {
  case 0:
    DataMemoryBarrier(0x1b);
    *(undefined4 *)(param_1 + 0x114) = 0;
    DataMemoryBarrier(0x1b);
    if (*(int *)(param_1 + 0xf0) != 0) {
      FUN_600d1ee0(*(int *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xf4));
    }
    FUN_600d6956(param_1 + 0x104,0);
    FUN_600d6956(param_1 + 0x108,0);
    local_20 = 0;
    local_1c = 0;
    while (iVar1 = thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0x168),&local_20,0), iVar1 == 1)
    {
      private_heap__600835ac(local_20);
    }
    iVar1 = *(int *)(param_1 + 0x290);
    *(undefined4 *)(param_1 + 0x290) = 0;
    if (iVar1 != 0) {
      thunk_EXT_FUN_000080d8();
    }
    *(undefined2 *)(param_1 + 0x28c) = 0;
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x298) = 0;
    DataMemoryBarrier(0x1b);
    return;
  case 1:
    iVar1 = FUN_60055d78(*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0xf8),0,
                         PTR_LAB_600d693e_1_60064d4c,param_1);
    if (iVar1 == 0) {
      return;
    }
    FUN_6010165c(0x28,PTR_s_usb_host_hid_cc_60064d54,0x1a1,
                 PTR_s_Error_setting_interface_stat_____60064d50,iVar1);
    goto LAB_60064a88;
  case 2:
    puVar5 = PTR_LAB_600d6a3c_1_60064d58;
    if (*(char *)(*(int *)(*(int *)(param_1 + 0xf8) + 0x30) + 7) == '\x01') {
      puVar5 = PTR_LAB_600d693e_1_60064d4c;
    }
    iVar1 = FUN_600d1f78(*(undefined4 *)(param_1 + 0xf4),0,0,puVar5,param_1);
    if (iVar1 == 0) {
      return;
    }
    uVar4 = 0x1b4;
    puVar5 = PTR_s_Error_setting_idle_60064d5c;
    break;
  case 3:
    pbVar6 = *(byte **)(*(int *)(param_1 + 0xf8) + 0x34);
    pbVar3 = pbVar6 + *(ushort *)(*(int *)(param_1 + 0xf8) + 0x38);
    for (; pbVar6 + 9 <= pbVar3; pbVar6 = pbVar6 + *pbVar6) {
      if (pbVar6[1] == 0x21) {
        bVar2 = 0;
        goto LAB_60064ade;
      }
    }
    uVar4 = 0x1cb;
    puVar5 = PTR_s_No_HID_descriptor_found_60064da8;
    break;
  case 4:
    if (*(char *)(*(int *)(*(int *)(param_1 + 0xf8) + 0x30) + 6) == '\x01') {
      iVar1 = FUN_600d1f98(*(undefined4 *)(param_1 + 0xf4),1,PTR_LAB_600d693e_1_60064d4c,param_1);
      if (iVar1 == 0) {
        return;
      }
      uVar4 = 0x204;
      puVar5 = PTR_s_Error_setting_HID_protocol_60064d70;
      break;
    }
LAB_60064b58:
    uVar4 = 1;
    goto LAB_60064b5a;
  case 5:
    uVar4 = FUN_600d1f44(*(undefined4 *)(param_1 + 0xf4),3,1);
    *(undefined4 *)(param_1 + 0x110) = uVar4;
    uVar4 = FUN_600d1f44(*(undefined4 *)(param_1 + 0xf4),3,0);
    DataMemoryBarrier(0x1b);
    *(undefined4 *)(param_1 + 0x114) = uVar4;
    DataMemoryBarrier(0x1b);
    uVar4 = FUN_60055704(*(undefined4 *)(param_1 + 0x110));
    FUN_600d6956(param_1 + 0x104,uVar4);
    if (*(int *)(param_1 + 0x104) == 0) {
      uVar4 = 0x212;
      puVar5 = PTR_s_Unable_to_allocate_DMA_memory_fo_60064d74;
    }
    else {
      if (*(int *)(param_1 + 0x2ac) == 0) {
        FUN_600d68ba(param_1);
        goto LAB_60064b58;
      }
      *(undefined1 *)(param_1 + 0x7c) = 0;
      DataMemoryBarrier(0x1b);
      DataMemoryBarrier(0x1b);
      if (*(uint *)(param_1 + 0x114) < *(uint *)(param_1 + 0x2b0)) {
        uVar4 = 0x220;
        puVar5 = PTR_s_Init_packet_size_greater_than_ma_60064d78;
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x2b0);
        iVar1 = *(int *)(param_1 + 0x2ac);
        local_20 = FUN_60055704(uVar4);
        if ((local_20 != 0) && (iVar1 != 0)) {
          thunk_EXT_FUN_0000b572(local_20,iVar1,uVar4);
        }
        iVar1 = local_20;
        iVar7 = param_1 + 0x108;
        local_20 = 0;
        FUN_600d6956(iVar7,iVar1);
        FUN_600d6946(&local_20);
        puVar5 = PTR_DAT_60064d80;
        iVar1 = *(int *)(param_1 + 0x108);
        if (iVar1 == 0) {
          uVar4 = 0x226;
          puVar5 = PTR_s_Unable_to_allocate_DMA_memory_fo_60064d7c;
        }
        else {
          puVar8 = *(undefined **)(param_1 + 0x2ac);
          *(undefined4 *)(param_1 + 0x2ac) = 0;
          if (puVar8 == puVar5) {
            iVar1 = FUN_600d1fb6(*(undefined4 *)(param_1 + 0xf4),0xf4,3,iVar1,
                                 *(undefined4 *)(param_1 + 0x2b0),PTR_FUN_600d6964_1_60064d84,
                                 param_1);
            if (iVar1 == 0) {
              return;
            }
            FUN_600d6956(iVar7,0);
            uVar4 = 0x23c;
            puVar5 = PTR_s_Error_sending_PS3_init_packet_60064d88;
          }
          else {
            iVar1 = FUN_60055e7c(*(undefined4 *)(param_1 + 0xf4),iVar1,
                                 *(undefined4 *)(param_1 + 0x2b0),PTR_FUN_600d6964_1_60064d84,
                                 param_1);
            if (iVar1 == 0) {
              return;
            }
            FUN_600d6956(iVar7,0);
            uVar4 = 0x247;
            puVar5 = PTR_s_Error_sending_init_packet_60064d8c;
          }
        }
      }
    }
    break;
  case 6:
    iVar1 = FUN_60101822(param_1 + 0x1e4,0);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_60055e28(*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0x104),
                             *(undefined4 *)(param_1 + 0x110),PTR_LAB_60064944_1_60064d90,param_1),
       iVar1 == 0)) {
      iVar1 = FUN_60101822(param_1 + 0x238,0);
      if (iVar1 == 0) {
        return;
      }
      local_20 = 0;
      local_1c = 0;
      iVar1 = thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0x168),&local_20,0);
      if (iVar1 == 1) {
        FUN_600d6956(param_1 + 0x108,local_20);
        *(undefined4 *)(param_1 + 0x10c) = local_1c;
        iVar1 = FUN_60055e7c(*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0x108),
                             local_1c,PTR_LAB_600d69de_1_60064d98,param_1);
        if (iVar1 == 0) {
          return;
        }
        FUN_600d6956(param_1 + 0x108,0);
        FUN_6010165c(0x28,PTR_s_usb_host_hid_cc_60064d54,0x270,PTR_s_Error_sending_output_60064d9c);
      }
      FUN_60101832(param_1 + 0x238);
      return;
    }
    uVar4 = 0x261;
    puVar5 = PTR_s_Error_setting_up_receive_buffers_60064d94;
    break;
  case 7:
    uVar4 = 0x17b;
    puVar5 = PTR_s_Entering_ERROR_state_60064da0;
    goto LAB_60064d34;
  case 8:
    uVar4 = 0xcb;
    puVar5 = PTR_s_Entering_invalid_state_60064da4;
LAB_60064d34:
    FUN_6010165c(0x28,PTR_s_usb_host_hid_cc_60064d54,uVar4,puVar5);
  default:
    goto switchD_600649de_default;
  }
LAB_60064ab6:
  FUN_6010165c(0x28,PTR_s_usb_host_hid_cc_60064d54,uVar4,puVar5);
LAB_60064a88:
  uVar4 = 8;
LAB_60064b5a:
  FUN_600d68fe(param_1,uVar4);
switchD_600649de_default:
  return;
  while (bVar2 = bVar2 + 1, pbVar6[6] != 0x22) {
LAB_60064ade:
    if (pbVar6[5] <= bVar2) goto LAB_60064af8;
  }
  *(undefined2 *)(param_1 + 0x28c) = *(undefined2 *)(pbVar6 + 7);
LAB_60064af8:
  if (*(short *)(param_1 + 0x28c) == 0) {
    uVar4 = 0x1da;
    puVar5 = PTR_s_Unable_to_find_hid_report_descri_60064d60;
  }
  else {
    if (*(int *)(param_1 + 0x294) != 0) goto LAB_60064a88;
    uVar4 = FUN_60055704();
    FUN_600d6956(param_1 + 0x294,uVar4);
    if (*(int *)(param_1 + 0x294) == 0) {
      uVar4 = 0x1e6;
      puVar5 = PTR_s_Unable_to_allocate_DMA_memory_fo_60064d64;
    }
    else {
      iVar1 = FUN_600d1f58(*(undefined4 *)(param_1 + 0xf4),*(int *)(param_1 + 0x294),
                           *(undefined2 *)(param_1 + 0x28c),PTR_FUN_600d6a6e_1_60064d68,param_1);
      if (iVar1 == 0) {
        return;
      }
      uVar4 = 0x1f0;
      puVar5 = PTR_s_Error_getting_hid_report_descrip_60064d6c;
    }
  }
  goto LAB_60064ab6;
}


