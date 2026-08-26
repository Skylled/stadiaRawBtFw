// 601016f0  FUN_601016f0  size=80 bytes
// --- callers ---
//   6005ce58 FUN_6005ce58
//   6008099c state_machine__6008099c
//   600d53ae FUN_600d53ae
//   60051b50 stats__60051b50
//   60101740 FUN_60101740
//   60058aa8 hid_input_target__60058aa8
//   6007ea94 audio_player__6007ea94
//   60058b68 FUN_60058b68
//   60069b20 adapter__60069b20
//   60080cdc gatt_manager_task__60080cdc
//   6007e82c FUN_6007e82c
//   60074e6c audio_states__60074e6c
//   6006044c reset__6006044c
//   6007fcec battery_service__6007fcec
//   6006ae20 gatt_server__6006ae20
//   60071580 board__60071580
//   60051240 main__60051240
//   600d4902 flash_lut__600d4902
//   6005d9d0 gatt_server__6005d9d0
//   6006c340 remote_device_db__6006c340
//   6007f454 receiver__6007f454
//   600d3b24 FUN_600d3b24
//   60083080 remote_device_db__60083080
//   60079f1c usb_audio_receive__60079f1c
//   60081500 FUN_60081500
//   60069a38 adapter__60069a38
//   600925bc FUN_600925bc
//   60067ddc logging__60067ddc
//   600834a4 parser__600834a4
//   60069c58 adapter__60069c58
//   60074910 FUN_60074910
//   60084644 state_machine__60084644
//   6005f450 dcp_encryption_engine__6005f450
//   60059d54 sleep_lock__60059d54
//   6005990c sleep_driver__6005990c
//   60078340 firmware_image_upload__60078340
//   6005f418 dcp_encryption_engine__6005f418
//   60076ba0 FUN_60076ba0
//   600d37b8 FUN_600d37b8
//   60069dd4 FUN_60069dd4
//   6006a9c8 gatt_server__6006a9c8
//   6006a21c adapter__6006a21c
//   600800c0 FUN_600800c0
//   60060f28 usb_device__60060f28
//   60078b4c get_device_data__60078b4c
//   60068f88 activation_sequence__60068f88
//   6005b794 application_state__6005b794
//   60075088 audio_states__60075088
//   6007a62c usb_audio_receive__6007a62c
//   60067e8c flash_memory__60067e8c
// --- callees ---
//   600cc090 FUN_600cc090
//   6005856c FUN_6005856c
//   60101b94 FUN_60101b94
//   6013d3a0 thunk_EXT_FUN_0000b572
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


