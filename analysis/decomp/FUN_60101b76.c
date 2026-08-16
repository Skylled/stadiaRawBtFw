// 60101b76  FUN_60101b76  size=30 bytes
// --- callers ---
//   60059f00 snvs__60059f00
//   600d37ac FUN_600d37ac
//   6005990c sleep_driver__6005990c
//   60067b50 gotham__60067b50
//   6007ed74 recording_pipeline__6007ed74
//   6006f660 gotham_16mb_mimxrt10xx_mpu__6006f660
//   60074f70 audio_states__60074f70
//   60068f88 activation_sequence__60068f88
//   6006b630 sound_codec_wm8904__6006b630
//   60068f04 activation_sequence__60068f04
//   6005b150 application_state__6005b150
//   6007edb0 recording_pipeline__6007edb0
//   60078efc FUN_60078efc
//   600cb460 key_value_store__600cb460
//   60060f28 usb_device__60060f28
//   600666f0 keys__600666f0
//   6005f418 dcp_encryption_engine__6005f418
//   6006573c haptics__6006573c
//   6005ff5c platform__6005ff5c
//   600d3ae6 FUN_600d3ae6
//   60067a68 gotham__60067a68
//   60061c48 FUN_60061c48
//   60077750 FUN_60077750
//   60058b68 FUN_60058b68
//   60059d54 sleep_lock__60059d54
//   6005fe04 io_pin__6005fe04
//   6005e200 bug_report__6005e200
//   60058600 FUN_60058600
//   60075088 audio_states__60075088
//   60051120 FUN_60051120
//   600d4902 flash_lut__600d4902
//   60075d78 headphone_state_machine__60075d78
//   60074e6c audio_states__60074e6c
//   6006c340 remote_device_db__6006c340
//   60079270 FUN_60079270
//   60060ccc usb_device__60060ccc
//   60065e68 keys__60065e68
//   60058aa8 hid_input_target__60058aa8
//   60058574 system_tasks__60058574
//   60077744 FUN_60077744
//   60067e8c flash_memory__60067e8c
//   60067c3c gotham__60067c3c
//   600cb2fc key_value_store__600cb2fc
//   600cbdf4 buffer__600cbdf4
//   60074c08 FUN_60074c08
//   60078b4c get_device_data__60078b4c
//   6007fcec battery_service__6007fcec
//   600ce2a0 FUN_600ce2a0
//   6006044c reset__6006044c
//   60051240 main__60051240
//   600656a0 haptics__600656a0
//   6006287c usb_host__6006287c
//   600834a4 parser__600834a4
//   60067f5c mimxrt10xx_flash_memory__60067f5c
//   60061684 partition_table__60061684
//   60068024 mimxrt10xx_flash_memory__60068024
//   60079778 http_flash_writer__60079778
//   600db61c FUN_600db61c
//   6007edf4 recording_pipeline__6007edf4
//   60067d14 gotham__60067d14
//   6005b1c0 application_state__6005b1c0
//   60058754 buffer__60058754
//   6005d844 trigger_bug_report__6005d844
//   60065eb8 keys__60065eb8
//   6007ea94 audio_player__6007ea94
//   6007952c http_flash_writer__6007952c
//   60051b50 stats__60051b50
//   60067ddc logging__60067ddc
//   6005e7e0 bug_report__6005e7e0
//   60078be0 FUN_60078be0
//   6005f450 dcp_encryption_engine__6005f450
//   60060bf4 usb_device__60060bf4
//   60080cdc gatt_manager_task__60080cdc
//   60069c58 adapter__60069c58
// --- callees ---
//   6013d258 thunk_EXT_FUN_0000b50a


void FUN_60101b76(int param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0;
      (*(int *)(param_1 + 4) - *(int *)(param_1 + 8) != iVar1 &&
      (*(char *)(param_2 + iVar1) != '\0')); iVar1 = iVar1 + 1) {
  }
  thunk_EXT_FUN_0000b50a();
  return;
}


