// 601016f0  FUN_601016f0  size=80 bytes
// --- callers ---
//   600d3b24 FUN_600d3b24
//   6008099c state_machine__6008099c
//   6005990c sleep_driver__6005990c
//   60077744 FUN_60077744
//   60067e8c flash_memory__60067e8c
//   60101740 FUN_60101740
//   60078340 firmware_image_upload__60078340
//   60068f88 activation_sequence__60068f88
//   6006a21c adapter__6006a21c
//   60078b4c get_device_data__60078b4c
//   6007fcec battery_service__6007fcec
//   60060f28 usb_device__60060f28
//   6005f418 dcp_encryption_engine__6005f418
//   6006044c reset__6006044c
//   60051240 main__60051240
//   6006ae20 gatt_server__6006ae20
//   600834a4 parser__600834a4
//   6005b794 application_state__6005b794
//   60069a38 adapter__60069a38
//   60071580 board__60071580
//   60083080 remote_device_db__60083080
//   60081500 FUN_60081500
//   6006a9c8 gatt_server__6006a9c8
//   6007f454 receiver__6007f454
//   60084644 state_machine__60084644
//   6007ea94 audio_player__6007ea94
//   60058b68 FUN_60058b68
//   60059d54 sleep_lock__60059d54
//   60051b50 stats__60051b50
//   6005d9d0 gatt_server__6005d9d0
//   60075088 audio_states__60075088
//   6007a62c usb_audio_receive__6007a62c
//   60067ddc logging__60067ddc
//   60069b20 adapter__60069b20
//   60079f1c usb_audio_receive__60079f1c
//   600d4902 flash_lut__600d4902
//   6005f450 dcp_encryption_engine__6005f450
//   60074e6c audio_states__60074e6c
//   6006c340 remote_device_db__6006c340
//   600d37b8 FUN_600d37b8
//   600d53ae FUN_600d53ae
//   60058aa8 hid_input_target__60058aa8
//   60080cdc gatt_manager_task__60080cdc
//   60069c58 adapter__60069c58
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6005856c FUN_6005856c
//   600cc090 FUN_600cc090
//   60101b94 FUN_60101b94
//   600cbfa0 FUN_600cbfa0


void FUN_601016f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int local_20;
  undefined4 local_1c;
  
  uVar1 = FUN_6005856c();
  FUN_600cc090(&local_20,uVar1,param_1,param_2,param_3,0);
  if (local_20 != 0) {
    FUN_60101b94(local_20 + 0xc,param_4);
    thunk_EXT_FUN_0000b572(local_20 + 0x1a,*param_4,param_4[2] + 1);
    FUN_600cbfa0(local_1c,local_20);
    return;
  }
  return;
}


